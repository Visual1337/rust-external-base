enum class ListType : int
{
	Player,
	Resource,
	World,
	Item
};

std::vector<std::pair<std::string, std::pair<std::string, ListType>>> name_list =
{
	{"player.prefab", std::make_pair("Player", ListType::Player)},
	{"patrolhelicopter", std::make_pair("Scientist", ListType::Player)},
	{"ch47scientist.entity", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_cargo", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_cargo_turret_any", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_cargo_turret_lr300", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_ch47_gunner", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_excavator", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_full_any", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_full_lr300", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_full_mp5", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_full_pistol", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_full_shotgun", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_heavy", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_junkpile_pistol", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_oilrig", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_patrol", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_roam", std::make_pair("Scientist", ListType::Player)},
	{"scientistnpc_roamthered", std::make_pair("Scientist", ListType::Player)},
	{"npc_tunneldweller", std::make_pair("Dweller", ListType::Player)},
	{"npc_underwaterdweller", std::make_pair("Dweller", ListType::Player)},
	{"stone-ore", std::make_pair("Stone", ListType::Resource)},
	{"sulfur-ore", std::make_pair("Sulfur", ListType::Resource)},
	{"metal-ore", std::make_pair("Metal", ListType::Resource)},
	{"hemp", std::make_pair("Hemp", ListType::Resource)},
	{"small_stash_deployed.prefab", std::make_pair("Stash", ListType::World)},
	{"crate_elite.prefab", std::make_pair("Elite Crate", ListType::World)},
	{"crate_normal.prefab", std::make_pair("Military Crate", ListType::World)},
	{"crate_normal_2.prefab", std::make_pair("Crate", ListType::World)},
	{"supply_drop", std::make_pair("AirDrop", ListType::World)},
	{"codelockedhackablecrate", std::make_pair("Locked Crate", ListType::World)},
	{"autoturret_deployed.prefab", std::make_pair("Autoturret", ListType::World)},
	{"flameturret.deployed.prefab", std::make_pair("Flameturret", ListType::World)},
	{"guntrap.deployed.prefab", std::make_pair("Shotgun Trap", ListType::World)},
	{"player_corpse.prefab", std::make_pair("Corpse", ListType::World)},
	{"item_drop_backpack.prefab", std::make_pair("Corpse", ListType::World)},
	{"(world)", std::make_pair("Droped Item", ListType::Item)}
};

struct AllList
{
	std::vector<RUSTPLAYER> player;
	std::vector<RUSTRESOURCE> resource;
	std::vector<RUSTWORLD> world;
	std::vector<RUSTITEM> item;
};

class World
{
public:
	AllList GetFullList()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return {};

		AllList list;

		//auto main_offsets = driver.read<uintptr_t>(global.game_assembly + 0x2F921F8); // System_Collections_Generic_List_BaseGameMode__c
		//uintptr_t list_ptr = driver.ReadChain<uintptr_t>(main_offsets, { 0xB8, 0x8, 0x28 });
		//
		//int size = driver.read<int>(list_ptr + 0x10);
		//uintptr_t base = driver.read<uintptr_t>(list_ptr + 0x18);

		auto BaseGameMode__c = driver.read<uintptr_t>(driver.read<uintptr_t>(global.game_assembly + 0x2F921F8) + 0xB8); //System_Collections_Generic_List_BaseGameMode__c
		auto entity_realm_client = driver.read<uintptr_t>(BaseGameMode__c + 0x10);
		auto client_entities = driver.read<uintptr_t>(driver.read<uintptr_t>(entity_realm_client + 0x10) + 0x28);
		auto EntityCount = driver.read<int>(client_entities + 0x10);
		auto EntityBuffer = driver.read<uintptr_t>(client_entities + 0x18);

		char buffer[256];

		for (int i = 0; i < EntityCount; i++)
		{
			uintptr_t instance = driver.read<uintptr_t>(EntityBuffer + 0x20 + (i * 0x8));
			uintptr_t name_ptr = driver.ReadChain<uintptr_t>(instance, { 0x10, 0x30, 0x60 });
			driver.readEx(name_ptr, (ULONG64)buffer, 128);

			//printf("name | %i it | total %i| %s\n", i, size, buffer);

			for (int j = 0; j < name_list.size(); j++)
			{
				if (strstr(buffer, "LocalPlayer"))
				{
					//printf("local player %p\n", instance);
					players.local = reinterpret_cast<BasePlayer*>(instance);
					players.local_position_ptr = players.local->GetPositionPointer();
				}
				if (strstr(buffer, name_list[j].first.c_str()))
				{
					switch (name_list[j].second.second)
					{
					case ListType::Player:
					{
						BasePlayer* base_player = reinterpret_cast<BasePlayer*>(instance);

						RUSTPLAYER player;
						player.instance = instance;
						player.name = base_player->GetName();
						player.name_hash = Utils::HashString(player.name);
						player.orgin_ptr = base_player->GetPositionPointer();
						player.is_npc = base_player->GetPlayerModel()->GetIsNpc();

						int flags = base_player->GetModelState()->GetModelStateFlags();
						if ((flags & 8) == static_cast<int32_t>(8)/* || (flags == 8)*/)
						{
							player.is_sleeping = true;
						}

						player.health_info = base_player->GetHealthInformation();

						list.player.push_back(player);
						break;
					}
					case ListType::Resource:
					{
						RUSTRESOURCE resource;

						//Finds the pointer to the instance of the resource
						resource.instance = instance;
						//Gets cleaned name from name list
						resource.name = name_list[j].second.first;
						//Hashes the name for comparision later
						resource.name_hash = Utils::HashString(resource.name);
						//Saves the pointer to the position sp you can read 0x90 into it later to get updated position
						resource.position_ptr = driver.ReadChain<uintptr_t>(resource.instance, { { 0x10, 0x30, 0x30, 0x8, 0x38 } });
						//Cached position to save on reads
						resource.position = driver.read<Vector3>(resource.position_ptr + 0x90);
						list.resource.push_back(resource);
						break;
					}
					case ListType::World:
					{
						RUSTWORLD world;
						world.instance = instance;
						world.name = name_list[j].second.first;
						world.name_hash = Utils::HashString(world.name);
						//world.position = driver.read<Vector3>(world.instance, { { 0x10, 0x30, 0x30, 0x8, 0x38, 0x90 } });

						uintptr_t position_ptr = driver.ReadChain<uintptr_t>(world.instance, { { 0x10, 0x30, 0x30, 0x8, 0x38 } });
						//Cached position to save on reads
						world.position = driver.read<Vector3>(position_ptr + 0x90);

						

						list.world.push_back(world);
						break;
					}
					case ListType::Item:
					{
						RUSTITEM item;
						item.instance = instance;
						item.name = name_list[j].second.first;
						item.name_hash = Utils::HashString(item.name);
						//item.position = driver.read(item.instance, { { 0x10, 0x30, 0x30, 0x8, 0x38, 0x90 } });

						uintptr_t position_ptr = driver.ReadChain<uintptr_t>(item.instance, { { 0x10, 0x30, 0x30, 0x8, 0x38 } });
						//Cached position to save on reads
						item.position = driver.read<Vector3>(position_ptr + 0x90);


						list.item.push_back(item);
						break;
					}
					default:
						break;
					}
				}
			}
			//std::this_thread::sleep_for(std::chrono::nanoseconds(1));
		}
		return list;
	}

	std::vector<std::pair<uintptr_t, std::string>> GetChamsMaterials()
	{
		std::vector<std::pair<uintptr_t, std::string>> result;

		result.push_back(std::make_pair(NULL, "NULL"));//Null cham material

		uintptr_t tod_scattering = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.TODSky, 0xB8, 0x0, 0x10, 0x20, 0xa8, 0x1a0 });

		//Other Materials Located At 0x78, 0x80, 0x88
		result.push_back(std::make_pair(driver.read<uintptr_t>(tod_scattering + 0x78), "White ZTest"));//White Wall Material

		result.push_back(std::make_pair(driver.read<uintptr_t>(tod_scattering + 0x88), "Black ZTest"));//Black Wall Material

		result.push_back(std::make_pair(driver.ReadChain<uintptr_t>(global.game_assembly, { 0x35D6568, 0xb8, 0x0}), "Reflective"));//OutlineManager_c  /* reflective (invisible) */

		result.push_back(std::make_pair(driver.ReadChain<uintptr_t>(global.game_assembly, { 0x3622188, 0xb8, 0x0 }), "White"));//UnityEngine_UI_Graphic_c White Material

		return result;
	}
};
