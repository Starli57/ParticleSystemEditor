#ifndef EDITOR_UI_H
#define EDITOR_UI_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "log_console.h"

namespace CardsEditor
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
#endif