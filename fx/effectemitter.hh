#pragma once

namespace Render
{
	class EffectEmitterSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		u32 mEffectUIDs[8];
		u32 mNumEffects;
		UFG::qVector3 mGlobalVelocityMin;
		UFG::qVector3 mGlobalVelocityMax;
		UFG::qVector3 mLocalVelocityMin;
		UFG::qVector3 mLocalVelocityMax;
		UFG::qVector3 mJitter;
		f32 mGravityMin;
		f32 mGravityMax;
		f32 mLifeMin;
		f32 mLifeMax;
		f32 mDragMin;
		f32 mDragMax;
		s8 mJitterType;
		bool mRandomlySpawnOne;
	};

	class EffectEmitterSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_EffectEmitterSettings, EffectEmitterSettings>
	{
	public:
	};
}