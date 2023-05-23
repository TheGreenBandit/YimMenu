#include "fiber_pool.hpp"
#include "services/mobile/mobile_service.hpp"
#include "util/mobile.hpp"
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



		components::sub_title("TIMECYCLETITLE");

		ImGui::Separator();


	}
}