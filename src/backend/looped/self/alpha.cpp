#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{

	class alpha_looped : looped_command
	{
		using looped_command::looped_command;

		bool toggle = false;

		virtual void on_enable() override
		{
			toggle = true;
		}

		virtual void on_tick() override
		{
			if (toggle)
			{															//change from null
				ENTITY::SET_ENTITY_ALPHA(self::ped, g.self.alphavalue, NULL);
			}
		}

		virtual void on_disable() override
		{
			toggle = false;
			ENTITY::RESET_ENTITY_ALPHA(self::ped);
		}
	};

	alpha_looped g_alpha_set("alpha", "Override Alpha", "Allows greater control over your invisibility", g.self.alpha);
}
