#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "../code/particleSystem/ParticleSettings.h"
#include "../code/rendering/shaders/Shader.h"
#include "../code/rendering/Vertex.h"
#include "../shaders/ShadersList.h"

#include "../code/utility/random/Random.h"
#include "../code/utility/time/Time.h"
#include "../code/utility/math/Math.h"
#include "../../settings/ScreenSettings.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ParticleSystemEditor
{
	class Particle
	{
	public:
		glm::vec3 GetPosition() { return _position; }
		float GetRotation() { return _rotation; }

		float GetLifetimeAspect();
		bool GetIsVisible();

		Particle(ParticleSettings* particleSettings);
		~Particle();

		void Setup();
		void Activate();
		void Deactivate();

		void Update();
		void Render();


	private:

		ParticleSettings* _settings;
		Rendering::Shader* _shader;

		glm::vec3 _position;
		glm::vec3 _velocity;
		
		float _rotation;
		float _rotationVelocity;

		float _lifetime;
		float _lifetimeLimit;


		void SetupProjectionMatrix();

		void UpdatePosition();
		void UpdateVelocity();
		
		void UpdateRotation();
	};
}