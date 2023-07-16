#include "ParticlesRenderer.h"


namespace ParticleSystemEditor
{
	ParticlesRenderer::ParticlesRenderer(ParticleSettings* settings, std::vector<Particle*>* particles)
	{
		this->settings = settings;
		this->particles = particles;
	}

	ParticlesRenderer::~ParticlesRenderer()
	{

	}

	void ParticlesRenderer::Render()
	{
		for (Particle* particle : *particles)
		{
			particle->Render();
		}
	}
}