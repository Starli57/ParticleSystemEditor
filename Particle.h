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

		Particle();
		Particle(const glm::vec3 startPosition);
		~Particle();

		void Update();
		void Render();

	private:
		glm::vec3* _position;
		glm::vec3* _velocity;
		float _lifetime;

		void SetupProjectionMatrix();

		void UpdatePosition();
	};
}