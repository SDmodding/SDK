#pragma once

namespace UFG
{
	class qVector2
	{
	public:
		f32 x, y;

		qVector2() : x(0.f), y(0.f) {}
		qVector2(f32 fX, f32 fY) : x(fX), y(fY) {}
	};

	class qVector3
	{
	public:
		f32 x, y, z;

		qVector3() : x(0.f), y(0.f), z(0.f) {}
		qVector3(f32 fX, f32 fY, f32 fZ) : x(fX), y(fY), z(fZ) {}
	};

	class qVector4
	{
	public:
		f32 x, y, z, w;

		qVector4() : x(0.f), y(0.f), z(0.f), w(0.f) {}
		qVector4(f32 fX, f32 fY, f32 fZ, f32 fW) : x(fX), y(fY), z(fZ), w(fW) {}
	};

	class qMatrix44
	{
	public:
		qVector4 v0, v1, v2, v3;
	};

	class qQuaternion
	{
	public:
		f32 x, y, z, w;

		qQuaternion() : x(0.f), y(0.f), z(0.f), w(0.f) {}
		qQuaternion(f32 fX, f32 fY, f32 fZ, f32 fW) : x(fX), y(fY), z(fZ), w(fW) {}
	};

	/* Functions */

	SDK_SINLINE int* qGetDefaultSeed() { return SDK_VAR(int*, 0x203BC24); }

	SDK_SINLINE qVector2 qRandom(const qVector2& range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(qVector2, 0x1892E0, const qVector2&, int*)(range, pseed); }

	SDK_SINLINE qVector3 qRandom(const qVector3& range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(qVector3, 0x189420, const qVector3&, int*)(range, pseed); }

	SDK_SINLINE int qRandom(int range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(int, 0x1895E0, int, int*)(range, pseed); }

	SDK_SINLINE f32 qRandom(f32 range, int* pseed = qGetDefaultSeed()) { return SDK_CALL_FUNC(float, 0x189620, f32, int*)(range, pseed); }

	SDK_SINLINE float qHeading2D(const qVector3& v1) { return SDK_CALL_FUNC(float, 0x184CF0, const qVector3&)(v1); }

	SDK_SINLINE float qHeadingDifference2D(const qVector3& v1, const qVector3& v2) { return SDK_CALL_FUNC(float, 0x184D60, const qVector3&, const qVector3&)(v1, v2); }

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