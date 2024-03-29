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

		particles = new std::vector<Particle*>();
		particles->reserve(maxParticles);

		for (int i = 0; i < maxParticles; i++)
		{
			particles->push_back(new Particle(settings));
		}

		emitter = new ParticlesEmitter(settings, particles);
		renderer = new ParticlesRenderer(settings, particles);
	}

	ParticleSystem::~ParticleSystem()
	{
		delete renderer;
		delete emitter;
		for (Particle* particle : *particles)
		{
			delete particle;
		}
		delete particles;
		delete settings;
	}

	void ParticleSystem::Update()
	{
		emitter->Update();
		UpdateParticles();
	}

	void ParticleSystem::Render()
	{
		renderer->Render();
	}

	void ParticleSystem::UpdateParticles()
	{
		for (Particle* particle : *particles)
		{
			particle->Update();
		}
	}
}