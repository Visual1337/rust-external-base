#include "Includes.hpp"

Vector2 CalculateAngle(const Vector3& player, const Vector3& target)
{
	Vector3 direction = Vector3(player.x - target.x, player.y - target.y, player.z - target.z);
	return Vector2(RAD2DEG(asin(direction.y / direction.Length())), RAD2DEG(-atan2(direction.x, -direction.z)));
}

std::map<int, BoneList> GetSelectedBone =
{
	{0, BoneList::head},
	{1, BoneList::spine3 },
	{2, BoneList::spine1},
	{3, BoneList::pelvis},
	{4, BoneList::l_forearm},

	{5, BoneList::l_knee},
	{6, BoneList::r_forearm},
	{7, BoneList::r_knee},
};

Vector3 Prediction(Vector3 local_position, Vector3 target_position)
{
	Vector3 result = target_position;

	float distance = local_position.Distance(target_position);

	if (distance > 0.001f && distance < 500.f)
	{
		uintptr_t ammo_defination = driver.ReadChain<uintptr_t>(global.held_item, { 0xa0, 0x2c0, 0x20, 0x10, 0x30 });

		uintptr_t item_mod_projectile = Unity->GetComponentFromGameObject(ammo_defination, "ItemModProjectile");
		if (!item_mod_projectile) return result;

		uintptr_t projectile = Unity->GetComponentFromGameObject(driver.ReadChain<uintptr_t>(item_mod_projectile, { 0x18, 0x18, 0x10 }), "Projectile");
		if (!projectile) return result;

		float bullet_speed = driver.read<float>(item_mod_projectile + 0x34);
		float bullet_drag = driver.read<float>(projectile + 0x24);
		float bullet_gravity = driver.read<float>(projectile + 0x28);

		bullet_speed *= 1 - 0.03125f * bullet_drag;

		float travel_time = distance / bullet_speed;

		Vector3 target_velocity = players.aim_target->GetPlayerModel()->GetNewVelocity();

		target_velocity = Vector3(target_velocity.x * travel_time, target_velocity.y * travel_time, target_velocity.z * travel_time);

		result += target_velocity;

		result.y += (0.5f * fabsf(bullet_gravity) * travel_time * travel_time) * 10;
	}
	return result;
}

void Target()
{
	int closest = 9999.0f;
	players.aim_target = NULL;

	std::vector<RUSTPLAYER> cachedList = global.player_list;

	for (int i = 0; i < cachedList.size(); i++)
	{
		RUSTPLAYER player = cachedList[i];

		if ((player.is_npc && global.aimbot_ignore_npc) || (player.is_sleeping && global.aimbot_ingore_sleepers)) continue;

		Vector2 screen_position;
		Vector3 position = Unity->GetTransformPosition(reinterpret_cast<BasePlayer*>(player.instance)->GetBoneTransform(GetSelectedBone[global.selected_aimbot_bone]));
		//printf("%f %f %f\n", position.x, position.y, position.z);
		if (position == Vector3{ 0,0,0 }) continue;

		if (camera.WorldToScreen(position, screen_position, global.view_matrix))
		{
			float distance = screen_position.Distance(Vector2(global.screen_width / 2, global.screen_height / 2));
			if (distance < global.aimbot_fov)
			{
				if (distance < closest)
				{
					closest = distance;
					players.aim_target = reinterpret_cast<BasePlayer*>(player.instance);
				}
			}
		}
	}
}

int Aimbot()
{
	std::mutex thread_lock;
	thread_lock.lock();

	printf("[+] Thread 3 Started\n");
	while (true)
	{
		if (GetAsyncKeyState(global.aimbot_key) && global.aimbot_enabled)
		{
			Target();

			Vector3 local_position = driver.read<Vector3>(global.camera + 0x42c);
			Vector3 target_position = Unity->GetTransformPosition(players.aim_target->GetBoneTransform(GetSelectedBone[global.selected_aimbot_bone]));

			if ((players.aim_target->GetHealthInformation().first <= 0) || (local_position.Distance(target_position) >= global.max_aimbot_distance)) continue;

			target_position = Prediction(local_position, target_position);

			Vector2 angle = CalculateAngle(local_position, target_position);

			players.local->GetPlayerEyes()->SetBodyRotation(Vector3(angle.x, angle.y, 0.0f).Quaternion());
			//players.local->GetPlayerInput()->SetBodyAngles(Vector3(angle.x, angle.y, 0));
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
	thread_lock.unlock();
	return -1;
}