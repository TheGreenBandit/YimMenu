#pragma once
#include "services/players/player_service.hpp"

namespace big
{
	class Esp
	{
	public:
		static void draw1();
		static void draw_player1(const player_ptr& plyr, ImDrawList* const draw_list);
	};
}