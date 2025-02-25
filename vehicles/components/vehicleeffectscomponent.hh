#pragma once

namespace UFG
{
	class WheelModelsBinding
	{
	public:
		ModelType::ModelBindingRigid* mModelBindings[3];
	};

	class VehicleEffectsComponent : public SimComponent, public qNode<VehicleEffectsComponent>
	{
	public:
		enum { _TypeUID = 0xE2000001 };

		enum Lod
		{
			LOD_UNINITIALIZED,
			LOD_LOW,
			LOD_MEDIUM,
			LOD_HIGH,
			LOD_NIS,
			LOD_RESOURCES_UNLOADED
		};

		enum TireSmokeEffect
		{
			TireSmoke_Burnout = 1,
			TireSmoke_Slip = 2,
			TireSmoke_Skid = 4,
			TireSmoke_Drift = 8
		};

		enum TransformNodes
		{
			TRANSFORM_WHEEL_0,
			TRANSFORM_WHEEL_1,
			TRANSFORM_WHEEL_2,
			TRANSFORM_WHEEL_3,
			TRANSFORM_WHEEL_0_GR,
			TRANSFORM_WHEEL_1_GR,
			TRANSFORM_WHEEL_2_GR,
			TRANSFORM_WHEEL_3_GR,
			TRANSFORM_WHEEL_0_GR_DIR,
			TRANSFORM_WHEEL_1_GR_DIR,
			TRANSFORM_WHEEL_2_GR_DIR,
			TRANSFORM_WHEEL_3_GR_DIR,
			TRANSFORM_BUMPER_0,
			TRANSFORM_BUMPER_1,
			TRANSFORM_BUMPER_2,
			TRANSFORM_BUMPER_3,
			TRANSFORM_NUM
		};

		u32 mDamageTransferUID;
		qSafeArray<WheelModelsBinding, 4> mWheelModelBindings;
		EffectStatus mEffectStatusTable[EFFECT_TABLE_SIZE];
		RebindingComponentHandle<WaterFloatingTrackerComponent> mWaterFloatingTrackerComponent;
		RebindingComponentHandle<CompositeDrawableComponent> mDrawableComponent;
		RebindingComponentHandle<Render::FXSimComponent> mFXComponent;
		RebindingComponentHandle<PhysicsMoverInterface> mMoverComponent;
		RebindingComponentHandle<RoadSpaceComponent> mRoadSpaceComponent;
		RebindingComponentHandle<VehicleDriverInterface> mVehicleDriverComponent;
		qSafeArray<u32, 4> mSkidEmitters;
		qSafeArray<TransformNodeComponent*, TRANSFORM_NUM> mTransformNodes;
		qArray<u32> mWheelBoneId;
		qSafeArray<u32, 4> mBumperBoneId;
		qSafeArray<u32, 4> mSkidEffect;
		qSafeArray<u32, 4> mRimSparksEffect;
		qSafeArray<u32, 4> mBumperSparksEffect;
		qSafeArray<u32, 4> mWetSurfaceEffect;
		qSafeArray<PhysicsSurfaceProperties*, 4> mLastPhysicsSurfacProperty;
		HullSprayEffects mSprayEffects[2];
		qVector3 mSprayVector;
		qSymbolUC mEffectGroup;
		Lod mLevelOfDetail;
		u32 mNumWheels;
		u32 mNumQueuedHeadlightChanges;
		RoadNetworkLane* mPreTurnLane;
		f32 mSpeedLevelThreshold[4];
		u32 mSpeedLevel;
		u32 mRigUID;
		u32 mVandalizedDamage;
		DamageRig* mDamageRig;
		f32 mInitialGrimePercentage;
		f32 mInitialGrimeFactor;
		f32 mExtinguishFireCountdown;
		f32 mAirTime;
		f32 mSignalTimer;
		f32 mHeadlightFlashesLength;
		f32 mHeadlightFlashesTimer;
		f32 mHeadlightFlareOnTime;
		f32 mHeadlightFlareOffTime;
		bool mIsOffGround;
		u32 mFramesOffGround;
		bool mOnFire : 1;
		bool mBlownOutWindows : 1;
		bool mInWater : 1;
		bool mUsesHeadlightsInRain : 1;
		bool mScriptLightsEnabled : 1;
		bool mHeadlightsAlwaysOn : 1;
		bool mHeadlightsAlwaysOff : 1;
		bool mAreEffectMarkersResolved : 1;

