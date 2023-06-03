class Unity
{
private:
	struct matrices
	{
		uint64_t matrices;
		int index;
	};

	struct matrix_list
	{
		uint64_t matrixListBase = 0;
		uint64_t dependencyIndexTableBase = 0;
	};
public:

	uintptr_t GetComponentFromGameObject(uint64_t game_object, const char* component_name)
	{
		char buffer[128] = {};

		uintptr_t game_object_class = driver.read<uintptr_t>(game_object + 0x30);
		for (int i = 0; i < 20; i++)
		{
			uintptr_t component = driver.read<uintptr_t>(game_object_class + (0x10 * i + 0x8));
			if (!component) continue;

			uintptr_t fields = driver.read<uintptr_t>(component + 0x28);
			if (!fields) continue;

			uintptr_t name_ptr = driver.read<uintptr_t>(fields);
			name_ptr = driver.read<uintptr_t>(name_ptr + 0x10);
			if (!name_ptr) continue;

			driver.readEx((name_ptr), (ULONG64)buffer, 128);
			//printf("%s\n", buffer);

			if (strcmp(buffer, component_name) == 0)
			{
				return fields;
			}
		}

		return -1;
	}

	uintptr_t GetCameraFromName(const char* camera_name, bool get_object = false) {
		char buffer[128] = {};

		uintptr_t camera_manager_offset = driver.read<uintptr_t>(global.unity_player + Offsets::Unity.AllCameras); // 0x1A74500
		uintptr_t camera_manager = driver.read<uintptr_t>(camera_manager_offset + 0x0);

		int size = driver.read<int>(camera_manager_offset + 0x10);

		for (int i = 0; i < size; i++)
		{
			uintptr_t camera = driver.read<uintptr_t>(camera_manager + (i * 0x8));

			if (!camera)continue;

			uintptr_t camera_object = driver.read<uintptr_t>(camera + 0x30);
			uintptr_t name_ptr = driver.read<uintptr_t>(camera_object + 0x60);
			driver.readEx((name_ptr + 0x0), (ULONG64)buffer, 128);

			//printf("%s\n", buffer);

			if (strcmp(buffer, camera_name) == 0)
			{
				if (get_object)
				{
					return camera_object;
				}
				else
				{
					return camera;
				}
			}
		}
		return NULL;
	}

	struct UnityEngine_TransformAccessReadOnly
	{
		uintptr_t TransformData;        /* 0x0  */
		uint32_t Index;                 /* 0x8  */
	};

	struct UnityEngine_TransformData
	{
		uintptr_t TransformArray;       /* 0x0  */
		uintptr_t TransformIndices;     /* 0x8  */
	};

	Vector3 GetTransformPosition(_In_ uintptr_t transform)
	{
		uintptr_t transform_internal = driver.read<uintptr_t>(transform + 0x10);

		if (!transform_internal)
			return Vector3();
		try
		{
			__m128 result;

			const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
			const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
			const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

			UnityEngine_TransformAccessReadOnly pTransformAccessReadOnly = driver.read<UnityEngine_TransformAccessReadOnly>(transform_internal + 0x38);
			UnityEngine_TransformData transformData = driver.read<UnityEngine_TransformData>(pTransformAccessReadOnly.TransformData + 0x18);

			if (!transformData.TransformArray)
				return Vector3();

			if (!transformData.TransformIndices)
				return Vector3();

			size_t sizeMatriciesBuf = sizeof(matrix3x4) * pTransformAccessReadOnly.Index + sizeof(matrix3x4);
			size_t sizeIndicesBuf = sizeof(int) * pTransformAccessReadOnly.Index + sizeof(int);

			void* pMatriciesBuf = malloc(sizeMatriciesBuf);
			void* pIndicesBuf = malloc(sizeIndicesBuf);

			if (pMatriciesBuf && pIndicesBuf)
			{
				if (transformData.TransformArray == 0 || transformData.TransformIndices == 0)
					return Vector3();

				// Read Matricies array into the buffer
				driver.readEx(transformData.TransformArray, (ULONG64)pMatriciesBuf, sizeMatriciesBuf);
				// Read Indices array into the buffer
				driver.readEx(transformData.TransformIndices, (ULONG64)pIndicesBuf, sizeIndicesBuf);

				__m128 Result = *reinterpret_cast<__m128*>(reinterpret_cast<uint64_t>(pMatriciesBuf) + (0x30 * pTransformAccessReadOnly.Index));
				int TransformIndex = *reinterpret_cast<int*>((reinterpret_cast<uint64_t>(pIndicesBuf) + (0x4 * pTransformAccessReadOnly.Index)));

				while (TransformIndex >= 0 && TransformIndex < (sizeMatriciesBuf / 0x30))
				{
					if (!pMatriciesBuf || !pIndicesBuf || !&result || !&TransformIndex)
						return Vector3();

					matrix3x4 Matrix = *reinterpret_cast<matrix3x4*>(reinterpret_cast<uint64_t>(pMatriciesBuf) + (0x30 * TransformIndex));

					if (!&Matrix)
						return Vector3();

					__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*reinterpret_cast<__m128i*>(&Matrix._21), 0x00));	// xxxx
					__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*reinterpret_cast<__m128i*>(&Matrix._21), 0x55));	// yyyy
					__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*reinterpret_cast<__m128i*>(&Matrix._21), 0x8E));	// zwxy
					__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*reinterpret_cast<__m128i*>(&Matrix._21), 0xDB));	// wzyw
					__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*reinterpret_cast<__m128i*>(&Matrix._21), 0xAA));	// zzzz
					__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*reinterpret_cast<__m128i*>(&Matrix._21), 0x71));	// yxwy
					__m128 tmp7 = _mm_mul_ps(*reinterpret_cast<__m128*>(&Matrix._31), Result);

					Result = _mm_add_ps(
						_mm_add_ps(
							_mm_add_ps(
								_mm_mul_ps(
									_mm_sub_ps(
										_mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
										_mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
									_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
								_mm_mul_ps(
									_mm_sub_ps(
										_mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
										_mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
									_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
							_mm_add_ps(
								_mm_mul_ps(
									_mm_sub_ps(
										_mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
										_mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
									_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
								tmp7)), *(__m128*)(&Matrix._11));

					TransformIndex = *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(pIndicesBuf) + (0x4 * TransformIndex));
				}

				free(pMatriciesBuf);
				free(pIndicesBuf);

				return Vector3{ Result.m128_f32[0], Result.m128_f32[1], Result.m128_f32[2] };
			}

			return {};
		}
		catch (...)
		{
			return Vector3();
		}
	}

	double GetRealTimeSinceStartup()
	{
		double v0; // xmm0_8
		LARGE_INTEGER PerformanceCount; // [rsp+30h] [rbp+8h] BYREF

		if (driver.read<uint32_t>(global.unity_player + 0x181B020) == -1)
		{
			PerformanceCount.QuadPart = 0;
			QueryPerformanceCounter(&PerformanceCount);
			driver.write<uint64_t>(global.unity_player + 0x181B018, PerformanceCount.QuadPart);
		}

		PerformanceCount.QuadPart = 0;
		QueryPerformanceCounter(&PerformanceCount);

		uint64_t qword_181B018 = driver.read<uint64_t>(global.unity_player + 0x181B018);

		v0 = (double)(PerformanceCount.LowPart - (int)qword_181B018);

		if (PerformanceCount.QuadPart - qword_181B018 < 0) {
			v0 = v0 + 1.844674407370955e19;
		}

		v0 = v0 * driver.read<double>(global.unity_player + 0x181AE58) / 1000000000.0;
		v0 = v0 - driver.read<double>(global.unity_player + 0x1769F40);

		uint64_t time_manager_ptr = driver.read<uint64_t>(global.unity_player + (0x17C1CD0 + (7 * 0x8)));

		return v0 - driver.read<double>(time_manager_ptr + 0xE8);
	}

	void IgnoreLayer(int main_layer, int layer_to_ignore, bool should_ignore = 0)
	{
		/*
			a1 = physics_manager
			a2 = main_layer
			a3 = layer_to_ignore
			a4 = should_ignore
		*/
		uintptr_t physics_manager = driver.read<uintptr_t>(global.unity_player + (0x17C1CD0 + (9 * 0x8)));

		uint64_t v7 = driver.read<uint64_t>(physics_manager + 0x70);
		uint32_t v8 = driver.read<uint32_t>(v7 + (0x4 * main_layer));

		int v11 = 1 << layer_to_ignore;

		//if (((v8 & (1 << layer_to_ignore)) == 0) != should_ignore)
		{
			int v12 = 0x4 * layer_to_ignore;
			int v13 = 0x1 << main_layer;

			int flags = driver.read<int>(v12 + v7);
			if (!should_ignore)
			{
				driver.write<uint32_t>(v8, v8 & ~v11);
				driver.write<uint64_t>(v12 + v7, flags &= ~v13);
			}
			else
			{
				driver.write<uint32_t>(v8, v11 | v8);
				driver.write<uint64_t>(v12 + v7, flags |= v13);
			}
		}
	}

	void SetTimeScale(float time_scale)
	{
		uintptr_t time_manager = driver.read<uintptr_t>(global.unity_player + (0x17C1CD0 + (7 * 0x8)));

		if (time_scale >= 0.0)
		{
			driver.write<float>(time_manager + 0xFC, time_scale);
		}
	}

	void SetKeyState(KeyCode a2, bool a3)
	{
		uint64_t input_manager = driver.read<uint64_t>(global.unity_player + (0x17C1CD0 + (1 * 0x8)));

		unsigned __int64 v3; // r9
		__int64 v5; // rdx
		unsigned __int64 v6; // r10
		unsigned int v7; // ecx
		LONG v8; // eax
		__int64 v9; // rax
		__int64 v10; // rcx
		char v11; // r9
		int v12; // eax
		int result; // eax
		int flags;

		v3 = a2;
		v5 = driver.read<uint64_t>(input_manager + (11 * 0x8));
		v6 = v3 >> 5;
		v7 = v3 & 0x1F;
		v8 = driver.read<int>(v5 + 4 * (v3 >> 5));
		if (a3)
		{
			if (_bittest(&v8, v7))
				goto LABEL_7;
			v9 = driver.read<uint64_t>(input_manager + (15 * 0x8));
		}
		else
		{
			if (!_bittest(&v8, v7))
				goto LABEL_7;
			v9 = driver.read<uint64_t>(input_manager + (19 * 0x8));
		}
		flags = driver.read<int>(v9 + 4 * v6);
		driver.write<int>(v9 + 4 * v6, flags |= 1 << (v3 & 0x1F));
	LABEL_7:
		v10 = driver.read<uint64_t>(input_manager + (11 * 0x8));
		v11 = v3 & 0x1F;
		v12 = driver.read<int>(v10 + 4 * v6);
		if (a3)
		{
			result = v12 | (1 << v11);
		}
		else
		{
			result = v12 & ~(1 << v11);
			driver.write<int>(v10 + 4 * v6, result);
		}
	}

}*Unity;