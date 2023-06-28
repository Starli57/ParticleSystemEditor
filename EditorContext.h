#pragma once
#include <iostream>

#include "EditorUi.h"
#include "ParticleSystem.h"
#include "Di.h"

using namespace ParticleSystemEditor;

class EditorContext
{
public:
	EditorContext();
	~EditorContext();
	
	void Update();
	void Render();

private:
	std::unique_ptr<EditorUi> editorUi;
};

