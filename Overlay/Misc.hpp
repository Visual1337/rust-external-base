int MiscDrawing()
{
	auto draw = ImGui::GetBackgroundDrawList();

	if (global.draw_fov)
	{
		draw->AddCircle(ImVec2(global.screen_width / 2, global.screen_height / 2), global.aimbot_fov, ImColor(255, 255, 255, 255), 64, 1.f);
	}

	return -1;
}