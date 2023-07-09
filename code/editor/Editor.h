#pragma once
#include <iostream>

#include "windows/inspector/Inspector.h"
#include "windows/console/LogConsole.h"
#include "windows/StatusDisplay/StatusDisplay.h"
#include "../code/particleSystem/ParticleSystem.h"
#include "../code/utility/di/Di.h"

using namespace ParticleSystemEditor;

class Editor
{
public:
	LogConsole* logConsole;
	StatusDisplay* statusDisplay;
	Inspector* inspector;

	Editor();
	~Editor();
	
	void Update();
	void Render();

};

