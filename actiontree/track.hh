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

template <typename T>
class Track : public ITrack
{
public:
};

class TrackGroup : public Expression::IMemberMap
{
public:
	BinPtrArray<ITrack> mTracks;

	/* Static Functions */

	SDK_SINLINE TrackGroup* Create() { return SDK_CALL_FUNC(TrackGroup*, 0x26C9B0)(); }
};
SDK_ASSERT_SIZEOF(TrackGroup, 0x20);
