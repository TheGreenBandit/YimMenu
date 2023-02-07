#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{

	class action_figure_drop_looped : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override //1666779307//moneybag
		{

			//0x4D6514A3/*vw_prop_vw_colle_alien*/, 0x748F3A2A/*vw_prop_vw_colle_beast*/, 0x1A9736DA/*vw_prop_vw_colle_imporage*/,0x3D1B7A2F/*vw_prop_vw_colle_pogo*/,
			//0x1A126315/*vw_prop_vw_colle_prbubble*/, 0xD937A5E9/*vw_prop_vw_colle_rsrcomm*/, 0x23DDE6DB/*vw_prop_vw_colle_rsrgeneric*/, 0x991F8C36/*vw_prop_vw_colle_sasquatch*/
			Player splayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()));
			Vector3 c = PED::GET_PED_BONE_COORDS(splayer, 46523, 0, 0, 0);

			STREAMING::REQUEST_MODEL(0x4D6514A3);
			if (STREAMING::HAS_MODEL_LOADED(0x4D6514A3))
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, c.x, c.y, c.z, NULL, 10, 0x4D6514A3, false, false);
			}
		}
	};

	action_figure_drop_looped g_afdrop("afdrop", "Action Figure Drop", "Allows You To Drop Action Figures On Someone", g.player.action_figure_drop);
}
