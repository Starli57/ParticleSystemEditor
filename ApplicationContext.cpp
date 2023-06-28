#include "ApplicationContext.h"

ApplicationContext::ApplicationContext()
{
    logger = std::make_shared<Logging::Logger>();
    Utilities::DI::Register(logger);

    time = std::make_shared<Time>();
    Utilities::DI::Register(time);

    particleSystem = std::make_unique<ParticleSystem>();
    editorUi = std::make_unique<EditorUi>(particleSystem->GetParticleSettingsPtr());
}

ApplicationContext::~ApplicationContext()
{

}

void ApplicationContext::Update()
{
    time->Update();
    particleSystem->Update();
}

void ApplicationContext::UpdateGlfw()
{
    particleSystem->Render();
}

void ApplicationContext::UpdateImgui()
{
    editorUi->Render();
}