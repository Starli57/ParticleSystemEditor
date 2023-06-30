#include "Editor.h"

#define MLogger Utilities::DI::Get<Logging::Logger>()
#define Timer Utilities::DI::Get<Time>()

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
	std::stringstream msg;
	msg << "Frames: " << (int)(1 / Timer->GetDeltaTime());
	MLogger->Log(msg.str());
}

void Editor::Render()
{
	logConsole->Render();
	inspector->Render();
}