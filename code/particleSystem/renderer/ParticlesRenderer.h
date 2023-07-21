#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "../ParticleSettings.h"
#include "../particle/Particle.h"

#include "../../settings/ScreenSettings.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
		Rendering::Shader* shader;

		Rendering::Vertex* vertexes;
		uint32_t* indices;

		unsigned int vao, vbo, ibo;
	};
}