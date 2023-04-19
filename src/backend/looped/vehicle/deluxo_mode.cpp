#include "backend/looped_command.hpp"
#include "gta/enums.hpp"
#include "natives.hpp"

namespace big
{
	class deluxo_mode : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (g_local_player && g_local_player->m_vehicle)
			{
				g_local_player->m_vehicle->m_handling_data->m_model_flags    = 4456464;
				g_local_player->m_vehicle->m_handling_data->m_handling_flags  = 8519690;
				g_local_player->m_vehicle->m_flags                            = 1073808655;
				g_local_player->m_vehicle->m_flags_2                          = 83886335;
				g_local_player->m_vehicle->m_flags_3                          = 1100530752;
				g_local_player->m_vehicle->m_flags_4                          = 1245439;
				g_local_player->m_vehicle->m_model_info->m_flags              = 2147487745;
				VEHICLE::SET_DISABLE_HOVER_MODE_FLIGHT(self::veh, false);
				VEHICLE::SET_HOVER_MODE_WING_RATIO(self::veh, 1.f);
				VEHICLE::SET_SPECIAL_FLIGHT_MODE_ALLOWED(self::veh, true);
			}
		}

		virtual void on_disable() override
		{
			//if (g_local_player && g_local_player->m_vehicle)
			//	g_local_player->m_vehicle->m_flags &= ~(1 << 24)
		}
	};

	deluxo_mode g_deluxo_mode("deluxomode", "Deluxo Mode", "Makes your mvehicle preform like a deluxo",
	    g.vehicle.deluxo_mode);
}
