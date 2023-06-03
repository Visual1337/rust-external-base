#pragma once
#include <math.h>

#define M_PI 3.14159265358979323846f
#define M_RADPI	57.295779513082f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))
#define atan2(a, b) ((float)atan2((double)(a), (double)(b)))

struct matrix4x4 
{
	union 
	{
		struct 
		{
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
};

struct matrix3x4
{
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
};

class Vector4
{
public:
	Vector4() : x(0.f), y(0.f), z(0.f), w(0.f)
	{

	}

	Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w)
	{

	}
	~Vector4()
	{

	}

	float x, y, z, w;
};

class Vector3
{
public:
	Vector3() : x(0.f), y(0.f), z(0.f)
	{

	}

	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
	{

	}
	~Vector3()
	{

	}

	inline float Dot(Vector3 v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline float Distance(Vector3 v)
	{
		return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
	}

	Vector3 abs()
	{
		return Vector3(std::abs(x), std::abs(y), std::abs(z));
	}

	inline float Length()
	{
		float ls = x * x + y * y + z * z;
		return sqrt(ls);
	}

	void clamp() 
	{
		if (x > 75.f)
		{
			x = 75.f;
		}
		else if (x < -75.f)
		{
			x = -75.f;
		}
		if (z < -180) 
		{
			z += 360.0f;
		}
		else if (z > 180)
		{
			z -= 360.0f;
		}
		y = 0.f;
	}

	Vector4 Quaternion()
	{
		double heading = DEG2RAD(x);
		double attitude = DEG2RAD(y);
		double bank = DEG2RAD(z);

		double c1 = cos(heading / 2);
		double s1 = sin(heading / 2);
		double c2 = cos(attitude / 2);
		double s2 = sin(attitude / 2);
		double c3 = cos(bank / 2);
		double s3 = sin(bank / 2);
		double c1c2 = c1 * c2;
		double s1s2 = s1 * s2;
		Vector4 Quat;
		Quat.w = c1c2 * c3 - s1s2 * s3;
		Quat.x = c1c2 * s3 + s1s2 * c3;
		Quat.y = s1 * c2 * c3 + c1 * s2 * s3;
		Quat.z = c1 * s2 * c3 - s1 * c2 * s3;
		Vector4 Quat2;
		Quat2 = { Quat.y, Quat.z, (Quat.x * -1), Quat.w };
		return Quat2;
	}

	bool operator==(const Vector3& in) const 
	{
		return (x == in.x && y == in.y && z == in.z);
	}

	bool operator!=(const Vector3& in) const
	{
		return (x != in.x || y != in.y || z != in.z);
	}

	Vector3 operator+(Vector3 v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(Vector3 v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(float number) const 
	{
		return Vector3(x * number, y * number, z * number);
	}

	Vector3& operator/(float fl)
	{
		x / fl;
		y / fl;
		z / fl;
		return *this;
	}

	Vector3& operator/=(float fl) 
	{
		x /= fl;
		y /= fl;
		z /= fl;
		return *this;
	}

	Vector3& operator+=(const Vector3& v) 
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3& operator-=(const Vector3& v) 
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	//bool operator<(const Vector3& v) const
	//{
	//	if (x < v.x && y < v.y && z < v.z)
	//	{
	//		return false;
	//	}
	//	else
	//	{
	//		return true;
	//	}

	//	//return (x < v.x && y < v.y && z < v.z) ? true : false;
	//}

	float x, y, z;
};

class Vector2
{
public:
	Vector2() : x(0.f), y(0.f)
	{

	}

	Vector2(float _x, float _y) : x(_x), y(_y)
	{

	}
	~Vector2()
	{

	}

	inline float Distance(Vector2 v)
	{
		return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0)));
	}

	bool operator==(Vector2& in)
	{
		return (this->x == in.x && this->y == in.y);
	}

	Vector2 operator+(Vector2 v)
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 operator-(Vector2 v)
	{
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 operator+=(Vector2 v)
	{
		return Vector2(x += v.x, y += v.y);
	}

	Vector2 operator/=(Vector2 v)
	{
		return Vector2(x /= v.x, y /= v.y);
	}

	Vector2& operator/(float fl)
	{
		x / fl;
		y / fl;
		return *this;
	}

	float x, y;
};

Vector3 Transform(Vector3 value, Vector4 rotation)
{
	Vector3 vector;
	float num12 = rotation.x + rotation.x;
	float num2 = rotation.y + rotation.y;
	float num = rotation.z + rotation.z;
	float num11 = rotation.w * num12;
	float num10 = rotation.w * num2;
	float num9 = rotation.w * num;
	float num8 = rotation.x * num12;
	float num7 = rotation.x * num2;
	float num6 = rotation.x * num;
	float num5 = rotation.y * num2;
	float num4 = rotation.y * num;
	float num3 = rotation.z * num;
	float num15 = ((value.x * ((1.f - num5) - num3)) + (value.y * (num7 - num9))) + (value.z * (num6 + num10));
	float num14 = ((value.x * (num7 + num9)) + (value.y * ((1.f - num8) - num3))) + (value.z * (num4 - num11));
	float num13 = ((value.x * (num6 - num10)) + (value.y * (num4 + num11))) + (value.z * ((1.f - num8) - num5));
	vector.x = num15;
	vector.y = num14;
	vector.z = num13;
	return vector;
}