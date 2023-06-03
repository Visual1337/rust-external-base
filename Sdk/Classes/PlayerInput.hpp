class PlayerInput
{
public:
	Vector3 GetBodyAngles()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector3(0, 0, 0);

		return driver.read<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInput.BodyAngles);
	}

	void SetBodyAngles(Vector3 angles)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInput.BodyAngles, angles);
	}

	Vector3 GetRecoilAngles()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector3(0,0,0);

		return driver.read<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInput.RecoilAngles);
	}

	bool GetAutoRun()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInput.AutoRun);
	}

	void SetAutoRun(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerInput.AutoRun, value);
	}
};