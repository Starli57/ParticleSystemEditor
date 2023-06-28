#include "Application.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()

using namespace ParticleSystemEditor;

Application::Application()
{
    std::unique_ptr<GlfwContext> glfwContext = std::make_unique<GlfwContext>();
    std::unique_ptr<ImguiContext> imguiContext = std::make_unique<ImguiContext>(glfwContext->GetWindow(), glfwContext->GetGlslVersion());
    std::unique_ptr<ApplicationContext> appContext = std::make_unique<ApplicationContext>();

    while (!glfwWindowShouldClose(glfwContext->GetWindow()))
    {
        glfwPollEvents();

        appContext->Update();

        imguiContext->Prepare();
        appContext->UpdateImgui();
        imguiContext->Render();

        glfwContext->Prepare();
        appContext->UpdateGlfw();
        glfwContext->Finalize(imguiContext->GetImguiIo()->ConfigFlags);

        std::stringstream msg;
        msg << "Frames: " << (int)(1 / appContext->time->GetDeltaTime());
        MLogger->Log(msg.str());
    }
}