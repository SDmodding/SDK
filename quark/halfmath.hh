#pragma once

namespace UFG
{
	class qHalfFloat
	{
	public:
		u16 mRep;

		qHalfFloat() : mRep(0) {}
	};

	class qHalfVector2
	{
	public:
		qHalfFloat x, y;
	};

	class qHalfVector3
	{
	public:
		qHalfFloat x, y, z;
	};

	class qHalfVector4
	{
	public:
		qHalfFloat x, y, z, w;
	};
}