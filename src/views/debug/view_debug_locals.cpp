#include "view_debug.hpp"
#include "gui/components/components.hpp"
#include "natives.hpp"

namespace big
{
	void debug::locals()
	{
		if (ImGui::BeginTabItem("Locals"))
		{
			if (components::button("Load MP Map"))
				DLC::ON_ENTER_MP();
			ImGui::SameLine();
			if (components::button("Load SP Map"))
				DLC::ON_ENTER_SP();
			ImGui::EndTabItem();
		}
	}
}