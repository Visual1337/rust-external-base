class PlayerModel
{
public:
	uintptr_t GetMaleSkin()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerModel.MaleSkin);
	}

	int GetSkinType()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1;

		return driver.read<int>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerModel.SkinType);
	}

	Vector3 GetVelocity()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector3(0, 0, 0);

		return driver.read<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerModel.Velocity);
	}

	Vector3 GetNewVelocity()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector3(0,0,0);

		return driver.read<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerModel.NewVelocity);
	}

	bool GetIsIncapacitated()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerModel.IsIncapacitated);
	}

	bool GetIsNpc()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerModel.IsNpc);
	}

	void SetDucked(bool toggle)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<int>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerModel.Ducked, (int)toggle);
	}
};