#include "Application.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()

using namespace ParticleSystemEditor;

Application::Application()
{
    std::unique_ptr<SceneContext> sceneContext = std::make_unique<SceneContext>();
    std::unique_ptr<UiContext> uiContext = std::make_unique<UiContext>();

    sceneContext->Initialize();
    uiContext->Initialize();

    std::shared_ptr<Logging::Logger> logger = std::make_shared<Logging::Logger>();
    Utilities::DI::Register(logger);

    std::shared_ptr<Time> time = std::make_shared<Time>();
    Utilities::DI::Register(time);

    std::unique_ptr<ParticleSystem> particleSystem = std::make_unique<ParticleSystem>();
    std::unique_ptr <EditorUi> editorUi = std::make_unique<EditorUi>(particleSystem->GetParticleSettingsPtr());

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(sceneContext->GetWindow(), true);
    ImGui_ImplOpenGL3_Init(sceneContext->GetGlslVersion().c_str());

    ImVec4 clear_color = ImVec4(0.075f, 0.15f, 0.2f, 1.00f);
    while (!glfwWindowShouldClose(sceneContext->GetWindow()))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        time->Update();
        particleSystem->Update();

        ImGui::NewFrame();

        editorUi->Render();

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(sceneContext->GetWindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        particleSystem->Render();

        if (uiContext->GetImguiIo()->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(sceneContext->GetWindow());

        std::stringstream msg;
        msg << "Frames: " << (int)(1/time->GetDeltaTime());
        MLogger->Log(msg.str());
    }

    uiContext->Finalize();
    sceneContext->Finalize();
}