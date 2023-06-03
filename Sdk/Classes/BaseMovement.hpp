class BaseMovement
{
public:
	bool GetFlying()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		bool grounded = driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Grounded);
		bool climbing = ((driver.read<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Ladder) == 0) ? false : true);
		bool swimming = driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Swimming);

		printf("result %i grounded? %i climbing? %i swimming?\n", grounded, climbing, swimming);

		return (!grounded && !climbing && !swimming);
	}

	Vector3 GetTargetMovement() 
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector3(0,0,0);

		return driver.read<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMovement.TargetMovement);
	}

	void SetTargetMovement(Vector3 value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMovement.TargetMovement, value);
	}

	float GetRunning()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMovement.Running);
	}

	void SetRunning(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMovement.Running, value);
	}

	float GetDucking()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMovement.Ducking);
	}

	void SetDucking(bool toggle, float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMovement.Ducking, value);
	}

	float GetCrawling()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::BaseMovement.Crawling);
	}

	//PlayerWalkMovement

	float GetCapsuleHeight()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.CapsuleHeight);
	}

	void SetCapsuleHeight(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.CapsuleHeight, value);
	}

	float GetCapsuleCenter()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.CapsuleCenter);
	}

	void SetCapsuleCenter(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.CapsuleCenter, value);
	}

	float GetGravityMultiplier()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GravityMultiplier);
	}

	void SetGravityMultiplier(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GravityMultiplier, value);
	}

	float GetGravityMultiplierSwimming()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GravityMultiplierSwimming);
	}

	void SetGravityMultiplierSwimming(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GravityMultiplierSwimming, value);
	}

	float GetMaxAngleWalking()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxAngleWalking);
	}

	void SetMaxAngleWalking(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxAngleWalking, value);
	}

	float GetMaxAngleClimbing()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxAngleClimbing);
	}

	void SetMaxAngleClimbing(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxAngleClimbing, value);
	}

	float GetMaxAngleSliding()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxAngleSliding);
	}

	void SetMaxAngleSliding(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxAngleSliding, value);
	}

	float GetMaxStepHeight()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxStepHeight);
	}

	void SetMaxStepHeight(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxStepHeight, value);
	}

	float GetMaxVelocity()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxVelocity);
	}

	void SetMaxVelocity(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.MaxVelocity, value);
	}

	float GetGroundAngle()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GroundAngle);
	}

	void SetGroundAngle(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GroundAngle, value);
	}

	float GetGroundAngleNew()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GroundAngleNew);
	}

	void SetGroundAngleNew(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GroundAngleNew, value);
	}

	float GetGroundTime()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GroundTime);
	}

	void SetGroundTime(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.GroundTime, value);
	}

	float GetJumpTime()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.JumpTime);
	}

	void SetJumpTime(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.JumpTime, value);
	}

	float GetLandTime()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return -1.f;

		return driver.read<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.LandTime);
	}

	void SetLandTime(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.LandTime, value);
	}

	Vector3 GetPreviousPosition()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return Vector3(0,0,0);

		return driver.read<Vector3>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.PreviousPosition);
	}

	bool GetSprintForced()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.SprintForced);
	}
	//0x14C
	void SetSprintForced(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.SprintForced, value);
	}

	void SetDuckedDelta(float value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<float>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.ForcedDuckDelta, value);
	}

	bool GetGrounded()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Grounded);
	}

	void SetGrounded(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Grounded, value);
	}

	bool GetClimbing()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Climbing);
	}

	void SetClimbing(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Climbing, value);
	}

	bool GetSliding()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Sliding);
	}

	void SetSliding(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Sliding, value);
	}

	bool GetSwimming()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Swimming);
	}

	void SetSwimming(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Swimming, value);
	}

	bool GetJumping()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Jumping);
	}

	void SetJumping(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Jumping, value);
	}

	bool GetFalling()
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return false;

		return driver.read<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Falling);
	}

	void SetFalling(bool value)
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return;

		driver.write<bool>(reinterpret_cast<uintptr_t>(this) + Offsets::PlayerWalkMovement.Falling, value);
	}
};