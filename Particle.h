#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "LogConsole.h"

#include "ParticleSettings.h"
#include "Shader.h"
#include "ShadersList.h"

#include "Vertex.h"
#include "Triangle.h"

#include "Random.h"
#include "Time.h"

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

		void Setup();
		void Activate();
		void Deactivate();

		void Update();
		void Render();

		bool GetIsVisible();
		float GetLifetimeAspect();

	private:
		ParticleSettings* _particleSettings;
		Graphics::Shader* _shader;

		glm::vec3 _position;
		glm::vec3 _velocity;
		float _lifetime;
		float _lifetimeLimit;


		void SetupProjectionMatrix();

		void UpdatePosition();
	};
}