#include "Application.h"

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
}