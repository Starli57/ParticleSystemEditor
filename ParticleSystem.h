#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "LogConsole.h"

#include "ParticleSystem.h"

#include "Shader.h"
#include "ShadersList.h"

#include "Vertex.h"
#include "Triangle.h"
#include "Particle.h"

namespace ParticleSystemEditor
{
	class Particle;

	class ParticleSystem 
	{
	public:
		std::vector<Particle*>* particles;

		ParticleSystem();
		~ParticleSystem();

		void Update();
		void Render();
	};
}