#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../code/particleSystem/particle/ParticleSettings.h"

namespace ParticleSystemEditor
{
	class Inspector
	{
	public:
		Inspector(ParticleSettings* settings);
		void Render();

	private:
		ParticleSettings* _settings;
	};
}