#pragma once

#include <glm/vec4.hpp>

class Math
{
public:
	static float Lerp(float min, float max, float t);
	static int Lerp(int min, int max, float t);
	static glm::vec4 Lerp(glm::vec4 min, glm::vec4 max, float t);
};

