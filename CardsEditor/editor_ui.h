#pragma once

namespace CardsEditor
{
	class EditorUi
	{
	public:
		bool show_demo_window = true;
		bool show_another_window = false;

		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		void Render();
	};
}