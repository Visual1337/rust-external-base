#include "Includes.hpp"

int Misc()
{
    std::mutex thread_lock;
    thread_lock.lock();

    printf("[+] Thread 4 Started\n");
    while (true)
    {
        Movement* movement = reinterpret_cast<Movement*>(players.local);
        Enviorment* enviorment = reinterpret_cast<Enviorment*>(players.local);

        weapon->WeaponHandler();

        movement->SpiderMan();
        movement->InfiniteJump();
        movement->NoSway();
        movement->UnlockAngles();
        movement->FakeAdmin();
        movement->FakeDuck();
        movement->ShootWhileMounted();
        Unity->IgnoreLayer(Layer::PlayerMovement, Layer::Water, global.walk_on_water);


        enviorment->ClearWater();
        enviorment->TimeChanger();
        enviorment->FovChanger();
        enviorment->BrightNight();
        enviorment->HandleAutoFarm();
        enviorment->ChamsHandler();

        try
        {
            if (global.save_config)
            {
                nlohmann::json json;

                /*------Aimbot------*/
                json[_("AimbotEnabled")] = global.aimbot_enabled;
                json[_("AimbotKey")] = global.aimbot_key;
                json[_("SelectedAimbotBone")] = global.selected_aimbot_bone;
                json[_("AimbotBone")] = global.aimbot_bone;
                json[_("AimbotIngoreSleepers")] = global.aimbot_ingore_sleepers;
                json[_("AimbotIgnoreNpc")] = global.aimbot_ignore_npc;
                json[_("DrawFov")] = global.draw_fov;
                json[_("AimbotFov")] = global.aimbot_fov;
                json[_("MaxAimbotDistance")] = global.max_aimbot_distance;

                /*------Weapon------*/
                json[_("NoRecoil")] = global.no_recoil;
                json[_("NoSpread")] = global.no_spread;
                json[_("ForceAutomatic")] = global.force_automatic;
                json[_("InstantEoka")] = global.instant_eoka;
                json[_("InstantCompound")] = global.instant_compound;

                /*------Movement------*/
                json[_("SpiderMan")] = global.spider_man;
                json[_("InfiniteJump")] = global.infinite_jump;
                json[_("NoSway")] = global.no_sway;
                json[_("UnlockAngles")] = global.unlock_angles;
                json[_("FlyHack")] = global.fly_hack;
                json[_("FakeAdmin")] = global.fake_admin;
                json[_("FovChanger")] = global.fov_changer;
                json[_("Fov")] = global.fov;
                json[_("TimeChanger")] = global.time_changer;
                json[_("Current_time")] = global.current_time;
                json[_("ClearWater")] = global.clear_water;
                json[_("BrightNight")] = global.bright_night;

                /*------Player-Esp------*/
                json[_("ShowPlayer")] = global.show_player;
                json[_("ShowPlayerName")] = global.show_player_name;
                json[_("ShowPlayerDistance")] = global.show_player_distance;
                json[_("ShowPlayerBox")] = global.show_player_box;
                json[_("PlayerBoxColor")] = (uintptr_t)global.player_box_color;
                json[_("PlayerNameColor")] = (uintptr_t)global.player_name_color;
                json[_("PlayerIgnoreNpc")] = global.player_ignore_npc;
                json[_("PlayerIgnoreSleeping")] = global.player_ignore_sleeping;
                json[_("MaxPlayerDistance")] = global.max_player_distance;

                /*------Resource-Esp------*/
                json[_("ShowResource")] = global.show_resource;
                json[_("ShowResourceName")] = global.show_resource_name;
                json[_("ShowResourceDistance")] = global.show_resource_distance;
                json[_("MaxResourceDistance")] = global.max_resource_distance;
                json[_("ShowStone")] = global.show_stone;
                json[_("ShowMetal")] = global.show_metal;
                json[_("ShowSulfur")] = global.show_sulfur;
                json[_("ShowHemp")] = global.show_hemp;
                json[_("StoneColor")] = (uintptr_t)global.stone_color;
                json[_("MetalColor")] = (uintptr_t)global.metal_color;
                json[_("SulfurColor")] = (uintptr_t)global.sulfur_color;
                json[_("HempColor")] = (uintptr_t)global.hemp_color;

                /*------World_Esp------*/
                json[_("show_world")] = global.show_world;
                json[_("show_world_name")] = global.show_world_name;
                json[_("show_world_distance")] = global.show_world_distance;
                json[_("max_world_distance")] = global.max_world_distance;
                json[_("show_stash")] = global.show_stash;
                json[_("show_crate_elite")] = global.show_crate_elite;
                json[_("show_create_military")] = global.show_create_military;
                json[_("show_crate")] = global.show_crate;
                json[_("show_airdrop")] = global.show_airdrop;
                json[_("show_locked_crate")] = global.show_locked_crate;
                json[_("show_auto_turret")] = global.show_auto_turret;
                json[_("show_flame_turret")] = global.show_flame_turret;
                json[_("show_shotgun_trap")] = global.show_shotgun_trap;
                json[_("show_corpse")] = global.show_corpse;
                json[_("stash_color")] = (uintptr_t)global.stash_color;
                json[_("crate_elite_color")] = (uintptr_t)global.crate_elite_color;
                json[_("crate_military_color")] = (uintptr_t)global.crate_military_color;
                json[_("crate_color")] = (uintptr_t)global.crate_color;
                json[_("airdrop_color")] = (uintptr_t)global.airdrop_color;
                json[_("locked_crate_color")] = (uintptr_t)global.locked_crate_color;
                json[_("auto_turret_color")] = (uintptr_t)global.auto_turret_color;
                json[_("flame_turret_color")] = (uintptr_t)global.flame_turret_color;
                json[_("shotgun_trap_color")] = (uintptr_t)global.shotgun_trap_color;
                json[_("corpse_color")] = (uintptr_t)global.corpse_color;

                /*------Item_Esp------*/
                json[_("show_item")] = global.show_item;
                json[_("show_item_name")] = global.show_item_name;
                json[_("show_item_distance")] = global.show_item_distance;
                json[_("item_color")] = (uintptr_t)global.item_color;
                json[_("max_item_distance")] = global.max_item_distance;

                /*------Auto-Farm------*/
                json[_("auto_farm")] = global.auto_farm;
                json[_("auto_farm_key")] = global.auto_farm_key;
                json[_("auto_farm_stone")] = global.auto_farm_stone;
                json[_("auto_farm_metal")] = global.auto_farm_metal;
                json[_("auto_farm_sulfur")] = global.auto_farm_sulfur;
                json[_("auto_farm_hemp")] = global.auto_farm_hemp;

                /*-----Settings-----*/
                json[_("Vsync")] = global.vsync;
                json[_("LimitFps")] = global.limit_fps;
                json[_("TargetFps")] = global.target_fps;

                std::ofstream out(global.selected_config);
                out << std::setw(4) << json << std::endl;
                out.close();

                global.save_config = false;
            }

            if (global.load_config)
            {
                if (global.selected_config == "")
                {
                    printf("Failed\n");
                    global.load_config = false;
                    continue;
                }

                std::ifstream ifstreammm(global.selected_config);
                nlohmann::json json_data = nlohmann::json::parse(ifstreammm);

                uintptr_t color;

                /*------Aimbot------*/
                json_data[_("AimbotEnabled")].get_to(global.aimbot_enabled);
                json_data[_("AimbotKey")].get_to(global.aimbot_key);
                json_data[_("SelectedAimbotBone")].get_to(global.selected_aimbot_bone);
                json_data[_("AimbotBone")].get_to(global.aimbot_bone);
                json_data[_("AimbotIngoreSleepers")].get_to(global.aimbot_ingore_sleepers);
                json_data[_("AimbotIgnoreNpc")].get_to(global.aimbot_ignore_npc);
                json_data[_("DrawFov")].get_to(global.draw_fov);
                json_data[_("AimbotFov")].get_to(global.aimbot_fov);
                json_data[_("MaxAimbotDistance")].get_to(global.max_aimbot_distance);

                /*------Weapon------*/
                json_data[_("NoRecoil")].get_to(global.no_recoil);
                json_data[_("NoSpread")].get_to(global.no_spread);
                json_data[_("ForceAutomatic")].get_to(global.force_automatic);
                json_data[_("InstantEoka")].get_to(global.instant_eoka);
                json_data[_("InstantCompound")].get_to(global.instant_compound);

                /*------Misc------*/
                json_data[_("SpiderMan")].get_to(global.spider_man);
                json_data[_("InfiniteJump")].get_to(global.infinite_jump);
                json_data[_("NoSway")].get_to(global.no_sway);
                json_data[_("UnlockAngles")].get_to(global.unlock_angles);
                json_data[_("FlyHack")].get_to(global.fly_hack);
                json_data[_("FakeAdmin")].get_to(global.fake_admin);
                json_data[_("FovChanger")].get_to(global.fov_changer);
                json_data[_("Fov")].get_to(global.fov);
                json_data[_("TimeChanger")].get_to(global.time_changer);
                json_data[_("Current_time")].get_to(global.current_time);
                json_data[_("ClearWater")].get_to(global.clear_water);
                json_data[_("BrightNight")].get_to(global.bright_night);

                /*------Player-Esp------*/
                json_data[_("ShowPlayer")].get_to(global.show_player);
                json_data[_("ShowPlayerName")].get_to(global.show_player_name);
                json_data[_("ShowPlayerDistance")].get_to(global.show_player_distance);
                json_data[_("ShowPlayerBox")].get_to(global.show_player_box);
                json_data[_("PlayerBoxColor")].get_to(color); global.player_box_color = (ImColor)color;
                json_data[_("PlayerNameColor")].get_to(color); global.player_name_color = (ImColor)color;
                json_data[_("PlayerIgnoreNpc")].get_to(global.player_ignore_npc);
                json_data[_("PlayerIgnoreSleeping")].get_to(global.player_ignore_sleeping);
                json_data[_("MaxPlayerDistance")].get_to(global.max_player_distance);

                /*------Resource-Esp------*/
                json_data[_("ShowResource")].get_to(global.show_resource);
                json_data[_("ShowResourceName")].get_to(global.show_resource_name);
                json_data[_("ShowResourceDistance")].get_to(global.show_resource_distance);
                json_data[_("MaxResourceDistance")].get_to(global.max_resource_distance);
                json_data[_("ShowStone")].get_to(global.show_stone);
                json_data[_("ShowMetal")].get_to(global.show_metal);
                json_data[_("ShowSulfur")].get_to(global.show_sulfur);
                json_data[_("ShowHemp")].get_to(global.show_hemp);
                json_data[_("StoneColor")].get_to(color); global.stone_color = (ImColor)color;
                json_data[_("MetalColor")].get_to(color); global.metal_color = (ImColor)color;
                json_data[_("SulfurColor")].get_to(color); global.sulfur_color = (ImColor)color;
                json_data[_("HempColor")].get_to(color); global.hemp_color = (ImColor)color;

                /*------World_Esp------*/
                json_data[_("show_world")].get_to(global.show_world);
                json_data[_("show_world_name")].get_to(global.show_world_name);
                json_data[_("show_world_distance")].get_to(global.show_world_distance);
                json_data[_("max_world_distance")].get_to(global.max_world_distance);
                json_data[_("show_stash")].get_to(global.show_stash);
                json_data[_("show_crate_elite")].get_to(global.show_crate_elite);
                json_data[_("show_create_military")].get_to(global.show_create_military);
                json_data[_("show_crate")].get_to(global.show_crate);
                json_data[_("show_airdrop")].get_to(global.show_airdrop);
                json_data[_("show_locked_crate")].get_to(global.show_locked_crate);
                json_data[_("show_auto_turret")].get_to(global.show_auto_turret);
                json_data[_("show_flame_turret")].get_to(global.show_flame_turret);
                json_data[_("show_shotgun_trap")].get_to(global.show_shotgun_trap);
                json_data[_("show_corpse")].get_to(global.show_corpse);
                json_data[_("stash_color")].get_to(color); global.stash_color = (ImColor)color;
                json_data[_("crate_elite_color")].get_to(color); global.crate_elite_color = (ImColor)color;
                json_data[_("crate_military_color")].get_to(color); global.crate_military_color = (ImColor)color;
                json_data[_("crate_color")].get_to(color); global.crate_color = (ImColor)color;
                json_data[_("airdrop_color")].get_to(color); global.airdrop_color = (ImColor)color;
                json_data[_("locked_crate_color")].get_to(color); global.locked_crate_color = (ImColor)color;
                json_data[_("auto_turret_color")].get_to(color); global.auto_turret_color = (ImColor)color;
                json_data[_("flame_turret_color")].get_to(color); global.flame_turret_color = (ImColor)color;
                json_data[_("shotgun_trap_color")].get_to(color); global.shotgun_trap_color = (ImColor)color;
                json_data[_("corpse_color")].get_to(color); global.corpse_color = (ImColor)color;

                /*------Item_Esp------*/
                json_data[_("show_item")].get_to(global.show_item);
                json_data[_("show_item_name")].get_to(global.show_item_name);
                json_data[_("show_item_distance")].get_to(global.show_item_distance);
                json_data[_("item_color")].get_to(color); global.item_color = (ImColor)color;
                json_data[_("max_item_distance")].get_to(global.max_item_distance);

                /*------Auto-Farm------*/
                json_data[_("auto_farm")].get_to(global.auto_farm);
                json_data[_("auto_farm_key")].get_to(global.auto_farm_key);
                json_data[_("auto_farm_stone")].get_to(global.auto_farm_stone);
                json_data[_("auto_farm_metal")].get_to(global.auto_farm_metal);
                json_data[_("auto_farm_sulfur")].get_to(global.auto_farm_sulfur);
                json_data[_("auto_farm_hemp")].get_to(global.auto_farm_hemp);

                /*-----Settings-----*/
                json_data[_("Vsync")].get_to(global.vsync);
                json_data[_("LimitFps")].get_to(global.limit_fps);
                json_data[_("TargetFps")].get_to(global.target_fps);

                global.load_config = false;
            }
        }
        catch (...)
        {

        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    thread_lock.unlock();
    return -1;
}