#include "views/view.hpp"
#include "util/scripts.hpp"
#include "script/globals/GPBD_FM_3.hpp"

namespace big
{
	void view::player_recovery()
	{
		if (ImGui::TreeNode("RECOVERY"))
		{

			components::command_checkbox<"rpdrop">();

			ImGui::TreePop();
		}
	}
}