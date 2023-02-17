#include "backend/looped/looped.hpp"
#include "natives.hpp"
#include "gta/enums.hpp"

namespace big
{
	void looped::weapons_grappling_gun()
	{
		if(g.weapons.grappling_gun)
		{
			Vector3 ghit;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(self::ped, &ghit);
			Vector3 hand = PED::GET_PED_BONE_COORDS(self::ped, (int)PedBones::SKEL_R_Hand, 0, 0, 0);
			GRAPHICS::DRAW_LINE(hand.x, hand.y, hand.z, ghit.x, ghit.y, ghit.z, 0, 0, 0, 255);
			int mult = 0;
			if (NETWORK::NETWORK_IS_SESSION_STARTED())
			{
				mult = 1;
			}
			else
			{
				mult = 0;
			}
			if (PAD::IS_CONTROL_PRESSED(0, (int)ControllerInputs::INPUT_ATTACK))
			{
				TASK::TASK_PLAY_ANIM(self::ped, "amb@code_human_in_car_mp_actions@fist_pump@bodhi@rds@base", "idle_a", 1.f, 1.f, 0, 120, 0, 0, 0, mult);
				if (PAD::IS_CONTROL_PRESSED(0, (int)ControllerInputs::INPUT_JUMP))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(self::ped, 5, 0, 100, 0, false, false, true, false);
				}
				ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(self::ped, 15, 0, -1, 0, false, false, true, false);
			}
		}
	}
}