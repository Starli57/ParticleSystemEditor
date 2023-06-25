
#include "EditorUi.h"
#include "Shader.h"

namespace ParticleSystemEditor
{
    EditorUi::EditorUi(ParticleSettings* settings)
    {
        logConsole = new LogConsole();
        inspector = new Inspector(settings);
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
        inspector->Render();

        ImGui::Render();
    }
}