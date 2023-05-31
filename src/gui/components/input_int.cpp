#include "fiber_pool.hpp"
#include "gui/components/components.hpp"
#include "natives.hpp"

namespace big
{
	void components::input_int(const std::string_view label, int* value, float step, float stepfast, ImGuiInputTextFlags_ flag, std::function<void()> cb)
	{
		if (ImGui::InputInt(label.data(), value, step, stepfast, flag))
			if (cb)
				g_fiber_pool->queue_job(std::move(cb));

		if (ImGui::IsItemActive())
			g_fiber_pool->queue_job([] {
				PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
			});
	}
}