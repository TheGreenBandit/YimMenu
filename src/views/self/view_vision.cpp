#include "fiber_pool.hpp"
#include "views/view.hpp"

namespace big
{
	void view::vision()
	{
		components::sub_title("NIGHTVISTITLE");

		ImGui::Separator();

		components::command_checkbox<"nightvis">();
		if (components::command_checkbox<"overridenv">())
			ImGui::InputFloat("Light Range", &g.self.vision.nv_lightrange, 1.f, 10.f, "%d");



		components::sub_title("HEATVISTITLE");

		ImGui::Separator();

		components::command_checkbox<"heatvis">();
		if (components::command_checkbox<"heatvisadv">())
		{		
			if (ImGui::Button("Reset Options"))
			{
				//todo, just use GRAPHICS::RESET_SEETHROUGH, could rpob just turn off and on as i set it to reset on turnoff.
			}
		}



		components::sub_title("TIMECYCLETITLE");

		ImGui::Separator();

		components::command_checkbox<"timecycle">();
		//ImGui::InputText("Timecycle Modifier", (char*)&g.self.vision.timecycleentry, sizeof(g.self.vision.timecycleentry)); look into this
		ImGui::InputFloat("Modifier Strength", &g.self.vision.timecyclestrength, 1.f, 10.f);
	}
}