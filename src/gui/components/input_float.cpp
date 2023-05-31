#include "fiber_pool.hpp"
#include "gui/components/components.hpp"
#include "natives.hpp"

namespace big
{
	void components::input_float(const std::string_view label, float* value, float step, float stepfast, const char* format = "%.f", ImGuiInputTextFlags_ flag, std::function<void()> cb)
	{
		if (ImGui::InputFloat(label.data(), value, step, stepfast, "%.f", flag))
			if (cb)
				g_fiber_pool->queue_job(std::move(cb));

		if (ImGui::IsItemActive())
			g_fiber_pool->queue_job([] {
				PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
			});
	}
}