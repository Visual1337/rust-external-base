#include "Includes.hpp"

int UpdateLists()
{
	std::mutex thread_lock;
	thread_lock.lock();

	printf("[+] Thread 1 Started\n");
	while (true)
	{
		World* world = driver.read<World*>(global.game_assembly + Offsets::GameAssembly.BaseGameMode);

		global.camera = camera.GetMainCamera();

		AllList full_list = world->GetFullList();

		global.player_list = full_list.player;
		global.resource_list = full_list.resource;
		global.world_list = full_list.world;
		global.item_list = full_list.item;

		global.chams_materials = world->GetChamsMaterials();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	thread_lock.unlock();
	return -1;
}

int UpdatePositions()
{
	std::mutex thread_lock;
	thread_lock.lock();
	printf("[+] Thread 2 Started\n");

	while (true)
	{
		//global.view_matrix = driver.read<matrix4x4>(global.camera + Offsets::Camera.ViewMatrix2);
		players.local_position = driver.read<Vector3>(players.local_position_ptr + 0x90);

		if (GetAsyncKeyState(global.auto_farm_key) & 1)
		{
			global.auto_farm = !global.auto_farm;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	thread_lock.unlock();
	return -1;
}