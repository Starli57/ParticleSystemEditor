#pragma once
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>   

#include "ParticleSystem.h"
#include "Di.h"
#include "Logger.h"

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

