#pragma once

#include "../ParticleSettings.h"
#include "../particle/Particle.h"

namespace ParticleSystemEditor
{
	class ParticlesRenderer
	{
	public:
		std::vector<Particle*>* particles;

		ParticlesRenderer(ParticleSettings* settings, std::vector<Particle*>* particles);
		~ParticlesRenderer();

		void Render();

	private:
		ParticleSettings* settings;
	};
}