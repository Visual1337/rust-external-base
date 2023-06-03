class PlayerEyes
{
public:
	Vector3 GetViewOffset()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector3(0,0,0);

		return driver.read<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerEyes.ViewOffset);
	}

	void SetViewOffset(Vector3 value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerEyes.ViewOffset, value);
	}

	Vector4 GetBodyRotation()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector4(0,0,0,0);

		return driver.read<Vector4>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerEyes.BodyRotation);
	}

	void SetBodyRotation(Vector4 angle)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<Vector4>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerEyes.BodyRotation, angle);
	}
};