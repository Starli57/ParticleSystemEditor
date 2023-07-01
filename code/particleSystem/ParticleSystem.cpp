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

		settings->emissionPosition = glm::vec3(0, -1, -3);
		settings->emissionRadius = 0.1f;

		settings->direction = glm::vec3(0, 0.02f, 0);
		settings->minVelocity = 1;
		settings->maxVelocity = 2;

		settings->minLifetime = 1;
		settings->maxLifetime = 2;

		settings->startColor = glm::vec4(1.0f, 0.5f, 0.2f, 1.0f);
		settings->endColor = glm::vec4(0.5f, 0.2f, 0.275f, 0);

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