#include "../code/particleSystem/ParticleSettings.h"

ParticleSettings::ParticleSettings() 
{
	emissionPosition = glm::vec3(0, 0, -3);
	emissionRadius = glm::vec3(0, 0, 0);
	particlesPerEmission = 100;
	emissionPeriod = 0.01f;

	direction = glm::vec3(0, 0, -1);
	directionNoise = glm::vec3(1, 0.4f, 0.25f);

	rotationVector = glm::vec3(1, 1, 1);
	minRotation = -2;
	maxRotation = 2;

	minVelocity = 1;
	maxVelocity = 7;
	velocityDamping = 0.0001f;

	startScale = glm::vec3(1, 1, 1);
	endScale = glm::vec3(0, 0, 0);

	minLifetime = 0.2f;
	maxLifetime = 0.2f;

	startColor = glm::vec4(1.0f, 0.5f, 0.2f, 1.0f);
	endColor = glm::vec4(0.48f, 0.0f, 1, 0);
}