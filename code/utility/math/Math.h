#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Math
{
public:
	template<typename T>
	static T Lerp(T min, T max, float t)
	{
		return min + (max - min) * t;
	}
};

