/*---------Drawing Functions---------*/
void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness);
void Outline_Text(Vector2 screen, std::string txt, ImColor color);

/*---------Esp Functions---------*/
void DrawPlayers(ImDrawList* draw);
void DrawResources(ImDrawList* draw);
void DrawWorld(ImDrawList* draw);
void DrawItems(ImDrawList* draw);

/*---------Esp---------*/
void Esp()
{
	global.view_matrix = driver.read<matrix4x4>(global.camera + Offsets::Camera.ViewMatrix2);

	ImDrawList* draw = ImGui::GetBackgroundDrawList();

	DrawPlayers(draw);
	DrawResources(draw);
	DrawWorld(draw);
	DrawItems(draw);
}

void DrawPlayers(ImDrawList* draw)
{
	if (global.show_player)
	{
		std::vector<RUSTPLAYER> cached_players = global.player_list;

		Vector2 screen_position;
		for (int i = 0; i < cached_players.size(); i++)
		{
			RUSTPLAYER player = cached_players[i];

			if ((global.player_ignore_npc && player.is_npc) || (global.player_ignore_sleeping && player.is_sleeping)) continue;

			Vector3 orgin = driver.read<Vector3>(player.orgin_ptr + 0x90);

			if (orgin == Vector3(0, 0, 0)) continue;

			//printf("%f %f %f\n", orgin.x, orgin.y, orgin.z);

			Vector3 head_position = Vector3(orgin.x, orgin.y + 1.8f, orgin.z);
			Vector3 hand_position = Vector3(orgin.x, orgin.y, orgin.z + 1.0f);
			Vector2 screen_head;

			float distance = players.local_position.Distance(orgin);
			if (camera.WorldToScreen(orgin, screen_position, global.view_matrix) && camera.WorldToScreen(head_position, screen_head, global.view_matrix) && distance < global.max_player_distance && distance > 1.0f)
			{
				float height = screen_head.y - screen_position.y;
				float width = height / 2.0f;

				std::string player_esp_string = "";
				if (global.show_player_name)
				{
					player_esp_string.append(std::string(player.name));
				}
				if (global.show_player_distance)
				{
					player_esp_string.append(std::string(" [" + std::to_string((int)players.local_position.Distance(orgin)) + " m]"));
				}
				Outline_Text(Vector2(screen_position.x, screen_position.y + 10), player_esp_string, global.player_name_color);

				if (global.show_player_box)
				{
					DrawCorneredBox(screen_position.x - (width / 2), screen_position.y, width, height, global.player_box_color, 1.0f);
				}
			}
		}
	}
}







void DrawResources(ImDrawList* draw)
{
	if (global.show_resource)
	{
		std::vector<RUSTRESOURCE> cached_resources = global.resource_list;
		Vector2 screen_position;

		for (int i = 0; i < cached_resources.size(); i++)
		{
			RUSTRESOURCE resource = cached_resources[i];

			ImColor color;
			bool skip = false;
			/*
				Stone Hash	1696469454
				Metal Hash	1622519874
				Sulfur Hash 1554069420
				Hemp Hash	1082534429
			*/

			//Find The Resources Color And Determine Weather You Need To Skip Or Not
			switch (resource.name_hash)
			{
			case 1696469454:
				skip = !global.show_stone;
				color = global.stone_color;
				break;
			case 1622519874:
				skip = !global.show_metal;
				color = global.metal_color;
				break;
			case 1554069420:
				skip = !global.show_sulfur;
				color = global.sulfur_color;
				break;
			case 1082534429:
				skip = !global.show_hemp;
				color = global.hemp_color;
				break;
			default:
				skip = true;
				break;
			}

			float distance = players.local_position.Distance(resource.position);

			if (skip || distance > global.max_resource_distance) continue;

			if (camera.WorldToScreen(resource.position, screen_position, global.view_matrix))
			{
				std::string resource_esp_string = "";
				if (global.show_resource_name)
				{
					resource_esp_string.append(std::string(resource.name));
				}
				if (global.show_resource_distance)
				{
					resource_esp_string.append(" [" + std::to_string((int)distance) + " m]");
				}

				Outline_Text(Vector2(screen_position.x, screen_position.y + 10), resource_esp_string, color);
			}
		}
	}
}

