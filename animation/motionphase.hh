#pragma once

enum PhaseMark
{
	PM_NONE,
	PM_LEFT,
	PM_RIGHT
};

class MotionKey : public Expression::IMemberMap
{
public:
	f32 mTimeBegin;
};

class MotionPhase2 : public Expression::IMemberMap
{
public:
	qEnum<PhaseMark, u32> mPhaseMark;
	int mPhasePeriod;
	f32 mPhase;
	f32 mPhaseDuration;
};

class MotionPhaseChannel : public Expression::IMemberMap
{
public:
	BinPtrArray<MotionKey> mKeys;
};
