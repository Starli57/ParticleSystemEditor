
#include "ImguiContext.h"

ImguiContext::ImguiContext(GLFWwindow* window, std::string glslVersion)
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    _io = &ImGui::GetIO(); (void)_io;
    _io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    _io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    _io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    _io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    _io->ConfigViewportsNoAutoMerge = true;

    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion.c_str());
}

ImguiContext::~ImguiContext()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImguiContext::Prepare()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();
}

void ImguiContext::Render()
{
    ImGui::Render();
}

ImGuiIO* ImguiContext::GetImguiIo()
{
    return _io;
}