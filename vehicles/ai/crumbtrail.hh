#pragma once

namespace UFG
{
	class Crumb
	{
	public:
		qVector3 vPosition;
		f32 fLength;
		qVector3 vDirection;
		f32 fCurvature;
	};

	class CrumbTrail
	{
	public:
		RingBuffer<Crumb> mTrail;
	};
}