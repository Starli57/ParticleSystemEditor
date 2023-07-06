#include "ParticlesEmitter.h"

namespace ParticleSystemEditor
{
	#define timer Utilities::DI::Get<Time>()

	ParticlesEmitter::ParticlesEmitter(ParticleSettings* settings, std::vector<Particle*>* particles)
	{
		this->settings = settings;
		this->particles = particles;

		nextEmissionTime = 0;
		lastSpawnIndex = 0;
	}

	ParticlesEmitter::~ParticlesEmitter()
	{
	}

	void ParticlesEmitter::Update()
	{
		double currentTime = timer->GetCurrentTime();
		if (currentTime > nextEmissionTime)
		{
			EmitParticles();

			double emissionTimeDebt = currentTime - nextEmissionTime;
			nextEmissionTime = currentTime + settings->emissionPeriod - emissionTimeDebt;
		}
	}

	void ParticlesEmitter::EmitParticles()
	{
		int spawnTarget = settings->particlesPerEmission;
		size_t particlesCount = particles->size();
		for (int i = 0; i < particlesCount && spawnTarget > 0; i++)
		{
			int particleIndex = (lastSpawnIndex + 1) % particlesCount;
			Particle* particle = particles->at(particleIndex);

			if (!particle->GetIsVisible())
			{
				particle->Setup();
				particle->Activate();

				spawnTarget--;
				lastSpawnIndex = particleIndex;
			}
		}
	}
}