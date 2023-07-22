#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Math
{
public:
	template<typename T>
	static T Lerp(T min, T max, float t)
	{
		return min + (max - min) * Clamp<float>(0, 1, t);
	}

	template<typename T>
	static T InverseLerp(T x, T y, float value)
	{
		return (value - x) / (y - x);
	}

	template<typename T>
	static T Clamp(T min, T max, T value)
	{
		if (value > max) return max;
		if (value < min) return min;
		return value;
	}
};

