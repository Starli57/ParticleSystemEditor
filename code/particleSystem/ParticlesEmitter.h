#pragma once

#include "../particleSystem/particle/ParticleSettings.h"
#include "../particleSystem/particle/Particle.h"

namespace ParticleSystemEditor
{
	class ParticlesEmitter
	{
	public:
		std::vector<Particle*>* particles;

		ParticlesEmitter(ParticleSettings* settings, std::vector<Particle*>* particles);
		~ParticlesEmitter();

		void Update();

	private:
		ParticleSettings* settings; 

		double nextEmissionTime;
		int lastSpawnIndex;

		void EmitParticles();
	};
}