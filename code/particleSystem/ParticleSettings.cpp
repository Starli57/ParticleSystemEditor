#include "../code/particleSystem/ParticleSettings.h"

ParticleSettings::ParticleSettings() 
{
	//environment
	nearHideDistanceMin = 5;
	nearHideDistance = 25;
	farHideDistance = 90;
	farHideDistanceMax = 100;

	//emission
	emissionPosition = glm::vec3(0, 0, -100);
	emissionRadius = glm::vec3(100, 100, 0);

	particlesPerEmission = 5;
	emissionPeriod = 0.01f;

	minLifetime = 5;
	maxLifetime = 15;

	//movement
	direction = glm::vec3(0, 0, 0);
	directionNoise = glm::vec3(1, 1, 2);

	rotationVector = glm::vec3(1, 1, 1);
	minRotation = -2;
	maxRotation = 2;

	minVelocity = 1;
	maxVelocity = 10;
	velocityDamping = 0.01f;

	//visual
	startScale = glm::vec3(1, 1, 1);
	endScale = glm::vec3(0, 0, 0);

	startColor = glm::vec4(1.0f, 0.940f, 0.587f, 1.0f);
	endColor = glm::vec4(0.48f, 0.0f, 1, 0);
}