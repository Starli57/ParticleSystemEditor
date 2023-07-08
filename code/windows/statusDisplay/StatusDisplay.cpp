#include "StatusDisplay.h"

namespace ParticleSystemEditor
{
    void StatusDisplay::Render()
    {
        ImGui::Begin("Status Display");

        ImGuiIO io = ImGui::GetIO();
        ImGui::Text("FPS: %.1f", io.Framerate);

        ImGui::End();
    }
}