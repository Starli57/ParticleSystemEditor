#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

struct ParticleSettings
{
	glm::vec4 startColor;
	glm::vec4 endColor;

	glm::vec3 emissionPosition;
	float emissionRadius;

	glm::vec3 direction;
	float minVelocity;
	float maxVelocity;

	float minLifetime;
	float maxLifetime;
};

