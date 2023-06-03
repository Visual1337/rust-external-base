class ModelState
{
public:
	float GetWaterLevel()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::ModelState.WaterLevel);
	}

	void SetWaterLevel(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::ModelState.WaterLevel, value);
	}

	int GetModelStateFlags()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return NULL;

		return driver.read<int>(reinterpret_cast<uintptr_t>(this) + Offsets::ModelState.Flags);
	}

	void SetModelStateFlags(ModelStateFlags modelFlags)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		int flags = driver.read<int>(reinterpret_cast<uintptr_t>(this) + Offsets::ModelState.Flags);
		driver.write<int>(reinterpret_cast<uintptr_t>(this) + Offsets::ModelState.Flags, (flags |= flags));
	}

	void SetRemoveModelStateFlags(ModelStateFlags modelFlags)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		int flags = driver.read<int>(reinterpret_cast<uintptr_t>(this) + Offsets::ModelState.Flags);
		driver.write<int>(reinterpret_cast<uintptr_t>(this) + Offsets::ModelState.Flags, (flags &= ~flags));
	}
};