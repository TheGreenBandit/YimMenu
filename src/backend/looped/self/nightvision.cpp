#include "backend/looped_command.hpp"
#include "natives.hpp"

namespace big
{
	int last_nvision = 0;

	class night_vision_looped : looped_command
	{
		using looped_command::looped_command;

		virtual void on_enable() override
		{
			last_nvision = GRAPHICS::GET_USINGNIGHTVISION();
		}

		virtual void on_tick() override
		{
			GRAPHICS::SET_NIGHTVISION(true);
			if (g.self.vision.nv_override)
				GRAPHICS::OVERRIDE_NIGHTVISION_LIGHT_RANGE(g.self.vision.nv_lightrange);
		}

		virtual void on_disable() override
		{
			GRAPHICS::SET_NIGHTVISION(last_nvision);
		}
	};

	night_vision_looped g_night_vision_looped("nightvis", "Night Vision", "Provides the nightvision effect.",
	    g.self.vision.night_vision);
	bool_command g_override_nightvis("overridenv", "Override Light Range", "Allows you to set the light in the nightvision to a custom amount.",
	    g.self.vision.nv_override);
}
