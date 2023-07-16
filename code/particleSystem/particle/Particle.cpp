
#include "Particle.h"


namespace ParticleSystemEditor
{
	#define timer Utilities::DI::Get<Time>()
	#define rand Utilities::DI::Get<Random>()
	#define screen Utilities::DI::Get<ScreenSettings>()

	Particle::Particle(ParticleSettings* settings)
	{
		_settings = settings;

		Setup();
		Deactivate();

		_shader = new Rendering::Shader(ShadersList::GetDefaultVertexPath(), ShadersList::GetDefaultFragmentPath());
		_shader->Use();
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

	void SetupPosition(glm::vec3& position, ParticleSettings* settings)
	{
		position = settings->emissionPosition + glm::vec3(
			settings->emissionRadius.x * rand->Get(-1.0f, 1.0f),
			settings->emissionRadius.y * rand->Get(-1.0f, 1.0f),
			settings->emissionRadius.z * rand->Get(-1.0f, 1.0f));
	}

	void SetupVelocity(glm::vec3& velocity, ParticleSettings* settings)
	{
		float velocityMultiplier = Math::Lerp(settings->minVelocity, settings->maxVelocity, rand->Get01());
		glm::vec3 velocityDirection = settings->direction + glm::vec3(
			settings->directionNoise.x * rand->Get(-1, 1),
			settings->directionNoise.y * rand->Get(-1, 1),
			settings->directionNoise.z * rand->Get(-1, 1));

		velocity = velocityDirection * velocityMultiplier;
	}

	void Particle::Setup() 
	{
		SetupPosition(_position, _settings);
		SetupVelocity(_velocity, _settings);
		
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

		const int squads = 1;

		Rendering::Vertex vertexes[squads * 4];
		uint32_t indices[squads * 6];

		for (int i = 0; i < squads; i++)
		{
			int vi = i * 4;
			vertexes[vi].position = glm::vec3(-0.5f, -0.5f, 0);
			vertexes[vi + 1].position = glm::vec3(-0.5f, 0.5f, 0);
			vertexes[vi + 2].position = glm::vec3(0.5f, 0.5f, 0);
			vertexes[vi + 3].position = glm::vec3(0.5f, -0.5f, 0);

			int ii = i * 6;
			indices[ii] = vi;
			indices[ii + 1] = vi + 1;
			indices[ii + 2] = vi + 2;
			indices[ii + 3] = vi + 2;
			indices[ii + 4] = vi + 3;
			indices[ii + 5] = vi;
		}

		unsigned int vao, vbo, ibo;
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ibo);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//data layout
		//1st -> index
		//2nd -> number of components (coordinates, like x y z w)
		//5th -> stride[bytes]: offset between vertexes (if 1 vertex has 3 elements - offset must be 3 * sizeof(type)) 
		//6th -> offset[bytes] to the initial element (if vertex has position and colors and you need to take colors)
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		SetupProjectionMatrix();
		glm::mat4 view = glm::mat4(1.0f); 
		view = glm::translate(view, _position);
		view = glm::rotate(view, _rotation, _settings->rotationVector);
		view = glm::scale(view, Math::Lerp(_settings->startScale, _settings->endScale, GetLifetimeAspect()));
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0, 0, 0));

		glm::vec4 color = Math::Lerp(_settings->startColor, _settings->endColor, GetLifetimeAspect());

		_shader->setMat4("view", view);
		_shader->setMat4("model", model);
		_shader->setVec4("inColor", color);

		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);
	}

	void Particle::SetupProjectionMatrix()
	{
		float screenAspect = screen->GetScreenAspect();

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(90.0f), screenAspect, 0.1f, 1000.0f);
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