		/* Impl Functions */

		SDK_INLINE bool AreCopLightsOn() { return mEffectStatusTable[FX_COPHEADLIGHTS].mState == EffectStatus::ACTIVE; }
		SDK_INLINE void TurnOffScriptedLights() { mScriptLightsEnabled = 0; }
		SDK_INLINE void TurnOnScriptedLights() { mScriptLightsEnabled = 1; }

		SDK_INLINE void TurnOffBrakelights() { TurnOffLightEffects(FX_BRAKELIGHTS); }
		SDK_INLINE void TurnOffInteriorLight() { TurnOffEffect_New(FX_INTERIORLIGHTS); }
		SDK_INLINE void TurnOffTaxiLight() { TurnOffEffect_New(FX_TAXILIGHTS); }
		SDK_INLINE void TurnOnBrakelights() { TurnOnLightEffects(FX_BRAKELIGHTS); }
		SDK_INLINE void TurnOnInteriorLight() { TurnOnEffect_New(FX_INTERIORLIGHTS); }
		SDK_INLINE void TurnOnTaxiLight() { TurnOnEffect_New(FX_TAXILIGHTS); }

		/* Functions */

		void BindEffectMarkers() { SDK_CALL_FUNC(void, 0x673430, void*)(this); }
		void BlowTire(int tireIndex) { SDK_CALL_FUNC(void, 0x673860, void*, int)(this, tireIndex); }
		void BreakGlass(eVehicleWindowTypeEnum eWindow) { SDK_CALL_FUNC(void, 0x673AE0, void*, eVehicleWindowTypeEnum)(this, eWindow); }
		void BreakGlass(const qVector3& position) { SDK_CALL_FUNC(void, 0x673900, void*, const qVector3&)(this, position); }
		void BreakGlassFX(u32 damageBoneID, f32 magnitude) { SDK_CALL_FUNC(void, 0x673B60, void*, u32, f32)(this, damageBoneID, magnitude); }
		void CreateDamageRig() { SDK_CALL_FUNC(void, 0x674850, void*)(this); }
		void CreateWheelDamageBinding() { SDK_CALL_FUNC(void, 0x675430, void*)(this); }
		void DamageGlass(const qVector3& position) { SDK_CALL_FUNC(void, 0x675F30, void*, const qVector3&)(this, position); }
		void DoRimAndBumperSparks(bool isMoving) { SDK_CALL_FUNC(void, 0x676BE0, void*, bool)(this, isMoving); }
		void DoWetSurfaceEffects(bool playFXs) { SDK_CALL_FUNC(void, 0x677250, void*, bool)(this, playFXs); }
		bool GetWheelIndexFromBoneID(u32 boneId, u32& wheelIndex) { return SDK_CALL_FUNC(bool, 0x67B960, void*, u32, u32&)(this, boneId, wheelIndex); }
		void InitializeEffect_New(VehicleEffectId id) { SDK_CALL_FUNC(void, 0x67E4A0, void*, VehicleEffectId)(this, id); }
		bool IsGlassBroken(eVehicleWindowTypeEnum eWindow) { return SDK_CALL_FUNC(bool, 0x67EF90, void*, eVehicleWindowTypeEnum)(this, eWindow); }
		bool IsGlassBroken(const qVector3& position) { return SDK_CALL_FUNC(bool, 0x67EDB0, void*, const qVector3&)(this, position); }
		void MeleeBasedDamage(const qVector3& position, f32 speed, f32 magnitude) { SDK_CALL_FUNC(void, 0x681B80, void*, const qVector3&, f32, f32)(this, position, speed, magnitude); }
		TransformNodeComponent* ObtainTransform(int transformIndex) { return SDK_CALL_FUNC(TransformNodeComponent*, 0x681FF0, void*, int)(this, transformIndex); }
		void PlayCollisionFX(Event* thisEvent, f32 magnitude) { SDK_CALL_FUNC(void, 0x686D80, void*, Event*, f32)(this, thisEvent, magnitude); }
		void QueueHeadlightFlashes(u32 numFlashes, f32 flashLength) { SDK_CALL_FUNC(void, 0x688440, void*, u32, f32)(this, numFlashes, flashLength); }
		void ShatterGlassFX(u32 damageBoneID) { SDK_CALL_FUNC(void, 0x68BC90, void*, u32)(this, damageBoneID); }

