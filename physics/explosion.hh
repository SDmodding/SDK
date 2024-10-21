#pragma once

namespace UFG
{
	class ExplosionTypeInfo
	{
	public:
		struct RangeValue
		{
			float range;
			float value;
		};

		qSymbol mPropertySetName;
		qSymbol mSimObjectToSpawn;
		u32 mExplosionEffectID;
		f32 mExplosionRadius;
		f32 mExplosionDuration;
		f32 mCameraShakeAmplitude;
		f32 mCameraShakeMaxDistanceSquared;
		RangeValue mMassMagnitudeValue[10];
		RangeValue mDistanceMagnitudeRatio[10];
		bool mExplosionNoDamage : 1;
		bool mExplosionCanTriggerVehicleExplosion : 1;
	};
	SDK_ASSERT_SIZEOF(ExplosionTypeInfo, 0xC0);
}