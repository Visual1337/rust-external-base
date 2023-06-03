class Camera
{
public:

	bool WorldToScreen(const Vector3& entity_position, Vector2& screen_position, matrix4x4 view_matrix)
	{
		Vector3 trans_vec{ view_matrix._14, view_matrix._24, view_matrix._34 };
		Vector3 right_vec{ view_matrix._11, view_matrix._21, view_matrix._31 };
		Vector3 up_vec{ view_matrix._12, view_matrix._22, view_matrix._32 };

		float w = trans_vec.Dot(entity_position) + view_matrix._44;

		if (w < 0.00f) return false;

		float y = up_vec.Dot(entity_position) + view_matrix._42;
		float x = right_vec.Dot(entity_position) + view_matrix._41;

		screen_position = Vector2((global.screen_width / 2) * (1.f + x / w) + 4, (global.screen_height / 2) * (1.f - y / w) + 4);
		return true;
	}

	matrix4x4 GetMatrix() 
	{
		if (!Utils::ValidPointer(reinterpret_cast<uintptr_t>(this))) return {};
		return driver.read<matrix4x4>(reinterpret_cast<uintptr_t>(this) + Offsets::Camera.ViewMatrix2);
	}

	uintptr_t GetMainCamera()
	{
		return Unity->GetCameraFromName("Main Camera");
	}
}camera;