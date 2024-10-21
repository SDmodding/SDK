#pragma once

class ITrack : public Expression::IMemberMap
{
public:
	u32 m_TrackClassNameUID;
	char mBreakPoint;
	char mDisable;
	char mMaster;
	ExpressionParameterFloat mMasterRate;
	f32 mTimeBegin;
	f32 mTimeEnd;
};
SDK_ASSERT_SIZEOF(ITrack, 0x38);

class TrackGroup : public Expression::IMemberMap
{
public:
	BinPtrArray<ITrack> mTracks;
};
SDK_ASSERT_SIZEOF(TrackGroup, 0x20);
