#pragma once

namespace UFG::AIAwareness
{
	class SubProfileAnimation
	{
	public:
		bool mEnableHeadTrack;
		bool mEnableEyeTrack;
		bool mEnableSpineTrack;
		f32 mHeadTrackLimitX;
		f32 mHeadTrackLimitY;
		f32 mHeadTrackLimitZ;
		f32 mEyeTrackLimitX;
		f32 mEyeTrackLimitY;
		f32 mEyeTrackLimitZ;
		f32 mSpineTrackLimitX;
		f32 mSpineTrackLimitY;
		f32 mSpineTrackLimitZ;
		f32 mHeadTrackGain;
		f32 mEyeTrackGain;
		f32 mSpineTrackGain;
	};
	SDK_ASSERT_SIZEOF(SubProfileAnimation, 0x34);
}
