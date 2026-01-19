#pragma once

namespace Render
{
	class CoronaFlareSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		struct Reflection
		{
			f32 mT;
			u32 mTextureUID;
			f32 mCoronaFlareScale;
			f32 mCoronaFlareAspect;
			UFG::qVector3 mColor;
		};

		s8 mReflectionCount;
		bool mCollapse;
		bool mFade;
		bool mFadeInvert;
		f32 mSizeX;
		f32 mSizeY;
		f32 mScaleY;
		u32 mInvertY;
		f32 mCollapseDistance;
		f32 mCollapseSpan;
		f32 mFadeDistance;
		f32 mFadeSpan;
		Reflection mReflections[8];
	};

	class CoronaFlareSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_CoronaFlareSettings, CoronaFlareSettings>
	{
	public:
	};
}