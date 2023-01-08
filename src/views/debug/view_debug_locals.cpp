#include "view_debug.hpp"
#include "gui/components/components.hpp"
#include "natives.hpp"

namespace big
{
	void debug::locals()
	{
		if (ImGui::BeginTabItem("Locals"))
		{
			const char cutscene_name = "";
			const char cutscene_nameflags = "";
			int flags = 0;
			if (components::button("Load MP Map"))
				DLC::ON_ENTER_MP();
			ImGui::SameLine();
			if (components::button("Load SP Map"))
				DLC::ON_ENTER_SP();
			if (components::button("Skip Cutscene"))
				CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
			if (components::button("Stop Player Switch"))
				STREAMING::STOP_PLAYER_SWITCH();
			if (components::button("Stop Loading"))
			{
				if (CAM::IS_SCREEN_FADED_OUT())
					CAM::DO_SCREEN_FADE_IN(0);
				SCRIPT::SHUTDOWN_LOADING_SCREEN();
			}
			ImGui::Text("Request Cutscene Types");
			components::input_text_with_hint("##Name Of Cutscene No Flags", "Simply loads the cutscene and doesn't do extra stuff that REQUEST_CUTSCENE does.", &cutscene_name);
			ImGui::SameLine();
			if (components::button("Request"))
			{
				CUTSCENE::REQUEST_CUT_FILE(cutscene_name);
			}
			components::input_text_with_hint("##With Flag", "flags are usually 8", &cutscene_nameflags);
			ImGui::InputInt("##Flag", &flags);
			if (components::button("Request"))
			{
				CUTSCENE::REQUEST_CUTSCENE(cutscene_nameflags, flags);
			}

			REQUEST_CUTSCENE_WITH_PLAYBACK_LIST
			if hovered Example : 0x105 (bit 0, 2 and 8 set) will enable scene 1, 3 and 9.
			ImGui::EndTabItem();
		}
	}
}