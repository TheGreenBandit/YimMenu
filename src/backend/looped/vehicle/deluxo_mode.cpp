#include "backend/looped_command.hpp"
#include "gta/enums.hpp"
#include "natives.hpp"
#include "vehicle/CVehicleModelInfo.hpp"

namespace big
{
	class deluxo_mode : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (g_local_player && g_local_player->m_vehicle)
			{

			}
		}

		virtual void on_disable() override
		{

		}
	};

	deluxo_mode g_deluxo_mode("deluxomode", "Deluxo Mode", "Makes your vehicle preform like a deluxo.",
	    g.vehicle.deluxo_mode);
}
//crash idea
//create ped, handle->m_model_info = vehicle or some other shit that will break it.