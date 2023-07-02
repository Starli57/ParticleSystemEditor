#include "StatusDisplay.h"

void StatusDisplay::Render()
{
    ImGui::Begin("Status Display");

    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    
    ImGui::End();
}