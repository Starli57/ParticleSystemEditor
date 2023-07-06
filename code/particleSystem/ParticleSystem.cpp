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

		int particlesLimit = 2500;
		particles = new std::vector<Particle*>();
		particles->reserve(particlesLimit);

		for (int i = 0; i < particlesLimit; i++)
		{
			particles->push_back(new Particle(settings));
		}

		emitter = new ParticlesEmitter(settings, particles);
	}

	ParticleSystem::~ParticleSystem()
	{
		for (Particle* particle : *particles)
		{
			delete particle;
		}
		delete particles;
		delete emitter;
		delete settings;
	}

	void ParticleSystem::Update()
	{
		emitter->Update();
		UpdateParticles();
	}

	void ParticleSystem::Render()
	{
		for (Particle* particle : *particles)
		{
			particle->Render();
		}
	}

	void ParticleSystem::UpdateParticles()
	{
		for (Particle* particle : *particles)
		{
			particle->Update();
		}
	}
}