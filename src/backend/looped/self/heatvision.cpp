#include "backend/looped_command.hpp"
#include "natives.hpp"

namespace big
{
	int last_hvision = 0;

	class heat_vision_looped : looped_command
	{
		using looped_command::looped_command;

		virtual void on_enable() override
		{
			last_hvision = GRAPHICS::GET_USINGSEETHROUGH();
		}

		virtual void on_tick() override
		{
			GRAPHICS::SET_SEETHROUGH(true);
		}

		virtual void on_disable() override
		{
			GRAPHICS::SET_SEETHROUGH(last_hvision);
		}
	};

	heat_vision_looped
	    g_heat_vision_looped("heatvis", "Heat Vision", "Provides the heatvision effect.", g.self.vision.heat_vision);
	bool_command g_override_nightvis("overridenv", "Override Light Range", "Allows you to set the light in the nightvision to a custom amount.",
	    g.self.vision.nv_override);
}
