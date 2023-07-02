
#include "Particle.h"


namespace ParticleSystemEditor
{
	#define timer Utilities::DI::Get<Time>()
	#define rand Utilities::DI::Get<Random>()

	Particle::Particle(ParticleSettings* settings)
	{
		_settings = settings;

		Setup();
		Deactivate();

		_shader = new Graphics::Shader(ShadersList::GetDefaultVertexPath(), ShadersList::GetDefaultFragmentPath());
		_shader->Use();

		SetupProjectionMatrix();
	}

	Particle::~Particle() 
	{
		delete _shader;
	}

	void Particle::Activate() 
	{
		_lifetime = 0;
	}
	
	void Particle::Deactivate() 
	{
		_lifetime = _lifetimeLimit + 1;
	}
	
	void Particle::Setup() 
	{
		_position = _settings->emissionPosition + glm::vec3(
			_settings->emissionRadius.x * rand->Get(-1.0f, 1.0f), 
			_settings->emissionRadius.y * rand->Get(-1.0f, 1.0f), 
			_settings->emissionRadius.z * rand->Get(-1.0f, 1.0f));

		float velocityMultiplier = Math::Lerp(_settings->minVelocity, _settings->maxVelocity, rand->Get01());
		glm::vec3 velocityDirection = _settings->direction + glm::vec3(
			_settings->directionNoise.x * rand->Get(-1, 1), 
			_settings->directionNoise.y * rand->Get(-1, 1), 
			_settings->directionNoise.z * rand->Get(-1, 1));

		_velocity = velocityDirection * velocityMultiplier;
		_rotationVelocity = Math::Lerp(_settings->minRotation, _settings->maxRotation, rand->Get01());

		_lifetimeLimit = Math::Lerp(_settings->minLifetime, _settings->maxLifetime, rand->Get01());
	}

	void Particle::Update()
	{
		if (!GetIsVisible())
		{
			return;
		}

		_lifetime += (float)timer->GetDeltaTime();

		UpdateVelocity();
		UpdatePosition();
		UpdateRotation();
	}

	void Particle::UpdatePosition() 
	{
		_position += _velocity * (float)timer->GetDeltaTime();
	}

	void Particle::UpdateVelocity()
	{
		_velocity *= (1 - _settings->velocityDamping);//todo: add DeltaTime
	}

	void Particle::UpdateRotation()
	{
		_rotation += _rotationVelocity * (float)timer->GetDeltaTime();
	}

	void Particle::Render() 
	{
		if (!GetIsVisible())
		{
			return;
		}


		float vertexes[] =
		{
		//   positions
		//   x      y      z
			-0.5f, -0.5f,  0,
			-0.5f,  0.5f,  0,
			 0.5f,  0.5f,  0,
			 0.5f, -0.5f,  0
		};

		uint32_t indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		unsigned int VAO, VBO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// create transformations
		glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		view = glm::translate(view, _position);
		view = glm::rotate(view, _rotation, _settings->rotationVector);
		view = glm::scale(view, Math::Lerp(_settings->startScale, _settings->endScale, GetLifetimeAspect()));
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0, 0, 0));

		glm::vec4 color = Math::Lerp(_settings->startColor, _settings->endColor, GetLifetimeAspect());

		_shader->setMat4("view", view);
		_shader->setMat4("model", model);
		_shader->setVec4("inColor", color);
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void Particle::SetupProjectionMatrix()
	{
		float widthHeightAspect = 1;//todo: calculate real aspect

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(90.0f), widthHeightAspect, 0.1f, 1000.0f);
		_shader->setMat4("projection", projection);
	}

	bool Particle::GetIsVisible()
	{
		return _lifetime <= _lifetimeLimit;
	}

	float Particle::GetLifetimeAspect()
	{
		return _lifetime / _lifetimeLimit;
	}
}