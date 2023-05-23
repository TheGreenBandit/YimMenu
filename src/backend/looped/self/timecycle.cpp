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
			GRAPHICS::SET_TIMECYCLE_MODIFIER_STRENGTH(g.self.vision.timecyclestrength);
		}

		virtual void on_disable() override
		{
			GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		}
	};

	time_cycle_looped 
		g_time_cycle_looped("timecycle", "Override Timecycle", "Override the timecycle to one you want.", g.self.vision.timecycle_override);
}