		void StartEffect(u32& effect, u32 effect_id, int bone_id, qMatrix44* offsetMatrix) {
			SDK_CALL_FUNC(void, 0x68C2D0, void*, u32&, u32, int, qMatrix44*)(this, effect, effect_id, bone_id, offsetMatrix);
		}

		void TurnOffCopLights() { SDK_CALL_FUNC(void, 0x68D7F0, void*)(this); }
		void TurnOffEffect_New(VehicleEffectId id) { SDK_CALL_FUNC(void, 0x68D840, void*, VehicleEffectId)(this, id); }
		void TurnOffEffects(bool headlights) { SDK_CALL_FUNC(void, 0x68D950, void*, bool)(this, headlights); }
		void TurnOffExhaust() { SDK_CALL_FUNC(void, 0x68DB10, void*)(this); }
		void TurnOffFire() { SDK_CALL_FUNC(void, 0x68DB50, void*)(this); }
		void TurnOffHeadlights() { SDK_CALL_FUNC(void, 0x68DCA0, void*)(this); }
		void TurnOffLightEffects(VehicleEffectId id) { SDK_CALL_FUNC(void, 0x68DD20, void*, VehicleEffectId)(this, id); }
		void TurnOnCopLights() { SDK_CALL_FUNC(void, 0x68E020, void*)(this); }
		void TurnOnDestroyedEffect() { SDK_CALL_FUNC(void, 0x68E0B0, void*)(this); }
		void TurnOnDisabledEffect() { SDK_CALL_FUNC(void, 0x68E280, void*)(this); }
		void TurnOnEffect_New(VehicleEffectId id) { SDK_CALL_FUNC(void, 0x68E350, void*, VehicleEffectId)(this, id); }
		void TurnOnExhaust() { SDK_CALL_FUNC(void, 0x68E500, void*)(this); }
		void TurnOnFire() { SDK_CALL_FUNC(void, 0x68E590, void*)(this); }
		void TurnOnGenericEffectByDamageBoneID(VehicleEffectId id, u32 damageboneID) { SDK_CALL_FUNC(void, 0x68E690, void*, VehicleEffectId, u32)(this, id, damageboneID); }
		void TurnOnHeadlights(bool isNightTime) { SDK_CALL_FUNC(void, 0x68E770, void*, bool)(this, isNightTime); }
		void TurnOnLightEffects(VehicleEffectId id) { SDK_CALL_FUNC(void, 0x68E850, void*, VehicleEffectId)(this, id); }

		void TurnOnSkidSmoke(int wheelId, PhysicsSurfaceProperties* properties, TireSmokeEffect tireSmokeFX) {
			SDK_CALL_FUNC(void, 0x68EB40, void*, int, PhysicsSurfaceProperties*, TireSmokeEffect)(this, wheelId, properties, tireSmokeFX);
		}
	};
	SDK_ASSERT_SIZEOF(VehicleEffectsComponent, 0x760);
}