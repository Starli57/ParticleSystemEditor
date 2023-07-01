#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Math
{
public:
	static float Lerp(float min, float max, float t);
	static int Lerp(int min, int max, float t);
	static glm::vec3 Lerp(glm::vec3 min, glm::vec3 max, float t);
	static glm::vec4 Lerp(glm::vec4 min, glm::vec4 max, float t);
};

