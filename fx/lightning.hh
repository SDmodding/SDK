#pragma once

namespace Render
{
	class LightningSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		UFG::qColour mColorAlphaKeys[4];
		f32 mColorKeyPositions[4];
		f32 mAlphaKeyPositions[4];
		f32 mCurveMin;
		f32 mCurveMax;
		u32 mTextureID;
		f32 mWidthMin;
		f32 mWidthMax;
		f32 mTexCoordScale;
		UFG::qVector2 mJitterDistance;
		f32 mLifeMin;
		f32 mLifeMax;
		f32 mEmissionRate;
		u32 mEmissionInit;
		f32 mSpeedMin;
		f32 mSpeedMax;
		f32 mLengthMin;
		f32 mLengthMax;
		u32 mHeadModelUID;
		u32 mTailModelUID;
		u32 mTexturePageU;
		u32 mTexturePageV;
	};

	class LightningSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_LightningSettings, LightningSettings>
	{
	public:
	};
}