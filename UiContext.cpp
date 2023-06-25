
#include "UiContext.h"

void UiContext::Initialize()
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

    ImGuiStyle& style = ImGui::GetStyle();

}

void UiContext::Finalize()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UiContext::Update()
{
}

void UiContext::BeforeRender()
{
}

void UiContext::Render()
{
}

void UiContext::AfterRender()
{
}

void UiContext::BeforeUpdate()
{
}

void UiContext::AfterUpdate()
{
}

ImGuiIO* UiContext::GetImguiIo()
{
    return _io;
}