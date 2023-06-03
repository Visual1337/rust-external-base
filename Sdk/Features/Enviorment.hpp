class Enviorment
{
public:

	void TimeChanger()
	{
		if (global.time_changer)
		{
			uintptr_t admin_convar = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.AdminConvar, 0xb8 });
			driver.write<float>(admin_convar + 0x0, global.current_time);
		}
	}

	void ClearWater()
	{
		if (global.clear_water)
		{
			uintptr_t admin_convar = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.AdminConvar, 0xb8 });
			driver.write<bool>(admin_convar + 0x11, false);
		}
	}

	void FovChanger()
	{
		if (global.fov_changer)
		{
			uintptr_t graphics_convar = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.GraphicsConvar, 0xb8});
			driver.write<float>(graphics_convar + 0x18, global.fov);
		}
	}

	void BrightNight()
	{
		if (global.bright_night)
		{
			uintptr_t TOD_Sky = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.TODSky , 0xB8, 0x0, 0x10, 0x20 });
			uintptr_t TOD_NightParameters = driver.read<uintptr_t>(TOD_Sky + 0x58);
			uintptr_t TOD_AmbientParameters = driver.read<uintptr_t>(TOD_Sky + 0x90);
			uintptr_t TOD_StarParameters = driver.read<uintptr_t>(TOD_Sky + 0x70);

			bool is_day = driver.read<bool>(TOD_Sky + 0xB8);
			if (is_day)
			{
				driver.write<float>(TOD_Sky + 0x230, 0.f);
				driver.write<float>(TOD_Sky + 0x234, 0.f);
				driver.write<float>(TOD_NightParameters + 0x48, 30.f);
				driver.write<float>(TOD_NightParameters + 0x50, 30.f);
				driver.write<float>(TOD_StarParameters + 0x14, 500.f);
				driver.write<float>(TOD_AmbientParameters + 0x18, 1000000);
			}
		}

		global.bright_night = false;
	}

	void HandleAutoFarm()
	{
		uintptr_t input_convar = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.ConVarInput, 0xb8 });

		if (!global.auto_farm)
		{
			driver.write<bool>(input_convar + 0x12, false);
			return;
		}

		std::vector<int> white_listed_items = {};

		if (global.auto_farm_stone) white_listed_items.push_back(1696469454);
		if (global.auto_farm_metal) white_listed_items.push_back(1622519874);
		if (global.auto_farm_sulfur) white_listed_items.push_back(1554069420);
		if (global.auto_farm_hemp) white_listed_items.push_back(1082534429);

		global.target_resource = {};

		if (global.find_target == true || global.target_resource.instance == NULL)
		{
			std::vector<RUSTRESOURCE> cached_list = global.resource_list;

			float closest = 9999.0f;
			RUSTRESOURCE target = {};

			for (int i = 0; i < cached_list.size(); i++)
			{
				RUSTRESOURCE resource = cached_list[i];

				for (int j = 0; j < white_listed_items.size(); j++)
				{
					if (resource.name_hash == white_listed_items[j])
					{
						float current_distance = players.local_position.Distance(resource.position);
						if (current_distance < closest)
						{
							closest = current_distance;
							target = resource;
						}
					}
				}
			}
			global.find_target = false;
			global.target_resource = target;
		}

		if (global.find_target == false)
		{
			players.local->GetPlayerInput()->SetAutoRun(true);
			driver.write<bool>(input_convar + 0x12, true);//always sprint

			Vector3 direction = Vector3(players.local_position.x - global.target_resource.position.x, players.local_position.y - global.target_resource.position.y + 1.f, players.local_position.z - global.target_resource.position.z);
			Vector2 angle = Vector2(RAD2DEG(asin(direction.y / direction.Length())), RAD2DEG(-atan2(direction.x, -direction.z)));
			players.local->GetPlayerInput()->SetBodyAngles(Vector3(angle.x, angle.y, 0));

			Vector3 velocity = players.local->GetPlayerModel()->GetNewVelocity();
			velocity = velocity.abs();

			float distance = players.local_position.Distance(global.target_resource.position);
			if (distance <= 3.5f && global.is_focused_window)
			{
				if (distance < 2.0f)
				{
					players.local->GetPlayerInput()->SetAutoRun(false);
				}

				Unity->SetKeyState(KeyCode::Mouse0, true);
				//Sleep(200);

				global.ticks++;
				if (global.ticks >= 100)
				{
					global.find_target = true;
				}
			}
			else if (velocity.x < 1 && velocity.y < 1 && velocity.z < 1 && distance > 3.0f)
			{
				printf("[!] Stuck... Applying Force Jump!\n");

				Unity->SetKeyState(KeyCode::Space, true);
				//Sleep(200);
			}
		}
	}

	void ChamsHandler()
	{
		if (global.apply_chams)
		{
			std::vector<RUSTPLAYER> cached_player_list = global.player_list;

			for (int i = 0; i < cached_player_list.size(); i++)
			{
				RUSTPLAYER player = cached_player_list[i];
				if (player.instance == reinterpret_cast<uintptr_t>(players.local)) continue;

				auto player_model = driver.read<uintptr_t>(player.instance + Offsets::BasePlayer.PlayerModel);
				auto player_skin_type = driver.read<uintptr_t>(player_model + Offsets::PlayerModel.SkinType);
				auto player_skin_component = driver.read<uintptr_t>(player_model + Offsets::PlayerModel.MaleSkin + ((int)player_skin_type * 0x8));
				auto skin = driver.read<uintptr_t>(player_skin_component + 0x18);

				auto skin_sz = driver.read<uintptr_t>(skin + 0x18);
				for (int i = 0; i <= (int)skin_sz; i++)
				{
					auto current_skin = driver.read<uintptr_t>(skin + 0x20 + (i * 0x8));

					driver.write<uintptr_t>(current_skin + 0x68, global.selected_chams_material);
					driver.write<uintptr_t>(current_skin + 0x70, global.selected_chams_material);
					driver.write<uintptr_t>(current_skin + 0x78, global.selected_chams_material);
				}
				driver.write<uintptr_t>(player.instance + 0x530, true);
			}

			auto skinnable_array = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.Skinnable, 0xb8, 0x0 });
			auto size = driver.read<int>(skinnable_array + 0x18);

			for (int i = 0; i < size; i++)
			{
				auto instance = driver.read<uint64_t>(skinnable_array + 0x20 + (i * 0x8)); if (!instance) continue;
				auto catagory = driver.read<int>(instance + 0x58);

				auto list_ptr = driver.read<uint64_t>(instance + 0x60);
				auto skinnable_group_size = driver.read<int>(list_ptr + 0x18);

				if (catagory != 6 && catagory != 7 && catagory != 9)
				{
					for (int j = 0; j < skinnable_group_size; j++)
					{
						auto skinnable_group = driver.read<uint64_t>(list_ptr + 0x20 + (j * 0x8));
						if (!skinnable_group) continue;

						if (global.selected_chams_material)
						{
							driver.write<uint64_t>(driver.read<uint64_t>(skinnable_group + 0x18) + 0x10, driver.read<uint64_t>(global.selected_chams_material + 0x10));
						}
					}
				}
			}
			global.apply_chams = false;
		}
	}
};