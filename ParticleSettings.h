#pragma once
#include <glm/vec3.hpp>

struct ParticleSettings
{
	glm::vec3 startPosition;
	float startPositionSpawnRadius;

	glm::vec3 startVelocity;
	float startVelocityDifference;

	float startLifetime;
	float startLifetimeDifference;
};

