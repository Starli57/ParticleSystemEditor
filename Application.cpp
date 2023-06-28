#include "Application.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()

using namespace ParticleSystemEditor;

Application::Application()
{
    std::unique_ptr<GlfwContext> glfwContext = std::make_unique<GlfwContext>();
    std::unique_ptr<ImguiContext> imguiContext = std::make_unique<ImguiContext>(glfwContext->GetWindow(), glfwContext->GetGlslVersion());
    std::unique_ptr<ApplicationContext> appContext = std::make_unique<ApplicationContext>();
    EditorContext* editorContext = new EditorContext();

    while (!glfwWindowShouldClose(glfwContext->GetWindow()))
    {
        glfwPollEvents();

        appContext->Update();
        editorContext->Update();

        imguiContext->Prepare();
        editorContext->Render();
        imguiContext->Render();

        glfwContext->Prepare();
        appContext->Render();
        glfwContext->Finalize(imguiContext->GetImguiIo()->ConfigFlags);

        std::stringstream msg;
        msg << "Frames: " << (int)(1 / appContext->time->GetDeltaTime());
        MLogger->Log(msg.str());
    }

    delete(editorContext);
}