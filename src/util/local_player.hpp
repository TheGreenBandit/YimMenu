#pragma once
#include "core/data/levels.hpp"
#include "gta/joaat.hpp"
#include "natives.hpp"
#include "script_global.hpp"

namespace big::local_player
{
	inline void get_active_character_slot(int* character_slot)
	{
		STATS::STAT_GET_INT(RAGE_JOAAT("MPPLY_LAST_MP_CHAR"), character_slot, true);
	}

	inline std::string get_mp_prefix()
	{
		get_active_character_slot(&g.player.character_slot);
		return "MP" + std::to_string(g.player.character_slot) + "_";
	}

	inline Vector3 ROTATION_TO_DIRECTION(Vector3* rot)
	{
		float radiansZ = rot->z * 0.0174532924f;
		float radiansX = rot->x * 0.0174532924f;
		float num      = std::abs((float)std::cos((double)radiansX));
		Vector3 dir;
		dir.x = (float)((double)((float)(-(float)std::sin((double)radiansZ))) * (double)num);
		dir.y = (float)((double)((float)std::cos((double)radiansZ)) * (double)num);
		dir.z = (float)std::sin((double)radiansX);
		return dir;
	}

	inline Vector3 get_coords_ahead_of_cam(int distance)
	{
		Vector3 Krox_Com_Pos = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 Krox_Rot     = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 Krox_Die     = ROTATION_TO_DIRECTION(&Krox_Rot);
		Vector3 Krox_Leg_Vec = Krox_Die * distance;
		Vector3 Results      = Krox_Com_Pos + Krox_Leg_Vec;
		return Results;
	}
}