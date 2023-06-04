
#include "editor_ui.h"
#include "shader.h"

namespace CardsEditor
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
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            
            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;

            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGuiIO& io = ImGui::GetIO();
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

            ImGui::End();
        }

        logConsole->Render();

        ImGui::Render();
    }
}