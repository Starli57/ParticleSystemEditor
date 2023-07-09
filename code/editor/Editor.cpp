#include "Editor.h"

Editor::Editor()
{
	std::shared_ptr<ParticleSystem> particleSystem = Utilities::DI::Get<ParticleSystem>();

	logConsole = new LogConsole();
	statusDisplay = new StatusDisplay();
	inspector = new Inspector(particleSystem->GetParticleSettingsPtr());
}

Editor::~Editor()
{
	delete(inspector);
	delete(statusDisplay);
	delete(logConsole);
}

void Editor::Update()
{
}

void Editor::Render()
{
	logConsole->Render();
	statusDisplay->Render();
	inspector->Render();
}