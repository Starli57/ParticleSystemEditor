#pragma once
#include <iostream>

#include "EditorUi.h"
#include "ParticleSystem.h"
#include "Di.h"

using namespace ParticleSystemEditor;

class Editor
{
public:
	Editor();
	~Editor();
	
	void Update();
	void Render();

private:
	std::unique_ptr<EditorUi> editorUi;
};

