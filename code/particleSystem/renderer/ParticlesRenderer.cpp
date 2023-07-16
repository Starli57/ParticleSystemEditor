#include "ParticlesRenderer.h"


namespace ParticleSystemEditor
{
	#define timer  Utilities::DI::Get<Time>()
	#define rand   Utilities::DI::Get<Random>()
	#define screen Utilities::DI::Get<ScreenSettings>()

	using namespace Rendering;
	ParticlesRenderer::ParticlesRenderer(ParticleSettings* settings, std::vector<Particle*>* particles)
	{
		this->settings = settings;
		this->particles = particles;

		shader = new Rendering::Shader(ShadersList::GetDefaultVertexPath(), ShadersList::GetDefaultFragmentPath());
		shader->Use();
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