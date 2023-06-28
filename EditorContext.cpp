#include "EditorContext.h"

EditorContext::EditorContext()
{
	std::shared_ptr<ParticleSystem> particleSystem = Utilities::DI::Get<ParticleSystem>();
	editorUi = std::make_unique<EditorUi>(particleSystem->GetParticleSettingsPtr());
}

EditorContext::~EditorContext()
{

}

void EditorContext::Update()
{

}

void EditorContext::Render()
{
	editorUi->Render();
}