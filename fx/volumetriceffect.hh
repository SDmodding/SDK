#pragma once

namespace Render
{
	class VolumetricEffectSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		struct DistanceScaleKey
		{
			f32 mDistance;
			f32 mScale;
		};

		UFG::qVector4 mColorKeys[4];
		f32 mColorKeyPositions[4];
		f32 mRadMin;
		f32 mRadMax;
		f32 mEmissionRate;
		u32 mEmissionInit;
		f32 mLifeMin;
		f32 mLifeMax;
		f32 mGravityMin;
		f32 mGravityMax;
		f32 mDragMin;
		f32 mDragMax;
		UFG::qVector3 mGlobalVelocityMin;
		UFG::qVector3 mGlobalVelocityMax;
		UFG::qVector3 mWrapRegionMin;
		UFG::qVector3 mWrapRegionMax;
		f32 mIntensity;
		f32 mBentNormals;
		f32 mLightingContribution;
		u32 mUseDistanceScale;
		DistanceScaleKey mDistanceScaleKeys[5];
	};

	class VolumetricEffectSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_VolumetricEffectSettings, VolumetricEffectSettings>
	{
	public:
	};
}