#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "LogConsole.h"

#include "ParticleSystem.h"
#include "ParticleSettings.h"
#include "Shader.h"
#include "ShadersList.h"

#include "Vertex.h"
#include "Triangle.h"

#include "Random.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ParticleSystemEditor
{
	class Particle
	{
	public:

		Particle(ParticleSettings* particleSettings);
		~Particle();

		void SetupSettings(ParticleSettings* particleSettings);

		void Update();
		void Render();

	private:
		ParticleSettings* _particleSettings;
		Graphics::Shader* _shader;

		glm::vec3 _position;
		glm::vec3 _velocity;
		float _lifetime;

		bool GetIsVisible();

		void SetupProjectionMatrix();

		void UpdatePosition();
	};
}