#include "ParticleSystem.h"

namespace ParticleSystemEditor
{
	ParticleSystem::ParticleSystem()
	{
		particles = new std::vector<Particle*>();
		particles->push_back(new Particle());
	}

	ParticleSystem::~ParticleSystem()
	{
		for (Particle* particle : *particles) 
		{
			delete particle;
		}
		delete particles;
	}

	void ParticleSystem::Render()
	{
		for (Particle* particle : *particles)
		{
			particle->Render();
		}
	}
}