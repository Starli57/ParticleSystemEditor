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

        ImGui::SeparatorText("Emission");
        ImGui::DragFloat3("Position", glm::value_ptr(_settings->emissionPosition), 0.1f);
        ImGui::DragFloat("Radius", &_settings->emissionRadius, 0.01f, 0, ImGuiSliderFlags_AlwaysClamp);

        ImGui::SeparatorText("Force");
        ImGui::DragFloat3("Direction", glm::value_ptr(_settings->direction), 0.001f, -1, 1);
        ImGui::DragFloatRange2("Velocity", &_settings->minVelocity, &_settings->maxVelocity, 0.01f, 0.0f, 120, "Min: %.2f", "Max: %.2f", ImGuiSliderFlags_AlwaysClamp);

        ImGui::SeparatorText("Color");
        ImGui::ColorEdit4("Start Color", glm::value_ptr(_settings->startColor));
        ImGui::ColorEdit4("End Color", glm::value_ptr(_settings->endColor));

        ImGui::SeparatorText("Lifetime");
        ImGui::DragFloatRange2("Lifetime", &_settings->minLifetime, &_settings->maxLifetime, 0.01f, 0.0f, 120, "Min: %.2f", "Max: %.2f", ImGuiSliderFlags_AlwaysClamp);

        ImGui::End();
	}
}