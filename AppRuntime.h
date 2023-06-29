#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include <stdio.h>

#include "Application.h"
#include "Di.h"
#include "Logger.h"

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#define MLogger Utilities::DI::Get<Logging::Logger>()

class AppRuntime
{
public:
    Application* application;
	GLFWwindow* window;

    AppRuntime();
    ~AppRuntime();

    void Run();

    void Start();
    void Dispose();
    void Update();
    void RenderScene();
    void RenderUi();

protected:

	ImGuiIO* io;
};

