#include "backend/looped/looped.hpp"
#include "gta/enums.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/entity.hpp"
#include "util/local_player.hpp"

namespace big
{
	int fuc_baba_yogo_grab_cars_cam = 30;

	void looped::self_babayoga()
	{
		if (g.self.babayoga)
		{
			CAM::STOP_GAMEPLAY_CAM_SHAKING(true);
			if (GetAsyncKeyState(0x41))
			{
				fuc_baba_yogo_grab_cars_cam--;
			}
			if (GetAsyncKeyState(0x44))
			{
				fuc_baba_yogo_grab_cars_cam++;
			}
			ENTITY::PLAY_ENTITY_ANIM(self::ped, (char*)"rcmcollect_paperleadinout@", (char*)"meditiate_idle", 1, true, true, 0, 1.f, 0);
			if (!ENTITY::GET_ENTITY_COLLISION_DISABLED(self::ped))
			{
				ENTITY::SET_ENTITY_COLLISION(self::ped, false, true);
			}
			Vector3 rot = ENTITY::GET_ENTITY_ROTATION(self::ped, 2);
			ENTITY::SET_ENTITY_ROTATION(self::ped, rot.x, rot.y, rot.z + 5, 2, 0);
			Vector3 Cam_coord = local_player::get_coords_ahead_of_cam(20);
			Vector3 Sub_Cords = Cam_coord - self::pos;
			Vector3 velocity  = ENTITY::GET_ENTITY_VELOCITY(self::ped);
			ENTITY::APPLY_FORCE_TO_ENTITY(self::ped, 1, Sub_Cords.x * 9.f, Sub_Cords.y * 9.f, Sub_Cords.z * 9.f, 0.f, 0.f, 0.f, 0, false, true, true, 0, 0);
			//"scr_rcbarry1", "scr_alien_teleport"
			GRAPHICS::START_PARTICLE_FX_LOOPED_ON_PED_BONE((char*)"scr_rcbarry1", self::ped, 0, 0, 0, 0, 0, 0, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(self::ped, "IK_L_Hand"), .01, 0, 0, 0);
			GRAPHICS::START_PARTICLE_FX_LOOPED_ON_PED_BONE((char*)"scr_rcbarry1", self::ped, 0, 0, 0, 0, 0, 0, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(self::ped, "IK_R_Hand"), .01, 0, 0, 0);
			Vector3 poly_coord = CAM::GET_CAM_COORD(fuc_baba_yogo_grab_cars_cam);
			GRAPHICS::DRAW_MARKER_SPHERE(poly_coord.x, poly_coord.y, poly_coord.z, 2, 0, 255, 255, 255);
			for (auto entity : entity::get_entities(true, true))
			{
				if (entity::take_control_of(entity, 0))
				{
					entity::push_entity_to_cam(entity, fuc_baba_yogo_grab_cars_cam, 60);
				}
			}
		}
		else
		{
			ENTITY::SET_ENTITY_COLLISION(self::ped, true, true);
		}
	}
}