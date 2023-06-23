#pragma once

#include <iostream>
#include <random>

class Random
{
public:
	Random();

	//return value from 0 to 1
	float Get();
	float Get(float min, float max);
};

