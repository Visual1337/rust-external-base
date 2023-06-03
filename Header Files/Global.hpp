class Global
{
public:
	int screen_width = 1920;
	int screen_height = 1080;

	bool is_focused_window = false;
	bool menu = false;
	int current_tab = 1;

	ID3D11ShaderResourceView* Image = nullptr;

	uintptr_t unity_player = NULL;
	uintptr_t game_assembly = NULL;

	uintptr_t all_cameras = NULL;
	uintptr_t camera = NULL;
	matrix4x4 view_matrix;

	/*------Fonts------*/
	ImFont* icons = NULL;
	ImFont* title = NULL;
	ImFont* radar = NULL;
	ImFont* medium = NULL;
	ImFont* large = NULL;

	/*------Cached-Lists------*/
	std::vector<RUSTPLAYER> player_list = {};
	std::vector<RUSTRESOURCE> resource_list = {};
	std::vector<RUSTWORLD> world_list = {};
	std::vector<RUSTITEM> item_list = {};
	std::vector<std::pair<uintptr_t, std::string>> chams_materials = {};

	uintptr_t held_item;

	/*------Aimbot------*/
	bool aimbot_enabled = false;
	bool aimbot_find_key = false;
	int aimbot_key = 0;
	int selected_aimbot_bone = 0;
	BoneList aimbot_bone;
	bool aimbot_ingore_sleepers = false;
	bool aimbot_ignore_npc = false;
	bool draw_fov = false;
	float aimbot_fov = 90.f;
	float max_aimbot_distance = 150.f;

	/*------Weapon------*/
	bool no_recoil = false;
	bool no_spread = false;
	bool force_automatic = false;
	bool instant_eoka = false;
	bool instant_compound = false;

	/*------Misc------*/
	bool spider_man = false;
	bool infinite_jump = false;
	bool no_sway = false;
	bool unlock_angles = false;
	bool fly_hack = false;
	bool fake_admin = false;
	bool fov_changer = false;
	float fov = 90.f;
	bool time_changer = false;
	float current_time = 12.f;
	bool clear_water = false;
	bool bright_night = false;
	bool walk_on_water = false;
	bool fake_duck = false;

	/*------Player-Esp------*/
	bool show_player = true;
	bool show_player_name = false;
	bool show_player_distance = false;
	bool show_player_box = false;
	ImColor player_box_color = ImColor(255, 255, 0, 255);
	ImColor player_name_color = ImColor(255, 255, 255, 255);
	bool player_ignore_npc = false;
	bool player_ignore_sleeping = false;
	float max_player_distance = 500.f;
	bool apply_chams = true;
	int selected_chams_tab = 0;
	uintptr_t selected_chams_material;


	/*------Resource-Esp------*/
	bool show_resource = false;
	bool show_resource_name = false;
	bool show_resource_distance = false;
	float max_resource_distance = 250.f;
	bool show_stone = false;
	bool show_metal = false;
	bool show_sulfur = false;
	bool show_hemp = false;
	ImColor stone_color = ImColor(255, 255, 255, 255);
	ImColor metal_color = ImColor(255, 255, 255, 255);
	ImColor sulfur_color = ImColor(255, 255, 255, 255);
	ImColor hemp_color = ImColor(255, 255, 255, 255);

	/*------World_Esp------*/
	bool show_world = false;
	bool show_world_name = false;
	bool show_world_distance = false;
	float max_world_distance = 100.f;
	bool show_stash = false;
	bool show_crate_elite = false;
	bool show_create_military = false;
	bool show_crate = false;
	bool show_airdrop = false;
	bool show_locked_crate = false;
	bool show_auto_turret = false;
	bool show_flame_turret = false;
	bool show_shotgun_trap = false;
	bool show_corpse = false;
	ImColor stash_color = ImColor(255, 255, 255, 255);
	ImColor crate_elite_color = ImColor(255, 255, 255, 255);
	ImColor crate_military_color = ImColor(255, 255, 255, 255);
	ImColor crate_color = ImColor(255, 255, 255, 255);
	ImColor airdrop_color = ImColor(255, 255, 255, 255);
	ImColor locked_crate_color = ImColor(255, 255, 255, 255);
	ImColor auto_turret_color = ImColor(255, 255, 255, 255);
	ImColor flame_turret_color = ImColor(255, 255, 255, 255);
	ImColor shotgun_trap_color = ImColor(255, 255, 255, 255);
	ImColor corpse_color = ImColor(255, 255, 255, 255);


	/*------Item_Esp------*/
	bool show_item = false;
	bool show_item_name = false;
	bool show_item_distance = false;
	ImColor item_color = ImColor(255, 255, 255, 255);
	float max_item_distance = 50.f;

	/*------Auto-Farm------*/
	bool auto_farm = false;
	bool find_target = true;
	int ticks = 0;
	RUSTRESOURCE target_resource = {};
	int auto_farm_key = 0;
	bool auto_farm_find_key = false;
	bool auto_farm_stone = false;
	bool auto_farm_metal = false;
	bool auto_farm_sulfur = false;
	bool auto_farm_hemp = false;

	/*------Config------*/
	std::string selected_config = "";
	char config_buffer[128];
	bool save_config = false;
	bool load_config = false;

	/*------Drawing-Settings------*/
	bool limit_fps = false;
	bool vsync = false;
	float target_fps = 120.f;
	bool show_debug_text = false;
}global;
