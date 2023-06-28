#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>   

#include "GlfwContext.h"
#include "ImguiContext.h"
#include "ApplicationContext.h"

#include "EditorUi.h"
#include "ParticleSystem.h"
#include "Di.h"
#include "Logger.h"
#include "Time.h"

#include <GLFW/glfw3.h> 


class Application
{
public:
	Application();
};

