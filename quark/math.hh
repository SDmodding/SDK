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
}