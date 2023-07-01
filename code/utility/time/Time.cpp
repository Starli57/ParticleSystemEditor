#include "Time.h"

double Time::GetCurrentTime() 
{
    return _currentTime;
}

double Time::GetDeltaTime()
{
    return _deltaTime;
}

void Time::Update()
{
    _currentTime = glfwGetTime();
    _deltaTime = _currentTime - _previousTime;
    _previousTime = _currentTime;
}