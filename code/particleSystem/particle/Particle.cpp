
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
	}

	Particle::~Particle() 
	{
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

	bool Particle::GetIsVisible()
	{
		return _lifetime <= _lifetimeLimit;
	}

	float Particle::GetLifetimeAspect()
	{
		return _lifetime / _lifetimeLimit;
	}
}