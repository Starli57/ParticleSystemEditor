#include "ParticleSystem.h"

namespace ParticleSystemEditor
{
	ParticleSystem::ParticleSystem()
	{
		int particlesCount = 100;

		//todo: settings should be updatable by editor ui
		ParticleSettings* settings = new ParticleSettings();

		settings->startPosition = glm::vec3(0, 0, -3);
		settings->startPositionSpawnRadius = 0.1f;

		settings->startVelocity = glm::vec3(0, 0.02f, 0);
		settings->startVelocityDifference = 0.01f;

		settings->startLifetime = 1;
		settings->startLifetimeDifference = 0.0f;
		//end settings

		particles = new std::vector<Particle*>();
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