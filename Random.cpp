#include "Random.h"

Random::Random() 
{
}

float Random::Get()
{
	return static_cast<float>(std::rand()) / RAND_MAX;
}

float Random::Get(float min, float max)
{
	return min + (max - min) * Get();
}