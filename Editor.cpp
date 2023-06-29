#include "Editor.h"

Editor::Editor()
{
	std::shared_ptr<ParticleSystem> particleSystem = Utilities::DI::Get<ParticleSystem>();
	editorUi = std::make_unique<EditorUi>(particleSystem->GetParticleSettingsPtr());
}

Editor::~Editor()
{

}

void Editor::Update()
{

}

void Editor::Render()
{
	editorUi->Render();
}