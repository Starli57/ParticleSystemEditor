#include "Application.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()

using namespace ParticleSystemEditor;

Application::Application()
{
    std::unique_ptr<SceneContext> sceneContext = std::make_unique<SceneContext>();
    std::unique_ptr<UiContext> uiContext = std::make_unique<UiContext>();

    std::shared_ptr<Logging::Logger> logger = std::make_shared<Logging::Logger>();
    Utilities::DI::Register(logger);

    std::shared_ptr<Time> time = std::make_shared<Time>();
    Utilities::DI::Register(time);

    std::unique_ptr<ParticleSystem> particleSystem = std::make_unique<ParticleSystem>();
    std::unique_ptr <EditorUi> editorUi = std::make_unique<EditorUi>(particleSystem->GetParticleSettingsPtr());

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(sceneContext->GetWindow(), true);
    ImGui_ImplOpenGL3_Init(sceneContext->GetGlslVersion().c_str());

    while (!glfwWindowShouldClose(sceneContext->GetWindow()))
    {
        glfwPollEvents();

        time->Update();
        particleSystem->Update();

        uiContext->Prepare();
        editorUi->Render();
        uiContext->Render();

        sceneContext->Prepare();
        particleSystem->Render();
        sceneContext->Finalize();

        if (uiContext->GetImguiIo()->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        std::stringstream msg;
        msg << "Frames: " << (int)(1/time->GetDeltaTime());
        MLogger->Log(msg.str());
    }
}