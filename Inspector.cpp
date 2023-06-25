#include "Inspector.h"

namespace ParticleSystemEditor
{
    Inspector::Inspector(ParticleSettings* settings)
    {
        _settings = settings;
    }

	void Inspector::Render()
	{
        ImGui::Begin("Inspector");

        ImGui::DragFloat3("Position", glm::value_ptr(_settings->startPosition), 0.1f);
        ImGui::DragFloat3("Velocity", glm::value_ptr(_settings->startVelocity), 0.001f);

        ImGui::ColorEdit4("Start Color", glm::value_ptr(_settings->startColor));
        ImGui::ColorEdit4("End Color", glm::value_ptr(_settings->endColor));

        ImGui::DragFloat("Lifetime", &_settings->startLifetime, 0.01f, 0, 120);

        ImGui::End();
	}
}