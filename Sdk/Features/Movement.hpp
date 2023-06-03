class Movement
{
public:
	void FakeDuck()
	{
		if (global.fake_duck)
		{
			if (GetAsyncKeyState(VK_XBUTTON1))
			{
				players.local->GetPlayerEyes()->SetViewOffset(Vector3(0.f, 0.75f, 0.f));
			}
		}
	}

	void ShootWhileMounted()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		uintptr_t base_mounted = driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(players.local) + 0x608);
		if (base_mounted)
		{
			driver.write<bool>(base_mounted + 0x2b8, true);
		}
	}

	void FakeAdmin()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		if (global.fake_admin)
		{
			reinterpret_cast<BasePlayer*>(this)->SetPlayerFlags(PlayerFlags::IsAdmin);
		}
	}

	void SpiderMan()
	{
		if(!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		if (global.spider_man)
		{
			BaseMovement* movement = reinterpret_cast<BasePlayer*>(this)->GetBaseMovement();

			movement->SetGroundAngle(0.0f);
			movement->SetGroundAngleNew(0.0f);
		}
	}

	void InfiniteJump()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		if (global.infinite_jump)
		{
			BaseMovement* movement = reinterpret_cast<BasePlayer*>(this)->GetBaseMovement();

			movement->SetJumpTime(0.0f);
			movement->SetLandTime(0.0f);
		}
	}

	void NoSway()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		if (global.no_sway)
		{
			reinterpret_cast<BasePlayer*>(this)->SetClothingAccuracyBonus(1.f);		
		}
	}

	void UnlockAngles()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		if (global.unlock_angles)
		{
			reinterpret_cast<BasePlayer*>(this)->SetClothingBlocksAiming(false);
		}
	}

	void FlyHack()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		if (global.fly_hack)
		{
			Vector3 target_movement = Vector3(0, 0, 0);
			Vector4 rotation = reinterpret_cast<BasePlayer*>(this)->GetPlayerEyes()->GetBodyRotation();

			if (GetAsyncKeyState(0x57) & 1)
			{
				target_movement += Transform(Vector3(0, 0, 1), rotation);
			}
			if (GetAsyncKeyState(0x53) & 1)
			{
				target_movement -= Transform(Vector3(0, 0, 1), rotation);
			}
			if (GetAsyncKeyState(0x41) & 1)
			{
				target_movement -= Transform(Vector3(1, 0, 0), rotation);
			}
			if (GetAsyncKeyState(0x44) & 1)
			{
				target_movement += Transform(Vector3(1, 0, 0), rotation);
			}

			if (GetAsyncKeyState(VK_SPACE) & 1)
			{
				target_movement.y += 1.f;
			}

			float d = 5.f;
			if (GetAsyncKeyState(VK_CONTROL) & 1)
			{
				d = 2.5f;
			}
			if (GetAsyncKeyState(VK_SHIFT) & 1)
			{
				d = 10.f;
			}
			if (!(target_movement == Vector3{ 0.f, 0.f, 0.f }))
			{
				players.local->GetBaseMovement()->SetTargetMovement(target_movement * d);
			}
		}
	}

	void BlockCommands()
	{
		uint64_t list = driver.ReadChain<uintptr_t>(global.game_assembly, { Offsets::GameAssembly.ConsoleSystem, 0xB8, 0x30 });

		uint32_t size = driver.read<int>(list + 0x18);
		for (int i = 0; i < size; i++)
		{
			uint64_t command = driver.read<uint64_t>(list + (0x20 + (0x8 * i)));
			std::string name = driver.GetUnicodeString(driver.read<uint64_t>(command + 0x10), 128);
			if (name == "noclip" || name == "camspeed" || name == "debugcamera")
			{
				//printf("%s\n", name.c_str());
				driver.write<bool>(command + 0x58, false);
			}
		}
	}
};
