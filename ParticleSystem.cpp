#include "ParticleSystem.h"

namespace ParticleSystemEditor
{
	ParticleSystem::ParticleSystem()
	{
		//todo: settings should be updatable by editor ui
		ParticleSettings* settings = new ParticleSettings();

		settings->startPosition = glm::vec3(0, 0, -3);
		settings->startPositionSpawnRadius = 1;

		settings->startVelocity = glm::vec3(0, 0.02f, 0);
		settings->startVelocityDifference = 0.01f;

		settings->startLifetime = 1;
		settings->startLifetimeDifference = 1;
		//end settings

		particles = new std::vector<Particle*>();
		particles->push_back(new Particle(settings));
		particles->push_back(new Particle(settings));
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
}