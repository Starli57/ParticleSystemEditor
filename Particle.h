#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "LogConsole.h"

#include "ParticleSystem.h"
#include "Shader.h"
#include "ShadersList.h"

#include "Vertex.h"
#include "Triangle.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ParticleSystemEditor
{
	class Particle
	{
	public:
		Graphics::Shader* shader;

		glm::vec3* position;

		Particle();
		Particle(const glm::vec3 startPosition);
		~Particle();

		void Render();
	};
}