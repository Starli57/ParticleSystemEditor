
#include "log_console.h"

namespace CardsEditor
{
	void LogConsole::Render()
	{
        ImGui::Begin("LogConsole"); 

        std::shared_ptr<Logging::Logger> logger = Utilities::DI::Get<Logging::Logger>();
        for (int i = 0; i < logger->GetMaxMessagesCount(); i++)
        {
            ImGui::Text(logger->messages[i].c_str());
        }

        ImGui::End();
	}
}