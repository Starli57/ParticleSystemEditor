#include "Application.h"

void Application::Start()
{
    std::shared_ptr<Time> timer = std::make_shared<Time>();

    Utilities::DI::Register(timer);
    Utilities::DI::Register(std::make_shared<Random>(timer->GetCurrentTime()));

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
}