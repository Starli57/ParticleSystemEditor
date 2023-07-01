#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


#include "../code/utility/di/Di.h"
#include "../code/logging/Logger.h"

namespace ParticleSystemEditor
{
	class LogConsole
	{
	public:
		void Render();
	};
}