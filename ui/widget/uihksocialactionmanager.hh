#pragma once

// Move this to appropriate file.
namespace UFG
{
	class ScoredTarget
	{
	public:
		f32 m_fScore;
		SimObject* m_pSimObject;
	};
}

namespace UFG
{
	class UIHKSocialActionManager
	{
	public:
		qFixedArray<ScoredTarget, 100> mScoredTargets;
		qFixedArray<ScoredTarget, 5> mTargets;
		u32 mWidgetIndexToUpdate;
		bool mIconsReset;
		bool mSocialEnabled;

		/* Functions */

		void Init(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5ED560, void*, UIScreen*)(this, screen); }
	};
}