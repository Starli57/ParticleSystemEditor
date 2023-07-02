#include "ParticleSystem.h"

namespace ParticleSystemEditor
{
	ParticleSettings* ParticleSystem::GetParticleSettingsPtr() 
	{
		return settings;
	}

	ParticleSystem::ParticleSystem()
	{
		settings = new ParticleSettings();

		settings->emissionPosition = glm::vec3(0, 0, 2);
		settings->emissionRadius = glm::vec3(10, 10, 0);

		settings->direction = glm::vec3(0, 0, -1);
		settings->directionNoise = glm::vec3(1, 0.5f, 0.25f);

		settings->rotationVector = glm::vec3(1, 1, 1);
		settings->minRotation = -2;
		settings->maxRotation =  2;

		settings->minVelocity = 1;
		settings->maxVelocity = 7;
		settings->velocityDamping = 0.0001f;

		settings->startScale = glm::vec3(1, 1, 1);
		settings->endScale = glm::vec3(0, 0, 0);

		settings->minLifetime = 3;
		settings->maxLifetime = 7;

		settings->startColor = glm::vec4(1.0f, 0.5f, 0.2f, 1.0f);
		settings->endColor = glm::vec4(1.0f, 0.88f, 0.2f, 0);

		int particlesCount = 200;
		particles = new std::vector<Particle*>();
		particles->reserve(particlesCount);

		for (int i = 0; i < particlesCount; i++)
		{
			particles->push_back(new Particle(settings));
		}
	}

	ParticleSystem::~ParticleSystem()
	{
		for (Particle* particle : *particles) 
		{
			delete particle;
		}
		delete particles;
		delete settings;
	}

	void ParticleSystem::Update()
	{
		Emit();

		for (Particle* particle : *particles)
		{
			particle->Update();
		}
	}

	void ParticleSystem::Render()
	{
		for (Particle* particle : *particles)
		{
			particle->Render();
		}
	}

	void ParticleSystem::Emit() 
	{
		int count = 1;

		for (Particle* particle : *particles)
		{
			if (particle->GetIsVisible()) continue;

			particle->Setup();
			particle->Activate();
			count--;

			if (count <= 0) return;
		}
	}
}