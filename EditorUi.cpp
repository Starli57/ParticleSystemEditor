
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
        logConsole->Render();
        inspector->Render();

    }
}