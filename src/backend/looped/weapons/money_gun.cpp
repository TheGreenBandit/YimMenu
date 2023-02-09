#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "gta/enums.hpp"
#include "util/entity.hpp"

namespace big
{
	class money_gun : looped_command
	{

		virtual void on_tick() override //1666779307//moneybag
		{
			bool bMoneyGun = g.weapons.custom_weapon == CustomWeapon::MONEY_GUN;

			if (bMoneyGun)
			{
				//0x4D6514A3/*vw_prop_vw_colle_alien*/, 0x748F3A2A/*vw_prop_vw_colle_beast*/, 0x1A9736DA/*vw_prop_vw_colle_imporage*/,0x3D1B7A2F/*vw_prop_vw_colle_pogo*/,
				//0x1A126315/*vw_prop_vw_colle_prbubble*/, 0xD937A5E9/*vw_prop_vw_colle_rsrcomm*/, 0x23DDE6DB/*vw_prop_vw_colle_rsrgeneric*/, 0x991F8C36/*vw_prop_vw_colle_sasquatch*/
				Vector3 c;
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(self::ped, &c);

				STREAMING::REQUEST_MODEL(0x4D6514A3);
				if (STREAMING::HAS_MODEL_LOADED(0x4D6514A3))
				{
					if (PAD::IS_CONTROL_JUST_RELEASED(0, (int)ControllerInputs::INPUT_ATTACK) && WEAPON::GET_WEAPON_DAMAGE_TYPE(g_local_player->m_weapon_manager->m_weapon_info->m_human_name_hash) != 1 || 0 || 2) //change to if(GET_WEAPON_DAMAGE_TYPE) != 1 || 0 || 2
					{
						OBJECT::CREATE_AMBIENT_PICKUP(1666779307, c.x, c.y, c.z + 10, 0, 10, 0x4D6514A3, false, false);
						script::get_current()->yield(200ms);
					}
				}
			}
		}
	};
}
