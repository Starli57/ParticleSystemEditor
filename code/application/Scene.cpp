#include "Scene.h"

#define timer Utilities::DI::Get<Time>()

Scene::Scene()
{
    logger = std::make_shared<Logging::Logger>();
    Utilities::DI::Register(logger);

    particleSystem = std::make_shared<ParticleSystem>();
    Utilities::DI::Register(particleSystem);
}

Scene::~Scene()
{

}

void Scene::Update()
{
    timer->Update();
    particleSystem->Update();
}

void Scene::Render()
{
    particleSystem->Render();
}