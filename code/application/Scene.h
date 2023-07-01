#pragma once
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>   

#include "../code/particleSystem/ParticleSystem.h"
#include "../code/utility/di/Di.h"
#include "../code/windows/console/LogConsole.h"
#include "../code/utility/time/Time.h"

using namespace ParticleSystemEditor;
using namespace Logging;

class Scene
{
public:
	std::shared_ptr<Logger> logger;

	Scene();
	~Scene();

	void Update();
	void Render();

private:
	std::shared_ptr<ParticleSystem> particleSystem;
};

