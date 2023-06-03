class BasePlayer
{
public:
	uintptr_t GetPositionPointer()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.ReadChain<uintptr_t>(reinterpret_cast<uintptr_t>(this), { 0x10, 0x30, 0x30, 0x8, 0x38 });
	}

	uintptr_t GetBoneTransform(BoneList bone)
	{
		uintptr_t player_model = driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x130);
		uintptr_t bone_transforms = driver.read<uintptr_t>(player_model + 0x48);
		return driver.read<uintptr_t>((bone_transforms + (0x20 + (bone * 0x8))));
	}

	bool GetVisible()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseEntity.isVisible);
	}

	std::pair<float, float> GetHealthInformation()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return std::make_pair(-1.f, -1.f);

		float health = driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseCombatEntity.Health);
		float max_health = driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseCombatEntity.MaxHealth);

		return std::make_pair(health, max_health);
	}

	PlayerModel* GetPlayerModel()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<PlayerModel*>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.PlayerModel);
	}

	PlayerInput* GetPlayerInput()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<PlayerInput*>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.PlayerInput);
	}

	BaseMovement* GetBaseMovement()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<BaseMovement*>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.BaseMovement);
	}

	uintptr_t GetCurrentTeam()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return  driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.CurrentTeam);
	}

	uintptr_t GetActiveItem()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return  driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ClActiveItem);
	}

	ModelState* GetModelState()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<ModelState*>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ModelState);
	}

	PlayerEyes* GetPlayerEyes()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<PlayerEyes*>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.PlayerEyes);
	}

	PlayerInventory* GetPlayerInventory()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<PlayerInventory*>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.PlayerInventory);
	}

	std::string GetName()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return "";

		uintptr_t name_ptr = driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.DisplayName);

		return driver.GetUnicodeString(name_ptr + Offsets::String.Name, 128);
	}

	void SetPlayerFlags(PlayerFlags player_flags)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		int Flags = driver.read<int>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.PlayerFlags);
		driver.write<int>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.PlayerFlags, (Flags |= player_flags));
	}

	bool GetClothingBlocksAiming()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ClothingBlocksAiming);
	}

	void SetClothingBlocksAiming(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ClothingBlocksAiming, value);
	}

	float GetClothingMoveSpeedReduction()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ClothingMoveSpeedReduction);
	}

	void SetClothingMoveSpeedReduction(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ClothingMoveSpeedReduction, value);
	}

	float GetClothingAccuracyBonus()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ClothingAccuracyBonus);
	}

	void SetClothingAccuracyBonus(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BasePlayer.ClothingAccuracyBonus, value);
	}
};
