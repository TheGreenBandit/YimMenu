#include "backend/looped_command.hpp"
#include "backend/int_command.hpp"
#include "natives.hpp"

namespace big
{
	class fov_looped : looped_command
	{
		using looped_command::looped_command;

		Cam cam;
		Vector3 rot;
		Vector3 pos;

		virtual void on_enable() override
		{
			cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 0);

			pos = CAM::GET_GAMEPLAY_CAM_COORD();
			rot = CAM::GET_GAMEPLAY_CAM_ROT(2);

			ENTITY::FREEZE_ENTITY_POSITION(self::veh, true);

			CAM::SET_CAM_COORD(cam, pos.x, pos.y, pos.z);
			CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 2);
			CAM::SET_CAM_ACTIVE(cam, true);
			CAM::RENDER_SCRIPT_CAMS(true, true, 500, true, true, 0);
		}

		virtual void on_tick() override
		{
			pos = CAM::GET_GAMEPLAY_CAM_COORD();
			rot = CAM::GET_GAMEPLAY_CAM_ROT(2);

			CAM::ATTACH_CAM_TO_ENTITY(cam, self::ped, 0.f, 1.f, 0.f, true);
			CAM::SET_CAM_FOV(cam, g.self.vision.fovvalue);
			CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 2);
			STREAMING::SET_FOCUS_POS_AND_VEL(pos.x, pos.y, pos.z, 0.f, 0.f, 0.f);
			//CAM::SET_CAM_FOV(cam, CAM::GET_GAMEPLAY_CAM_FOV()); reset todo make button for it
		}

		virtual void on_disable() override
		{
			CAM::SET_CAM_ACTIVE(cam, false);
			CAM::RENDER_SCRIPT_CAMS(false, true, 500, true, true, 0);
			CAM::DESTROY_CAM(cam, false);
			STREAMING::CLEAR_FOCUS();
			
			ENTITY::FREEZE_ENTITY_POSITION(cam, false);
		}
	};

	fov_looped g_fov_looped("fov", "Override Fov", "Override the fov to a desired amount.", g.self.vision.fov);
//	int_command g_fov_value("fovval", "Fov Value", "Set the fov.", g.self.vision.fovvalue, 1, 300);
}