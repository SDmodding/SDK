#pragma once

namespace Render
{
	class FlareSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		struct DistanceScaleKey
		{
			f32 mDistance;
			f32 mScale;
		};

		struct Reflection
		{
			CB_FlareSettings mSettings;
			u32 mTextureUID;
			f32 mFlareScale;
			f32 mFlareAspect;
			f32 mFadeStart;
			f32 mFadeEnd;
			f32 mFadeMid;
			f32 mFadeMidFactor;
			f32 mFadeInner;
			f32 mFadeOuter;
			s8 mPad[12];
		};

		Reflection mReflections[8];
		u32 mDrawType;
		f32 mProbeRadius;
		u32 mReflectionCount;
		u32 mRenderToEnvMap;
		u32 mUseDistanceScale;
		DistanceScaleKey mDistanceScaleKeys[5];
	};

	class FlareSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_FlareSettings, FlareSettings>
	{
	public:
	};
}