
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>   

#include "EditorUi.h"
#include "ParticleSystem.h"
#include "Di.h"
#include "Logger.h"
#include "Time.h"

#include <GLFW/glfw3.h> 

#define MLogger Utilities::DI::Get<Logging::Logger>()

void glfw_error_callback(int error, const char* description)
{
    MLogger->Log("GLFW Error description: " + std::string(description));
}

int WinMain()
{
    std::shared_ptr<Logging::Logger> logger = std::make_shared<Logging::Logger>();
    Utilities::DI::Register(logger);

    std::shared_ptr<Time> time = std::make_shared<Time>();
    Utilities::DI::Register(time);

    glfwSetErrorCallback(glfw_error_callback);
    int initialized = glfwInit();

    if (!initialized)
    {
        return 1;
    }

#if defined(__APPLE__)
// GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
// GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    GLFWwindow* window = glfwCreateWindow(800, 800, "Cards editor", nullptr, nullptr);
    if (window == nullptr)
    {
        glfwTerminate();
        return 1;
    }
    
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);

    std::unique_ptr<ParticleSystemEditor::ParticleSystem> particleSystem = std::make_unique<ParticleSystemEditor::ParticleSystem>();
    ParticleSystemEditor::EditorUi* editorUi = new ParticleSystemEditor::EditorUi(particleSystem->GetParticleSettingsPtr());

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    io.ConfigViewportsNoAutoMerge = true;

    //io.ConfigViewportsNoTaskBarIcon = true;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    ImVec4 clear_color = ImVec4(0.075f, 0.15f, 0.2f, 1.00f);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        time->Update();
        particleSystem->Update();

        editorUi->Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        particleSystem->Render();

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);

        std::stringstream msg;
        msg << "Frame: " << (time->GetDeltaTime());
        MLogger->Log(msg.str());
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    delete editorUi;

    return 0;
}