#pragma once

#include "Scene.h"
#include "../code/editor/Editor.h"
#include "../code/utility/time/Time.h"

class Application
{
public:
    std::unique_ptr<Scene> scene;
    std::unique_ptr<Editor> editor;

    void Start();
    void Dispose();
    void Update();
    void RenderScene();
    void RenderUi();
};