#include "fiber_pool.hpp"
#include "views/view.hpp"
#include "natives.hpp"

namespace big
{
	void view::vision()
	{
		components::sub_title("NIGHTVISTITLE");

		ImGui::Separator();

		components::command_checkbox<"nightvis">();
		components::command_checkbox<"nightvisov">();
		if (g.self.vision.nv_override)
			ImGui::InputFloat("Light Range", &g.self.vision.nv_lightrange, 1, 10);


		components::sub_title("HEATVISTITLE");

		ImGui::Separator();

		components::command_checkbox<"heatvis">();
		components::command_checkbox<"heatvisadv">();
		if (components::nav_button("Reset Heat Vision"))
		{
			g_fiber_pool->queue_job([] {
				GRAPHICS::SEETHROUGH_RESET();
			});
		}


		components::sub_title("TIMECYCLETITLE");

		ImGui::Separator();

		components::command_checkbox<"timecycle">();
		//ImGui::InputText("Timecycle Modifier", (char*)&g.self.vision.timecycleentry, sizeof(g.self.vision.timecycleentry)); look into this
		ImGui::InputFloat("Modifier Strength", &g.self.vision.timecyclestrength, 1.f, 10.f);


		components::sub_title("FOVTITLE");

		ImGui::Separator();

		components::command_checkbox<"fov">();
		if (g.self.vision.fov)
			ImGui::InputFloat("Fov Value", &g.self.vision.fovvalue, 1, 10);
	}
}