void DrawWorld(ImDrawList* draw)
{
	if (global.show_world)
	{
		std::vector<RUSTWORLD> cached_resources = global.world_list;
		Vector2 screen_position;

		for (int i = 0; i < cached_resources.size(); i++)
		{
			RUSTWORLD world = cached_resources[i];

			ImColor color;
			bool skip = false;
			/*
				Stash Hash 1696490862
				Elite Crate Hash 697501462
				Military Crate Hash 1907420021
				Crate Hash 1611742587
				AirDrop Hash 1383014174
				Locked Crate Hash 217888051
				Autoturret Hash 155487790
				Flameturret Hash 1730120291
				Shotgun Trap Hash 1562176836
				Corpse Hash 2062577317
			*/

			//Find The World Entities Color And Determine Weather You Need To Skip Or Not
			switch (world.name_hash)
			{
			case 1696490862:
				skip = !global.show_stash;
				color = global.stash_color;
				break;
			case 697501462:
				skip = !global.show_crate_elite;
				color = global.crate_elite_color;
				break;
			case 1907420021:
				skip = !global.show_create_military;
				color = global.crate_military_color;
				break;
			case 1383014174:
				skip = !global.show_airdrop;
				color = global.airdrop_color;
				break;
			case 217888051:
				skip = !global.show_locked_crate;
				color = global.locked_crate_color;
				break;
			case 1611742587:
				skip = !global.show_crate;
				color = global.crate_color;
				break;
			case 155487790:
				skip = !global.show_auto_turret;
				color = global.auto_turret_color;
				break;
			case 1730120291:
				skip = !global.show_flame_turret;
				color = global.flame_turret_color;
				break;
			case 1562176836:
				skip = !global.show_shotgun_trap;
				color = global.shotgun_trap_color;
				break;
			case 2062577317:
				skip = !global.show_corpse;
				color = global.corpse_color;
				break;
			default:
				skip = true;
				break;
			}

			float distance = players.local_position.Distance(world.position);

			if (skip || distance > global.max_world_distance) continue;

			if (camera.WorldToScreen(world.position, screen_position, global.view_matrix))
			{

				std::string world_esp_string = "";
				if (global.show_world_name)
				{
					world_esp_string.append(world.name);
				}
				if (global.show_world_distance)
				{
					world_esp_string.append(" [" + std::to_string((int)distance) + " m]");
				}

				Outline_Text(Vector2(screen_position.x, screen_position.y + 10), world_esp_string, color);
			}
		}
	}
}

void DrawItems(ImDrawList* draw)
{

}

void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness)
{
	float lineW = (W / 3);
	float lineH = (H / 3);

	auto draw = ImGui::GetBackgroundDrawList();

	draw->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	draw->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	draw->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	draw->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	draw->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	draw->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	draw->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	draw->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}

void Outline_Text(Vector2 screen, std::string txt, ImColor color = IM_COL32(255, 255, 255, 255))
{
	auto draw = ImGui::GetBackgroundDrawList();

	ImVec2 fontSize = ImGui::CalcTextSize(txt.c_str(), 0, false, -1.0f);
	draw->AddText(ImVec2(screen.x + 1 - (fontSize.x / 2), screen.y - (fontSize.y / 2)), IM_COL32(0, 0, 0, color.Value.w * 255), txt.c_str());
	draw->AddText(ImVec2(screen.x - 1 - (fontSize.x / 2), screen.y - (fontSize.y / 2)), IM_COL32(0, 0, 0, color.Value.w * 255), txt.c_str());
	draw->AddText(ImVec2(screen.x - (fontSize.x / 2), screen.y + 1 - (fontSize.y / 2)), IM_COL32(0, 0, 0, color.Value.w * 255), txt.c_str());
	draw->AddText(ImVec2(screen.x - (fontSize.x / 2), screen.y - 1 - (fontSize.y / 2)), IM_COL32(0, 0, 0, color.Value.w * 255), txt.c_str());
	draw->AddText(ImVec2(screen.x - (fontSize.x / 2), screen.y - (fontSize.y / 2)), color, txt.c_str());
}