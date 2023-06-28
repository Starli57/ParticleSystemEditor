#include "ApplicationContext.h"

ApplicationContext::ApplicationContext()
{
    logger = std::make_shared<Logging::Logger>();
    Utilities::DI::Register(logger);

    time = std::make_shared<Time>();
    Utilities::DI::Register(time);

    particleSystem = std::make_shared<ParticleSystem>();
    Utilities::DI::Register(particleSystem);
}

ApplicationContext::~ApplicationContext()
{

}

void ApplicationContext::Update()
{
    time->Update();
    particleSystem->Update();
}

void ApplicationContext::Render()
{
    particleSystem->Render();
}