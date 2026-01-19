#pragma once

namespace Render
{
	class DynamicLightSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		UFG::qVector4 mColorKeys[4];
		f32 mColorKeyPositions[4];
		UFG::qVector3 mSizeKeys[4];
		f32 mSizeKeyPositions[4];
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
		s8 mLightshafts;
	};

	class DynamicLightSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_DynamicLightSettings, DynamicLightSettings>
	{
	public:
	};
}