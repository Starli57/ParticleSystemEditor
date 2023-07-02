#pragma once
#include <iostream>

#include "../code/particleSystem/ParticleSystem.h"
#include "../code/windows/inspector/Inspector.h"
#include "../code/windows/console/LogConsole.h"
#include "../code/windows/StatusDisplay/StatusDisplay.h"
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

