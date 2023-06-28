#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class UiContext
{
public:
	UiContext();
	~UiContext();
	void Prepare();
	void Render();

	ImGuiIO* GetImguiIo();

private:
	ImGuiIO* _io;
};

