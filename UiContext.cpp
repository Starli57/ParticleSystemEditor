
#include "UiContext.h"

UiContext::UiContext()
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
}

UiContext::~UiContext()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UiContext::Prepare()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();
}

void UiContext::Render()
{
    ImGui::Render();
}

ImGuiIO* UiContext::GetImguiIo()
{
    return _io;
}