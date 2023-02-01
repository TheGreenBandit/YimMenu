#include "backend/looped/looped.hpp"
#include "fiber_pool.hpp"
#include "gta/enums.hpp"
#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "esp.hpp"
#include "pointers.hpp"

namespace big
{

	void Esp::draw_player1(const player_ptr & plyr, ImDrawList* const draw_list)
	{
		Ped player = plyr->get_ped();
		Vector3 head = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_Head", 0, 0, 0);
		Vector3 root = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_ROOT", 0, 0, 0);
		Vector3 lshoulder = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_L_Clavicle", 0, 0, 0);
		Vector3 rshoulder = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_R_Clavicle", 0, 0, 0);
		Vector3 lelbow = PED::GET_PED_BONE_COORDS(player, (int)"MH_L_Elbow ", 0, 0, 0);
		Vector3 relbow = PED::GET_PED_BONE_COORDS(player, (int)"MH_R_Elbow ", 0, 0, 0);
		Vector3 lhand = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_L_Hand", 0, 0, 0);
		Vector3 rhand = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_R_Hand", 0, 0, 0);
		Vector3 pelvis = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_Pelvis", 0, 0, 0);
		Vector3 lthigh = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_L_Thigh ", 0, 0, 0);
		Vector3 rthigh = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_R_Thigh ", 0, 0, 0);
		Vector3 lknee = PED::GET_PED_BONE_COORDS(player, (int)"MH_L_Knee", 0, 0, 0);
		Vector3 rknee = PED::GET_PED_BONE_COORDS(player, (int)"MH_R_Knee", 0, 0, 0);
		Vector3 lfoot = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_L_Foot", 0, 0, 0);
		Vector3 rfoot = PED::GET_PED_BONE_COORDS(player, (int)"SKEL_R_Foot", 0, 0, 0);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(head.x, head.y, head.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int rootsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(root.x, root.y, root.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(lshoulder.x, lshoulder.y, lshoulder.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(rshoulder.x, rshoulder.y, rshoulder.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(lelbow.x, lelbow.y, lelbow.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(relbow.x, relbow.y, relbow.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(lhand.x, lhand.y, lhand.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(rhand.x, rhand.y, rhand.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);
		int headsc = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(head.x, head.y, head.z, (float*)g_pointers->m_resolution_x, (float*)g_pointers->m_resolution_y);

		GRAPHICS::DRAW_MARKER_SPHERE(head.x, head.y, head.z, 10.0f, 12, 255, 57, 255);
		draw_list->AddLine(ImVec2{ rootsc.x, rootsc.y }, ImVec2{ headsc.x, headsc.y }, 352352, 1.0f);
		GRAPHICS::DRAW_LINE(head.x, head.y, head.z, root.x, root.y, root.z, 12, 255, 57, 255);//head to mid body
		GRAPHICS::DRAW_LINE(lshoulder.x, lshoulder.y, lshoulder.z, lelbow.x, lelbow.y, lelbow.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(rshoulder.x, rshoulder.y, rshoulder.z, relbow.x, relbow.y, relbow.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(rshoulder.x, rshoulder.y, rshoulder.z, lshoulder.x, lshoulder.y, lshoulder.z, 12, 255, 57, 255); //makes shoulders cross to meet with main line
		GRAPHICS::DRAW_LINE(lelbow.x, lelbow.y, lelbow.z, lhand.x, lhand.y, lhand.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(relbow.x, relbow.y, relbow.z, rhand.x, rhand.y, rhand.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(root.x, root.y, root.z, pelvis.x, pelvis.y, pelvis.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(lthigh.x, lthigh.y, lthigh.z, pelvis.x, pelvis.y, pelvis.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(rthigh.x, rthigh.y, rthigh.z, pelvis.x, pelvis.y, pelvis.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(lknee.x, lknee.y, lknee.z, lfoot.x, lfoot.y, lfoot.z, 12, 255, 57, 255);
		GRAPHICS::DRAW_LINE(rknee.x, rknee.y, rknee.z, rfoot.x, rfoot.y, rfoot.z, 12, 255, 57, 255);
	}
}