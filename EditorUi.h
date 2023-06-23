#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "LogConsole.h"

namespace ParticleSystemEditor
{
	class EditorUi
	{
	public:
		
		LogConsole *logConsole;

		EditorUi();
		~EditorUi();

		void Render();
	};
}