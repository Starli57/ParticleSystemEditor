#ifndef LOG_CONSOLE_H
#define LOG_CONSOLE_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Shader.h"

namespace ParticleSystemEditor
{
	class LogConsole
	{
	public:
		void Render();
	};
}
#endif