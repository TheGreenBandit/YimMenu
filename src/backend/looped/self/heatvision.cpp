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
			if (g.self.vision.heat.heat_vision_advanced_override)
			{
				GRAPHICS::SEETHROUGH_SET_FADE_STARTDISTANCE(g.self.vision.heat.fadestart);
				GRAPHICS::SEETHROUGH_SET_FADE_ENDDISTANCE(g.self.vision.heat.fadeend);
				GRAPHICS::SEETHROUGH_SET_MAX_THICKNESS(g.self.vision.heat.maxthick);
				GRAPHICS::SEETHROUGH_SET_NOISE_MIN(g.self.vision.heat.noisemin);
				GRAPHICS::SEETHROUGH_SET_NOISE_MAX(g.self.vision.heat.noisemax);
				GRAPHICS::SEETHROUGH_SET_HILIGHT_INTENSITY(g.self.vision.heat.highlight_intensity);
				GRAPHICS::SEETHROUGH_SET_HIGHLIGHT_NOISE(g.self.vision.heat.highlight_noise);
				GRAPHICS::SEETHROUGH_SET_HEATSCALE(g.self.vision.heat.heatscale_index, g.self.vision.heat.heatscale);
				GRAPHICS::SEETHROUGH_SET_COLOR_NEAR(g.self.vision.heat.color_near_r,
				    g.self.vision.heat.color_near_g,
				    g.self.vision.heat.color_near_b);
			}
		}

		virtual void on_disable() override
		{
			GRAPHICS::SET_SEETHROUGH(last_hvision);
			GRAPHICS::SEETHROUGH_RESET();
		}
	};

	heat_vision_looped
	    g_heat_vision_looped("heatvis", "Heat Vision", "Provides the heatvision effect.", g.self.vision.heat.heat_vision);
	bool_command g_heat_vision_advanced("heatvisadv", "Advanced Options", "",
	    g.self.vision.nv_override);
}
