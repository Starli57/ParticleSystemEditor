#include "../code/particleSystem/ParticleSettings.h"

ParticleSettings::ParticleSettings() 
{
	emissionPosition = glm::vec3(0, 0, -250);
	emissionRadius = glm::vec3(0, 0, 0);
	particlesPerEmission = 500;
	emissionPeriod = 1;

	direction = glm::vec3(0, 0, 5);
	directionNoise = glm::vec3(1, 1, 2);

	rotationVector = glm::vec3(1, 1, 1);
	minRotation = -2;
	maxRotation = 2;

	minVelocity = 10;
	maxVelocity = 30;
	velocityDamping = 0.01f;

	startScale = glm::vec3(1, 1, 1);
	endScale = glm::vec3(0, 0, 0);

	minLifetime = 3;
	maxLifetime = 7;

	startColor = glm::vec4(1.0f, 0.5f, 0.2f, 1.0f);
	endColor = glm::vec4(0.48f, 0.0f, 1, 0);
}