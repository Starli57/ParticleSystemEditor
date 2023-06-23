#pragma once

#include <GLFW/glfw3.h> 

class Time
{
public:
	double GetCurrentTime();
	double GetDeltaTime();

	void Update();

private:
	double _currentTime;
	double _deltaTime;
	double _previousTime;
};

