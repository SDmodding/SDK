#pragma once

namespace Render
{
	enum eDynamicLightAnim
	{
		DYNAMICLIGHTANIM_ALWAYS_ON,
		DYNAMICLIGHTANIM_ANIMATED,
		DYNAMICLIGHTANIM_FLICKERING,
		NUM_DYNAMICLIGHTANIMTYPES
	};

	class DynamicLightSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		UFG::qVector4 mColorKeys[4];
		f32 mColorKeyPositions[4];

		// x: Radius
		// y: FOV Half Inner (Type == 1 only)
		// z: FOV Half Outer (Type == 1 only)
		UFG::qVector3 mSizeKeys[4];

		f32 mSizeKeyPositions[4];

		// 0 - Omni light
		// 1 - Spotlight
		u32 mType;

		u32 mAnimType;
		f32 mDecayPower;
		f32 mRadMin;
		f32 mRadMax;
		f32 mConeOuter;
		f32 mConeInner;
		f32 mShadowNear;
		u32 mTextureUID;
		bool mShadow;
		bool mSpecular;
		bool mFade;
		bool mFadeInvert;
		f32 mFadeDistance;
		f32 mFadeSpan;
		f32 mMinFlickerOnTime;
		f32 mMaxFlickerOnTime;
		f32 mMinFlickerOffTime;
		f32 mMaxFlickerOffTime;
		s8 mClipPlanes[6];
		s8 mClipPlaneCount;

		// Type must be 1
		s8 mLightshafts;
	};

	class DynamicLightSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_DynamicLightSettings, DynamicLightSettings>
	{
	public:
	};
}