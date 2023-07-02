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

        if (ImGui::CollapsingHeader("Emission"))
        {
            ImGui::SliderInt("Spawn per second", &_settings->emissionCount, 0, 1200);
            ImGui::DragFloat3("Position", glm::value_ptr(_settings->emissionPosition), 0.1f);
            ImGui::DragFloat3("Radius", glm::value_ptr(_settings->emissionRadius), 0.01f, 0, ImGuiSliderFlags_AlwaysClamp);
        }
        
        if (ImGui::CollapsingHeader("Forces", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::SeparatorText("Direction");
            ImGui::DragFloat3("Direction", glm::value_ptr(_settings->direction), 0.001f, -1, 1);
            ImGui::DragFloat3("Direction Noise", glm::value_ptr(_settings->directionNoise), 0.001f);

            ImGui::SeparatorText("Velocity");
            ImGui::DragFloatRange2("Velocity", &_settings->minVelocity, &_settings->maxVelocity, 0.01f, 0.0f, 120, "Min: %.2f", "Max: %.2f", ImGuiSliderFlags_AlwaysClamp);
            ImGui::DragFloat("Velocity Damping", &_settings->velocityDamping, 0.00001f, 0, 1, "%.5f");
        }

        if (ImGui::CollapsingHeader("Particle", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::SeparatorText("Scale");
            ImGui::DragFloat3("Start Scale", glm::value_ptr(_settings->startScale), 0.01f);
            ImGui::DragFloat3("End Scale", glm::value_ptr(_settings->endScale), 0.01f);

            ImGui::SeparatorText("Rotation");
            ImGui::DragFloat3("Vector", glm::value_ptr(_settings->rotationVector), 0.01f, -1, 1);
            ImGui::DragFloatRange2("Rotation Speed", &_settings->minRotation, &_settings->maxRotation, 0.01f);

            ImGui::SeparatorText("Lifetime");
            ImGui::DragFloatRange2("Lifetime", &_settings->minLifetime, &_settings->maxLifetime, 0.01f, 0.0f, 120, "Min: %.2f", "Max: %.2f", ImGuiSliderFlags_AlwaysClamp);

            ImGui::SeparatorText("Color");
            ImGui::ColorEdit4("Start Color", glm::value_ptr(_settings->startColor));
            ImGui::ColorEdit4("End Color", glm::value_ptr(_settings->endColor));

        }


        ImGui::End();
	}
}