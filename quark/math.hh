#pragma once

//---------------------------------------------------------------
//	Defines / Macros
//---------------------------------------------------------------

#define UFGM_PI				3.1415926535897932384626433832795
#define UFGM_PI_F			((f32)(UFGM_PI))

#define UFGM_DEG2RAD_MUL	(UFGM_PI_F / 180.f)
#define UFGM_DEG2RAD(x)		(x * UFGM_DEG2RAD_MUL)

#define UFGM_RAD2DEG_MUL	(180.f / UFGM_PI_F)
#define UFGM_RAD2DEG(x)		(x * UFGM_RAD2DEG_MUL)

//---------------------------------------------------------------

namespace UFG
{
	class qVector2
	{
	public:
		f32 x, y;

		SDK_INLINE qVector2() {}
		SDK_INLINE qVector2(f32 f) : x(f), y(f) {}
		SDK_INLINE qVector2(f32 fX, f32 fY) : x(fX), y(fY) {}

		/* Operators */

		SDK_INLINE bool operator==(const qVector2& vec) const { return (x == vec.x && y == vec.y); }
		SDK_INLINE bool operator!=(const qVector2& vec) const { return (x != vec.x || y != vec.y); }

		SDK_INLINE qVector2 operator+(const qVector2& vec) const { return { x + vec.x, y + vec.y }; }
		SDK_INLINE qVector2 operator-(const qVector2& vec) const { return { x - vec.x, y - vec.y }; }
		SDK_INLINE qVector2 operator*(const qVector2& vec) const { return { x * vec.x, y * vec.y }; }
		SDK_INLINE qVector2 operator*(f32 v) const { return { x * v, y * v }; }
		SDK_INLINE qVector2 operator/(const qVector2& vec) const { return { x / vec.x, y / vec.y }; }
		SDK_INLINE qVector2 operator/(f32 v) const { return { x / v, y / v }; }

		SDK_INLINE void operator+=(const qVector2& vec) { x += vec.x; y += vec.y; }
		SDK_INLINE void operator-=(const qVector2& vec) { x -= vec.x; y -= vec.y; }
		SDK_INLINE void operator*=(const qVector2& vec) { x *= vec.x; y *= vec.y; }
		SDK_INLINE void operator*=(f32 v) { x *= v; y *= v; }
		SDK_INLINE void operator/=(const qVector2& vec) { x /= vec.x; y /= vec.y; }
		SDK_INLINE void operator/=(f32 v) { x /= v; y /= v; }

		SDK_INLINE qVector2 operator-() const { return { -x, -y }; }

		/* Impl Functions */

		SDK_INLINE f32 DistTo(const qVector2& vec) { return (*this - vec).Length(); }
		SDK_INLINE f32 Length() const { return sqrtf(x * x + y * y); }
		SDK_INLINE void Normalize() { operator/=(Length()); }

		SDK_INLINE void NormalizeSafe()
		{
			f32 length = Length();
			if (*reinterpret_cast<int*>(&length)) {
				operator/=(length);
			}
		}
	};

	class qVector3
	{
	public:
		f32 x, y, z;

		SDK_INLINE qVector3() {}
		SDK_INLINE qVector3(f32 f) : x(f), y(f), z(f) {}
		SDK_INLINE qVector3(f32 f0, f32 f1, f32 f2) : x(f0), y(f1), z(f2) {}

		/* Operators (Vec2) */

		SDK_INLINE qVector3 operator+(const qVector2& vec) const { return { x + vec.x, y + vec.y, z }; }
		SDK_INLINE qVector3 operator-(const qVector2& vec) const { return { x - vec.x, y - vec.y, z }; }
		SDK_INLINE qVector3 operator*(const qVector2& vec) const { return { x * vec.x, y * vec.y, z }; }
		SDK_INLINE qVector3 operator/(const qVector2& vec) const { return { x / vec.x, y / vec.y, z }; }

		SDK_INLINE void operator+=(const qVector2& vec) { x += vec.x; y += vec.y; }
		SDK_INLINE void operator-=(const qVector2& vec) { x -= vec.x; y -= vec.y; }
		SDK_INLINE void operator*=(const qVector2& vec) { x *= vec.x; y *= vec.y; }
		SDK_INLINE void operator/=(const qVector2& vec) { x /= vec.x; y /= vec.y; }

		/* Operators */

