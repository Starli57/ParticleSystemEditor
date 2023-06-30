#include "Editor.h"

Editor::Editor()
{
	std::shared_ptr<ParticleSystem> particleSystem = Utilities::DI::Get<ParticleSystem>();

	logConsole = new LogConsole();
	inspector = new Inspector(particleSystem->GetParticleSettingsPtr());
}

Editor::~Editor()
{
	delete(inspector);
	delete(logConsole);
}

void Editor::Update()
{
}

void Editor::Render()
{
	logConsole->Render();
	inspector->Render();
}