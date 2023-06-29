#include "Application.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()

void Application::Start()
{
    scene = std::make_unique<Scene>();
    editor = std::make_unique<Editor>();
}

void Application::Dispose()
{

}

void Application::Update()
{
    scene->Update();
    editor->Update();
}

void Application::RenderScene()
{
    scene->Render();
}

void Application::RenderUi()
{
    editor->Render();

    std::stringstream msg;
    msg << "Frames: " << (int)(1 / scene->time->GetDeltaTime());
    MLogger->Log(msg.str());
}