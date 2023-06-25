#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

struct ParticleSettings
{
	glm::vec4 startColor;
	glm::vec4 endColor;

	glm::vec3 startPosition;
	float startPositionSpawnRadius;

	glm::vec3 startVelocity;
	float startVelocityDifference;

	float startLifetime;
	float startLifetimeDifference;
};

