#include "ParticleSystem.h"

namespace ParticleSystemEditor
{
	ParticleSystem::ParticleSystem()
	{
		particles = new std::vector<Particle*>();
		particles->push_back(new Particle(glm::vec3(-1, 0, -3)));
		particles->push_back(new Particle(glm::vec3( 1, 0, -3)));
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