#include "../looped.hpp"
#include "natives.hpp"
#include "gta/enums.hpp"
#include "util/entity.hpp"

namespace big
{
	static auto last_time = std::chrono::steady_clock::now();
	Vector3 c             = self::pos;
	Object bh             = 0;

	void looped::weapons_blackhole_gun() //todo add support for multiple instances of the gun
	{
		Hash bhole = MISC::GET_HASH_KEY("prop_tool_spanner02"); //makes it easy to have an object, can set everything relative to it 
		
		const bool is_b_gun_selected = g.weapons.custom_weapon == CustomWeapon::BLACKHOLE_GUN;

		const auto time_now = std::chrono::steady_clock::now();

		const auto elapsed_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now - last_time).count();

		if (is_b_gun_selected)
		{
			if (PAD::IS_CONTROL_JUST_PRESSED(0, (int)ControllerInputs::INPUT_ATTACK))
			{
				bh = OBJECT::CREATE_OBJECT(bhole, self::pos.x, self::pos.y, self::pos.z, 1, 0, 1);
				LOG(INFO) << "Object  Created.";
				ENTITY::SET_ENTITY_HEADING(bh, ENTITY::GET_ENTITY_HEADING(self::ped));
				LOG(INFO) << "Attack Pressed.";
			}
			if (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("ent_sht_telegraph_pole")) //replace
			{
				STREAMING::REQUEST_NAMED_PTFX_ASSET("ent_sht_telegraph_pole");
				LOG(INFO) << "Asset Loaded.";
			}
			if (bh != 0)
			{
				GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY("ent_sht_telegraph_pole", bh, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
				LOG(INFO) << "Ptfx looped.";
				c = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(bh, 0, 1, 0);
				ENTITY::SET_ENTITY_COORDS(bh, c.x, c.y, c.z, 0, 0, 0, false);
				LOG(INFO) << "Coord Set.";
				Vector3 bhc = ENTITY::GET_ENTITY_COORDS(bh, 0);
				GRAPHICS::DRAW_MARKER_SPHERE(bhc.x, bhc.y, bhc.z, 1.f, 0, 0, 50, 180);
				LOG(INFO) << "Sphere Drawn.";
				for (Entity ent : entity::get_entities(true, true))
				{
					LOG(INFO) << "Entities Collected.";
					Vector3 nc = ENTITY::GET_ENTITY_COORDS(ent, 0) - ENTITY::GET_ENTITY_COORDS(bh, 0);
					ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, -nc.x, -nc.y, -nc.z, 0, 0, 0, 0, false, true, true, 0, 0);
					LOG(INFO) << "Applied Force.";
					if (elapsed_time_in_ms >= 40000)
					{
						LOG(INFO) << "Time Elapsed.";
						ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, nc.x, nc.y, nc.z, 0, 0, 0, 0, false, true, true, 0, 0);
						LOG(INFO) << "Applied Force Outward.";
						ENTITY::DELETE_ENTITY(&bh);
						LOG(INFO) << "Blackhole Deleted.";
						bh = 0;
						LOG(INFO) << "Blackhole = 0.";
						STREAMING::REMOVE_NAMED_PTFX_ASSET("ent_sht_telegraph_pole");
						LOG(INFO) << "Asset Unloaded.";
						last_time = time_now;
					}
				}
			}
		}
	}
}