		SDK_INLINE bool operator==(const qVector3& vec) const { return (x == vec.x && y == vec.y && z == vec.z); }
		SDK_INLINE bool operator!=(const qVector3& vec) const { return (x != vec.x || y != vec.y || z != vec.z); }

		SDK_INLINE qVector3 operator+(const qVector3& vec) const { return { x + vec.x, y + vec.y, z + vec.z }; }
		SDK_INLINE qVector3 operator-(const qVector3& vec) const { return { x - vec.x, y - vec.y, z - vec.z }; }
		SDK_INLINE qVector3 operator*(const qVector3& vec) const { return { x * vec.x, y * vec.y, z * vec.z }; }
		SDK_INLINE qVector3 operator*(f32 v) const { return { x * v, y * v, z * v }; }
		SDK_INLINE qVector3 operator/(const qVector3& vec) const { return { x / vec.x, y / vec.y, z / vec.z }; }
		SDK_INLINE qVector3 operator/(f32 v) const { return { x / v, y / v, z / v }; }

		SDK_INLINE void operator+=(const qVector3& vec) { x += vec.x; y += vec.y; z += vec.z; }
		SDK_INLINE void operator-=(const qVector3& vec) { x -= vec.x; y -= vec.y; z -= vec.z; }
		SDK_INLINE void operator*=(const qVector3& vec) { x *= vec.x; y *= vec.y; z *= vec.z; }
		SDK_INLINE void operator*=(f32 v) { x *= v; y *= v; z *= v; }
		SDK_INLINE void operator/=(const qVector3& vec) { x /= vec.x; y /= vec.y; z /= vec.z; }
		SDK_INLINE void operator/=(f32 v) { x /= v; y /= v; z /= v; }

		SDK_INLINE qVector3 operator-() const { return { -x, -y, -z }; }

		/* Impl Functions */

		SDK_INLINE qVector3 CrossProduct(const qVector3& vec) const { return { y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x }; }
		SDK_INLINE f32 DistTo(const qVector3& vec) { return (*this - vec).Length(); }
		SDK_INLINE f32 DotProduct(const qVector3& vec) const { return x * vec.x + y * vec.y + z * vec.z; }
		SDK_INLINE f32 Length() const { return sqrtf(x * x + y * y + z * z); }
		SDK_INLINE f32 Length2D() const { return sqrtf(x * x + y * y); }
		SDK_INLINE void Normalize() { operator/=(Length()); }

		SDK_INLINE void NormalizeSafe() 
		{
			f32 length = Length();
			if (*reinterpret_cast<int*>(&length)) {
				operator/=(length);
			}
		}

		void AngleVectors(qVector3& forward)
		{
			f32 sp = sinf(x), sy = sinf(y), cp = cosf(x), cy = cosf(y);

			forward.x = cp * cy;
			forward.y = cp * sy;
			forward.z = -sp;
		}

		void AngleVectors(qVector3* forward, qVector3* right = 0, qVector3* up = 0)
		{
			f32 sp = sinf(x), sy = sinf(y), sr = sinf(z), cp = cosf(x), cy = cosf(y), cr = cosf(z);

			if (forward)
			{
				forward->x = cp * cy;
				forward->y = cp * sy;
				forward->z = -sp;
			}

			if (right)
			{
				right->x = (-1 * sr * sp * cy + -1 * cr * -sy);
				right->y = (-1 * sr * sp * sy + -1 * cr * cy);
				right->z = -1 * sr * cp;
			}

			if (up)
			{
				up->x = (cr * sp * cy + -sr * -sy);
				up->y = (cr * sp * sy + -sr * cy);
				up->z = cr * cp;
			}
		}

	};

	class qVector4
	{
	public:
		f32 x, y, z, w;

		SDK_INLINE qVector4() {}
		SDK_INLINE qVector4(f32 f) : x(f), y(f), z(f), w(f) {}
		SDK_INLINE qVector4(f32 f0, f32 f1, f32 f2, f32 f3) : x(f0), y(f1), z(f2), w(f3) {}

		/* Operators */

		SDK_INLINE bool operator==(const qVector4& vec) const { return (x == vec.x && y == vec.y && z == vec.z && w == vec.w); }
		SDK_INLINE bool operator!=(const qVector4& vec) const { return (x != vec.x || y != vec.y || z != vec.z || w != vec.w); }

