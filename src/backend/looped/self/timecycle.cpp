#include "backend/looped_command.hpp"
#include "natives.hpp"

namespace big
{

	class time_cycle_looped : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			GRAPHICS::SET_TIMECYCLE_MODIFIER(g.self.vision.timecycleentry);
		}

		virtual void on_disable() override
		{
			GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		}
	};

	time_cycle_looped g_time_cycle_looped("timecycle", "Heat Vision", "Provides the heatvision effect.", g.self.vision.heat_vision);
}
