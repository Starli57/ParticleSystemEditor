#pragma once
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>   

#include "EditorUi.h"
#include "ParticleSystem.h"
#include "Di.h"
#include "Logger.h"
#include "Time.h"

using namespace ParticleSystemEditor;
using namespace Logging;

class ApplicationContext
{
public:
	std::shared_ptr<Logger> logger;
	std::shared_ptr<Time> time;

	ApplicationContext();
	~ApplicationContext();

	void Update();
	void Render();

private:
	std::shared_ptr<ParticleSystem> particleSystem;
};