		SDK_INLINE qVector4 operator+(const qVector4& vec) const { return { x + vec.x, y + vec.y, z + vec.z, w + vec.w }; }
		SDK_INLINE qVector4 operator-(const qVector4& vec) const { return { x - vec.x, y - vec.y, z - vec.z, w - vec.w }; }
		SDK_INLINE qVector4 operator*(const qVector4& vec) const { return { x * vec.x, y * vec.y, z * vec.z, w * vec.w }; }
		SDK_INLINE qVector4 operator*(f32 v) const { return { x * v, y * v, z * v, w * v }; }
		SDK_INLINE qVector4 operator/(const qVector4& vec) const { return { x / vec.x, y / vec.y, z / vec.z, w / vec.w }; }
		SDK_INLINE qVector4 operator/(f32 v) const { return { x / v, y / v, z / v, w / v }; }

		SDK_INLINE void operator+=(const qVector4& vec) { x += vec.x; y += vec.y; z += vec.z; w += vec.w; }
		SDK_INLINE void operator-=(const qVector4& vec) { x -= vec.x; y -= vec.y; z -= vec.z; w -= vec.w; }
		SDK_INLINE void operator*=(const qVector4& vec) { x *= vec.x; y *= vec.y; z *= vec.z; w *= vec.w; }
		SDK_INLINE void operator*=(f32 v) { x *= v; y *= v; z *= v; w *= v; }
		SDK_INLINE void operator/=(const qVector4& vec) { x /= vec.x; y /= vec.y; z /= vec.z; w /= vec.w; }
		SDK_INLINE void operator/=(f32 v) { x /= v; y /= v; z /= v; w /= v; }

		SDK_INLINE qVector4 operator-() const { return { -x, -y, -z, -w }; }

		/* Operators (Vector3) */

		SDK_INLINE void operator=(const qVector3& vec) { x = vec.x; y = vec.y; z = vec.z; }
		SDK_INLINE operator qVector3&() { return reinterpret_cast<qVector3&>(*this); }
		SDK_INLINE operator const qVector3&() const { return reinterpret_cast<const qVector3&>(*this); }

		/* Impl Functions */

		SDK_INLINE f32 Length() const { return sqrtf(x * x + y * y + z * z + w * w); }
	};

	class qMatrix44
	{
	public:
		/*
		* v0 - Forward
		* v1 - Right
		* v2 - Up
		* v3 - Position
		*/
		qVector4 v0, v1, v2, v3;

		SDK_INLINE qMatrix44() {}
		SDK_INLINE qMatrix44(const qVector4& vec0, const qVector4& vec1, const qVector4& vec2, const qVector4& vec3) : v0(vec0), v1(vec1), v2(vec2), v3(vec3) {}

		/* Static Members */

		SDK_VINLINE qGlobalVar<qMatrix44, 0x203BD40> msIdentity;

		/* Impl Functions */

		SDK_INLINE const qVector4& GetForward() const { return v0; }
		SDK_INLINE const qVector4& GetRight() const { return v1; }
		SDK_INLINE const qVector4& GetUp() const { return v2; }
		SDK_INLINE const qVector4& GetPosition() const { return v3; }

		// Helper for Transform / Camera Transform as they have swapped members...

		SDK_INLINE const qVector4& GetTransForward() const { return v2; }
		SDK_INLINE const qVector4& GetTransRight() const { return v0; }
		SDK_INLINE const qVector4& GetTransUp() const { return v1; }
	};

	class qQuaternion
	{
	public:
		f32 x, y, z, w;

		SDK_INLINE qQuaternion() {}
		SDK_INLINE qQuaternion(f32 f) : x(f), y(f), z(f), w(f) {}
		SDK_INLINE qQuaternion(f32 f0, f32 f1, f32 f2, f32 f3) : x(f0), y(f1), z(f2), w(f3) {}
		SDK_INLINE qQuaternion(const qVector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
	};

	struct qTransQuat
	{
		qQuaternion mRot;
		qVector3 mTrans;
	};

	/* Functions */

	SDK_SINLINE int* qGetDefaultSeed() { return SDK_VAR(int*, 0x203BC24); }

	SDK_SINLINE qVector2 qRandom(const qVector2& range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(qVector2, 0x1892E0, const qVector2&, int*)(range, pseed); }

	SDK_SINLINE qVector3 qRandom(const qVector3& range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(qVector3, 0x189420, const qVector3&, int*)(range, pseed); }

