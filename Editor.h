#pragma once
#include <iostream>

#include "Inspector.h"
#include "ParticleSystem.h"
#include "Di.h"

using namespace ParticleSystemEditor;

class Editor
{
public:
	LogConsole* logConsole;
	Inspector* inspector;

	Editor();
	~Editor();
	
	void Update();
	void Render();

};

