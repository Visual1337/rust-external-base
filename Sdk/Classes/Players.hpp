class players
{
public:
	BasePlayer* local{};
	uintptr_t local_position_ptr;
	Vector3 local_position;

	BasePlayer* aim_target{};
	uintptr_t aim_target_cached_bones;
	uintptr_t aim_position_ptr;
} players;