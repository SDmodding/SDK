#pragma once

namespace UFG
{
	class UIHKReticleWidget
	{
	public:
		enum ePart
		{
			PART_1,
			PART_2,
			PART_3,
			PART_4,
			MAX_RETICLE_PARTS,
			NUM_PISTOL_PARTS = 4,
			NUM_RIFLE_PARTS = 4,
			NUM_SHOTGUN_PARTS = 2
		};

		enum eState
		{
			STATE_INVALID,
			STATE_HIDE,
			STATE_FREE_AIM,
			STATE_LOCKED_AIM
		};

		bool mChanged;
		bool mStateChanged;
		bool mFactionChanged;
		bool mTypeChanged;
		eState mState;
		bool mVisible;
		f32 mScreenX;
		f32 mScreenY;
		f32 mRadius;
		f32 mfSizeMin;
		f32 mfSizeMax;
		f32 mfSizeCurrent;
		bool mLockAnimationPlaying;
		bool mLockAnimationChanged;
		bool mHasAmmo;
		qVector2 mDefaultReticleOffset[4][4];
		eFactionStandingEnum mTargetFaction;
		u32 mType;
		eHighlightModeEnum mHighlightMode;

		/* Functions */

		void HandleScreenInit(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5EBEC0, void*, UIScreen*)(this, screen); }
	};
}