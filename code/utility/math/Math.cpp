#include "Math.h"

float Math::Lerp(float min, float max, float t)
{
	return min + (max - min) * t;
}

int Math::Lerp(int min, int max, float t)
{
	return min + (max - min) * t;
}

glm::vec4 Math::Lerp(glm::vec4 min, glm::vec4 max, float t)
{
	return min + (max - min) * t;
}