	SDK_SINLINE int qRandom(int range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(int, 0x1895E0, int, int*)(range, pseed); }

	SDK_SINLINE f32 qRandom(f32 range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(f32, 0x189620, f32, int*)(range, pseed); }

	SDK_SINLINE f32 qHeading2D(const qVector3& v1) { return SDK_CALL_FUNC(f32, 0x184CF0, const qVector3&)(v1); }

	SDK_SINLINE f32 qHeadingDifference2D(const qVector3& v1, const qVector3& v2) { return SDK_CALL_FUNC(f32, 0x184D60, const qVector3&, const qVector3&)(v1, v2); }

	SDK_SINLINE bool qDecomposeAffineEuler(qVector3* sol_a, qVector3* sol_b, qMatrix44* m, bool pos_bias) { 
		return SDK_CALL_FUNC(bool, 0x182C10, qVector3*, qVector3*, qMatrix44*, bool)(sol_a, sol_b, m, pos_bias);
	}

	SDK_SINLINE void qInverse(qMatrix44& d, const qMatrix44& m) { SDK_CALL_FUNC(void, 0x186740, qMatrix44&, const qMatrix44&)(d, m); }

	SDK_SINLINE void qInverseAffine(qMatrix44& d, const qMatrix44& m) { SDK_CALL_FUNC(void, 0x1870A0, qMatrix44&, const qMatrix44&)(d, m); }

	SDK_SINLINE void qLookAtMatrix(qMatrix44& dest, const qVector3& eye, const qVector3& target, const qVector3& up) {
		SDK_CALL_FUNC(void, 0x187750, qMatrix44&, const qVector3&, const qVector3&, const qVector3&)(dest, eye, target, up);
	}

	SDK_SINLINE bool qMakeMatrix(qMatrix44& dest, const qVector3& forward, const qVector3& up, const qVector3& translation, f32 threshold) {
		return SDK_CALL_FUNC(bool, 0x187970, qMatrix44&, const qVector3&, const qVector3&, const qVector3&, f32)(dest, forward, up, translation, threshold);
	}

	SDK_SINLINE void qRotateVectorZ(qVector2& dest, const qVector2& source, f32 radians) { 
		SDK_CALL_FUNC(void, 0x18A440, qVector2&, const qVector2&, f32)(dest, source, radians); 
	}

	SDK_SINLINE void qRotateVectorZ(qVector3& dest, const qVector3& source, f32 radians) { 
		SDK_CALL_FUNC(void, 0x18A4B0, qVector3&, const qVector3&, f32)(dest, source, radians);
	}

	SDK_SINLINE void qRotationMatrixAxis(qMatrix44& dest, const qVector3& axis, f32 radians) { 
		SDK_CALL_FUNC(void, 0x18A530, qMatrix44&, const qVector3&, f32)(dest, axis, radians);
	}

	SDK_SINLINE void qRotationMatrixEuler(qMatrix44& rot, const qVector3& angles) { 
		SDK_CALL_FUNC(void, 0x18A6A0, qMatrix44&, const qVector3&)(rot, angles);
	}

	SDK_SINLINE void qRotationMatrixX(qMatrix44& dest, f32 radians) { SDK_CALL_FUNC(void, 0x18A810, qMatrix44&, f32)(dest, radians); }
	SDK_SINLINE void qRotationMatrixY(qMatrix44& dest, f32 radians) { SDK_CALL_FUNC(void, 0x18AA00, qMatrix44&, f32)(dest, radians); }
	SDK_SINLINE void qRotationMatrixZ(qMatrix44& dest, f32 radians) { SDK_CALL_FUNC(void, 0x18AA80, qMatrix44&, f32)(dest, radians); }
	SDK_SINLINE void qRotationMatrixXYZDepreciated(qMatrix44& rot, const qVector3& radians) { SDK_CALL_FUNC(void, 0x18A890, qMatrix44&, const qVector3&)(rot, radians); }

	SDK_SINLINE void qTranslationMatrix(qMatrix44& dest, const qVector3& offset) { SDK_CALL_FUNC(void, 0x18C5E0, qMatrix44&, const qVector3&)(dest, offset); }
	SDK_SINLINE void qScaleMatrix(qMatrix44& dest, const qVector3& scale) { SDK_CALL_FUNC(void, 0x18ABA0, qMatrix44&, const qVector3&)(dest, scale); }
}