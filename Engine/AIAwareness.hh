#pragma once

namespace UFG
{
	namespace AIAwareness
	{
		class CEffector
		{
		public:

		};

		class CKnowledgeSpace
		{
		public:

		};

		class CProfile
		{
		public:

		};

		class CSubProfileAnimation
		{
		public:
			bool mEnableHeadTrack;
			bool mEnableEyeTrack;
			bool mEnableSpineTrack;
			float mHeadTrackLimitX;
			float mHeadTrackLimitY;
			float mHeadTrackLimitZ;
			float mEyeTrackLimitX;
			float mEyeTrackLimitY;
			float mEyeTrackLimitZ;
			float mSpineTrackLimitX;
			float mSpineTrackLimitY;
			float mSpineTrackLimitZ;
			float mHeadTrackGain;
			float mEyeTrackGain;
			float mSpineTrackGain;
		};
	}
}