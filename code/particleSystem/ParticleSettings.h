#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

const int maxParticles = 1000;

struct ParticleSettings
{
	ParticleSettings();

	glm::vec4 startColor;
	glm::vec4 endColor;

	glm::vec3 emissionPosition;
	glm::vec3 emissionRadius;

	int particlesPerEmission;
	float emissionPeriod;

	glm::vec3 direction;
	glm::vec3 directionNoise;

	float minVelocity;
	float maxVelocity;
	float velocityDamping;

	glm::vec3 rotationVector;
	float minRotation;
	float maxRotation;

	glm::vec3 startScale;
	glm::vec3 endScale;

	float minLifetime;
	float maxLifetime;

};

