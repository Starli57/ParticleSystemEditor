#include "../code/particleSystem/ParticleSettings.h"

ParticleSettings::ParticleSettings() 
{
	//environment
	nearHideDistanceMin = 5;
	nearHideDistance = 25;
	farHideDistance = 100;
	farHideDistanceMax = 125;

	//emission
	emissionPosition = glm::vec3(0, 0, -200);
	emissionRadius = glm::vec3(50, 50, 0);

	particlesPerEmission = 50;
	emissionPeriod = 0.1f;

	minLifetime = 3;
	maxLifetime = 10;

	//movement
	direction = glm::vec3(0, 0, 4);
	directionNoise = glm::vec3(1, 1, 1);

	rotationVector = glm::vec3(1, 1, 1);
	minRotation = -2;
	maxRotation = 2;

	minVelocity = 10;
	maxVelocity = 30;
	velocityDamping = 0.01f;

	//visual
	startScale = glm::vec3(1, 1, 1);
	endScale = glm::vec3(0, 0, 0);

	startColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	endColor = glm::vec4(0.48f, 0.0f, 1, 0);
}