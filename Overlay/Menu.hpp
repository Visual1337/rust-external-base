#define SPACING 25

static const char* aimbot_bones[]{ (" Head"),(" Neck"),(" Chest"),(" Stomach"),(" Left Arm"),(" Left Leg"),(" Right Arm"),(" Right Leg") };


void Menu()
{
    if (global.menu)
    {
        ImGui::SetNextWindowSize(ImVec2(800, 500), NULL);
        ImGui::Begin(_("Rust"), NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground);

        ImVec2 window_position = ImGui::GetWindowPos();
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        draw->AddImage((PVOID)global.Image, ImVec2(window_position.x, window_position.y), ImVec2(window_position.x + 800, window_position.y + 500));

        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(200, 255, 0, 255)));
        ImGui::PushFont(global.title);
        ImGui::TextColored(ImColor(200, 255, 0, 255), _("Rust"));
        ImGui::PopFont();

        ImGui::Dummy(ImVec2(0, SPACING));
        ImGui::TextColored(ImColor(72, 72, 78, 255), _("Weapon"));
        ImGui::PushFont(global.medium);
        //if (ImGui::TabButton(_("Wepons"), ImVec2(160, 30), 1, global.current_tab, global.icons, AIMBOT_ICON)) global.current_tab = 1;
        if (ImGui::TabButton(_("Weapon"), ImVec2(160, 30), 2, global.current_tab, global.icons, AK_ICON)) global.current_tab = 2;
        ImGui::PopFont();

        ImGui::Dummy(ImVec2(0, SPACING));
        ImGui::TextColored(ImColor(72, 72, 78, 255), _("Visuals"));
        ImGui::PushFont(global.medium);
        if (ImGui::TabButton(_("Player"), ImVec2(160, 30), 3, global.current_tab, global.icons, PLAYER_ICON)) global.current_tab = 3;
        if (ImGui::TabButton(_("Resource"), ImVec2(160, 30), 4, global.current_tab, global.icons, LOOT_ICON)) global.current_tab = 4;
        if (ImGui::TabButton(_("Item"), ImVec2(160, 30), 5, global.current_tab, global.icons, EXIT_ICON)) global.current_tab = 5;
        ImGui::PopFont();

        ImGui::Dummy(ImVec2(0, SPACING));
        ImGui::TextColored(ImColor(72, 72, 78, 255), _("World"));
        ImGui::PushFont(global.medium);
        if (ImGui::TabButton(_("Misc"), ImVec2(160, 30), 6, global.current_tab, global.icons, MOVEMENT_ICON)) global.current_tab = 6;
        ImGui::PopFont();

        ImGui::Dummy(ImVec2(0, SPACING));
        ImGui::TextColored(ImColor(72, 72, 78, 255), _("Misc"));
        ImGui::PushFont(global.medium);
        if (ImGui::TabButton(_("Config"), ImVec2(160, 30), 7, global.current_tab, global.icons, SETTINGS_ICON)) global.current_tab = 7;
        ImGui::PopFont();

        ImGui::Dummy(ImVec2(0, SPACING));

        //draw->AddCircleFilled(ImVec2(window_position.x + 25, window_position.y + 465), 20, ImColor(0, 168, 243), 64);
        ImGui::Dummy(ImVec2(40, 0));
        ImGui::SameLine();
        //ImGui::TextColored(ImColor(72, 72, 78, 255), "Error");
        ImGui::Dummy(ImVec2(40, 0));
        ImGui::SameLine();
       // ImGui::TextColored(ImColor(72, 72, 78, 255), "Error");
        ImGui::PopStyleColor();

        switch (global.current_tab)
        {
        case 1:
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 190, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Aimbot_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("Enabled"), &global.aimbot_enabled);
                ImGui::KeyBind(_("Aimbot Key     "), ImVec2(250, 30), global.aimbot_key, global.aimbot_find_key);
                ImGui::Combo(_("Bone"), &global.selected_aimbot_bone, aimbot_bones, IM_ARRAYSIZE(aimbot_bones));
                ImGui::Checkbox2(_("Ignore Npc"), &global.aimbot_ignore_npc);
                ImGui::Checkbox2(_("Ignore Sleeper"), &global.aimbot_ingore_sleepers);
                ImGui::Checkbox2(_("Draw Fov"), &global.draw_fov);
                if (global.draw_fov)
                {
                    ImGui::SliderFloatCustom(_("Fov"), &global.aimbot_fov, 0.f, 1000.f);
                }
                ImGui::SliderFloatCustom(_("Max Distance"), &global.max_aimbot_distance, 0.f, 500.f);
            }
            ImGui::EndChild();
            break;
        case 2:
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 190, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Weapon_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("No Recoil"), &global.no_recoil);
                ImGui::Checkbox2(_("No Spread"), &global.no_spread);
               // ImGui::Checkbox2(_("Force Automatic"), &global.force_automatic);
                //ImGui::Checkbox2(_("Instant Eoka"), &global.instant_eoka);
                //ImGui::Checkbox2(_("Instant Compound"), &global.instant_compound);
            }
            ImGui::EndChild();
            break;
        case 3:
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 190, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Player_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("Enabled"), &global.show_player);
                ImGui::Checkbox2(_("Name"), &global.show_player_name);
                ImGui::Checkbox2(_("Distance"), &global.show_player_distance);
                ImGui::Checkbox2(_("Box"), &global.show_player_box);
                ImGui::Checkbox2(_("Hide Npc"), &global.player_ignore_npc);
                ImGui::Checkbox2(_("Hide Sleeping"), &global.player_ignore_sleeping);
                ImGui::ColorPicker(_("Box Color"), &global.player_box_color);
                ImGui::ColorPicker(_("Name Color"), &global.player_name_color);
                ImGui::SliderFloatCustom(_("Max Distance"), &global.max_player_distance, 0.f, 1000.f);
            }
            ImGui::EndChild();
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 500, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Chams_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                if (ImGui::Button(_("Apply Chams"), ImVec2(230, 30)))
                {
                    global.apply_chams = true;
                }
                ImGui::Dummy(ImVec2(0, 5));
                ImGui::BeginChild(_("##Chams_Selection"), ImVec2(230, 300), true, NULL);
                {
                    for (int i = 0; i < global.chams_materials.size(); i++)
                    {
                        if (ImGui::TabButton(global.chams_materials[i].second.c_str(), ImVec2(200, 30), i, global.selected_chams_tab, global.icons, PAPER_ICON))
                        {
                            global.selected_chams_tab = i;
                            global.selected_chams_material = global.chams_materials[i].first;
                        }
                    }
                }
                ImGui::EndChild();
            }
            ImGui::EndChild();
            break;
        case 4:
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 190, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Resource_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("Enabled"), &global.show_resource);
                ImGui::Checkbox2(_("Name"), &global.show_resource_name);
                ImGui::Checkbox2(_("Distance"), &global.show_resource_distance);
                ImGui::Checkbox2(_("Show Stone"), &global.show_stone);
                ImGui::Checkbox2(_("Show Metal"), &global.show_metal);
                ImGui::Checkbox2(_("Show Sulur"), &global.show_sulfur);
                ImGui::Checkbox2(_("Show Hemp"), &global.show_hemp);
                ImGui::ColorPicker(_("Stone Color"), &global.stone_color);
                ImGui::ColorPicker(_("Metal Color"), &global.metal_color);
                ImGui::ColorPicker(_("Sulfur Color"), &global.sulfur_color);
                ImGui::ColorPicker(_("Hemp Color"), &global.hemp_color);
                ImGui::SliderFloatCustom(_("Max Distance"), &global.max_resource_distance, 0.f, 500.f);
            }
            ImGui::EndChild();
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 500, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Item_Esp"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("Enabled"), &global.show_item);
                ImGui::Checkbox2(_("Name"), &global.show_item_name);
                ImGui::Checkbox2(_("Distance"), &global.show_item_distance);
                ImGui::ColorPicker(_("Item Color"), &global.item_color);
                ImGui::SliderFloatCustom(_("Max Distance"), &global.max_item_distance, 0.f, 250.f);
            }
            ImGui::EndChild();
            break;
        case 5:
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 190, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##World_Esp"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("Enabled"), &global.show_world);
                ImGui::Checkbox2(_("Name"), &global.show_world_name);
                ImGui::Checkbox2(_("Distance"), &global.show_world_distance);
                ImGui::SliderFloatCustom(_("Max Distance"), &global.max_world_distance, 0.f, 250.f);

                ImGui::Checkbox2(_("Show Stash"), &global.show_stash);
                ImGui::Checkbox2(_("Show Elite Crate"), &global.show_crate_elite);
                ImGui::Checkbox2(_("Show Military Crate"), &global.show_create_military);
                ImGui::Checkbox2(_("Show Crate"), &global.show_crate);
                ImGui::Checkbox2(_("Show Airdrop"), &global.show_airdrop);
                ImGui::Checkbox2(_("Show Locked Crate"), &global.show_locked_crate);
                ImGui::Checkbox2(_("Show Auto-Turret"), &global.show_auto_turret);
                ImGui::Checkbox2(_("Show Flame-Turret"), &global.show_flame_turret);
                ImGui::Checkbox2(_("Show Shotgun-Trap"), &global.show_shotgun_trap);
                ImGui::Checkbox2(_("Show Corpse"), &global.show_corpse);
            }
            ImGui::EndChild();
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 500, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##World_Color_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::ColorPicker(_("Stash Color"), &global.stash_color);
                ImGui::ColorPicker(_("Elite Crate Color"), &global.crate_elite_color);
                ImGui::ColorPicker(_("Military Crate Color"), &global.crate_military_color);
                ImGui::ColorPicker(_("Crate Color"), &global.crate_color);
                ImGui::ColorPicker(_("Airdrop Color"), &global.airdrop_color);
                ImGui::ColorPicker(_("Locked Crate Color"), &global.locked_crate_color);
                ImGui::ColorPicker(_("Auto-Turret Color"), &global.auto_turret_color);
                ImGui::ColorPicker(_("Flame-Turret Color"), &global.flame_turret_color);
                ImGui::ColorPicker(_("Shotgun-Trap Color"), &global.shotgun_trap_color);
                ImGui::ColorPicker(_("Corpse Color"), &global.corpse_color);
            }
            ImGui::EndChild();
            break;
        case 6:
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 190, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Movement_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("SpiderMan"), &global.spider_man);
                //ImGui::Checkbox2(_("Infinite Jump"), &global.infinite_jump);
               // ImGui::Checkbox2(_("No Sway"), &global.no_sway);
               // ImGui::Checkbox2(_("Unlock Angles"), &global.unlock_angles);
                ImGui::Checkbox2(_("Fake Admin"), &global.fake_admin);
                //ImGui::Checkbox2(_("Clear Water"), &global.clear_water);
                //ImGui::Checkbox2(_("Walk On Water"), &global.walk_on_water);
                //ImGui::Checkbox2(_("Fake Duck"), &global.fake_duck);
                ImGui::Checkbox2(_("Fov Changer"), &global.fov_changer);
                if (global.fov_changer)
                {
                    ImGui::SliderFloatCustom(_("Fov"), &global.fov, 0, 180);//fix
                }

                ImGui::Checkbox2(_("Time Changer"), &global.time_changer);
                if (global.time_changer)
                {
                    ImGui::SliderFloatCustom(_("Time"), &global.current_time, -1, 24);
                }
                ImGui::Dummy(ImVec2(5, 5));
                if (ImGui::Button("Bright Night", ImVec2(150, 30)))
                {
                    global.bright_night = true;
                }
            }
            ImGui::EndChild();
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 500, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Auto_Farm"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("AutoFarm"), &global.auto_farm);
                ImGui::KeyBind(_("Farm Keybind   "), ImVec2(250, 30), global.auto_farm_key, global.auto_farm_find_key);

                ImGui::Checkbox2(_("Stone"), &global.auto_farm_stone);
                ImGui::Checkbox2(_("Metal"), &global.auto_farm_metal);
                ImGui::Checkbox2(_("Sulfur"), &global.auto_farm_sulfur);
                ImGui::Checkbox2(_("Hemp"), &global.auto_farm_hemp);
            }
            ImGui::EndChild();
            break;
        case 7:
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 190, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Config_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                if (ImGui::Button(_("Load"), ImVec2(54, 25)))
                {
                    global.load_config = true;
                }
                ImGui::SameLine();
                if (ImGui::Button(_("Save"), ImVec2(54, 25)))
                {
                    global.save_config = true;
                }
                ImGui::SameLine();
                if (ImGui::Button(_("Create"), ImVec2(54, 25)))
                {
                    std::ofstream file;
                    std::string name = std::string(std::string(getenv(_("APPDATA")) + std::string(_("\\Amplitude-Rust\\Configs\\")) + std::string(global.config_buffer) + std::string(_(".json"))));
                    file.open(name);
                }
                ImGui::SameLine();
                if (ImGui::Button(_("Remove"), ImVec2(54, 25)))
                {
                    remove(global.selected_config.c_str());
                }
                ImGui::SetNextItemWidth(230);
                ImGui::InputText(_(" "), global.config_buffer, 255);
                ImGui::Dummy(ImVec2(0, 5));
                ImGui::BeginChild(_("##Config2_Tab"), ImVec2(230, 300), true, NULL);
                {
                    int i = 0;
                    for (const auto& entry : std::filesystem::directory_iterator(std::string(getenv(_("APPDATA")) + std::string(_("\\Amplitude-Rust\\Configs")))))
                    {
                        if (ImGui::TabButton(Utils::GetBasePath(entry.path().string()).c_str(), ImVec2(200, 30), Utils::StringToInt(entry.path().string()), Utils::StringToInt(global.selected_config), global.icons, PAPER_ICON))
                        {
                            global.selected_config = entry.path().string();
                        }
                        i++;
                    }
                }
                ImGui::EndChild();
            }
            ImGui::EndChild();
            ImGui::SetNextWindowPos(ImVec2(window_position.x + 500, window_position.y + 60), NULL);
            ImGui::BeginChild(_("##Player2_Tab"), ImVec2(250, 370), false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            {
                ImGui::Checkbox2(_("Vsync"), &global.vsync);
                ImGui::Checkbox2(_("Limit Fps"), &global.limit_fps);
                ImGui::SliderFloatCustom(_("Target Fps"), &global.target_fps, 0, 250);
                ImGui::Checkbox2(_("Debug Fps"), &global.show_debug_text);
            }
            ImGui::EndChild();
            break;
        }

        ImGui::End();
    }
}