#include "Scene.h"

Scene::Scene()
{
    logger = std::make_shared<Logging::Logger>();
    Utilities::DI::Register(logger);

    time = std::make_shared<Time>();
    Utilities::DI::Register(time);

    particleSystem = std::make_shared<ParticleSystem>();
    Utilities::DI::Register(particleSystem);
}

Scene::~Scene()
{

}

void Scene::Update()
{
    time->Update();
    particleSystem->Update();
}

void Scene::Render()
{
    particleSystem->Render();
}