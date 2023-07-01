#pragma once

#include <iostream>

class Random
{
public:
	Random();
	Random(uint32_t defaultSeed);

	uint32_t Get();
	float Get01();
	float Get(float min, float max);

private:
	uint32_t seed = 0;

	uint32_t WangHash();
};

