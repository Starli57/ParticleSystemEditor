#pragma once

#include "AppRuntime.h"
#define MLogger Utilities::DI::Get<Logging::Logger>()
#define Screen Utilities::DI::Get<ScreenSettings>()

void OnGLFWError(int error, const char* description)
{
    MLogger->Log("GLFW Error description: " + std::string(description));
}

void OnWindowResized(GLFWwindow* window, int width, int height)
{
    Screen->SetScreenHeight(height);
    Screen->SetScreenWidth(width);
}

AppRuntime::AppRuntime()
{
    application = new Application();

    glfwSetErrorCallback(OnGLFWError);
    glfwInit();

    std::string glslVersion = "";
#if defined(__APPLE__)
    // GL 3.2 + GLSL 150
    glslVersion = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    glslVersion = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif
    glfwWindowHint(GLFW_SAMPLES, 4);

    std::shared_ptr <ScreenSettings> screenSettings = std::make_shared<ScreenSettings>();
    Utilities::DI::Register(screenSettings);

    window = glfwCreateWindow(
        screenSettings->GetScreenWidth(), screenSettings->GetScreenHeight(),
        "Particle System", nullptr, nullptr);

    glfwSetWindowSizeCallback(window, OnWindowResized);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    gladLoadGL();

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO(); (void)io;
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    io->ConfigViewportsNoAutoMerge = true;

    ImguiStyles().SetupEditorStyle();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion.c_str());

    Start();
    Run();
}

AppRuntime::~AppRuntime()
{
    Dispose();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    delete application;
}

void AppRuntime::Run()
{
    ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.15f, 1.00f);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        Update();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();
        RenderUi();
        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        RenderScene();

        if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);
    }
}

void AppRuntime::Start()
{
    application->Start();
}

void AppRuntime::Dispose()
{
    application->Dispose();
}

void AppRuntime::Update()
{
    application->Update();
}

void AppRuntime::RenderScene()
{
    application->RenderScene();
}

void AppRuntime::RenderUi()
{
    application->RenderUi();
}