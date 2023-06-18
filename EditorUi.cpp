
#include "EditorUi.h"
#include "Shader.h"

namespace ParticleSystemEditor
{
    EditorUi::EditorUi() 
    {
        logConsole = new LogConsole();
    }

    EditorUi::~EditorUi() 
    {
        delete(logConsole);
    }

    void EditorUi::Render()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        logConsole->Render();

        ImGui::Render();
    }
}