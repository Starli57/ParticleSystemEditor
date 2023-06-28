#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <string>

class ImguiContext
{
public:
	ImguiContext(GLFWwindow* window, std::string glslVersion);
	~ImguiContext();
	void Prepare();
	void Render();

	ImGuiIO* GetImguiIo();

private:
	ImGuiIO* _io;
};

