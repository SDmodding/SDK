#pragma once

namespace UFG
{
	struct EffectStatus_t
	{
		enum EState
		{
			Enabled = 3
		};

		EState mState;
		class CVehicleEffectState* mInternalState;
		uint32_t mQueuedToPlay : 1;
	};
	UFG_ASSERT_STRUCT(EffectStatus_t, 0x18);

	//================================================================================================================================

	class CVehicleEffectsComponent : public SimComponent
	{
	public:
		UFG_PAD(0x10);

		unsigned int mDamageTransferUID;

		UFG_PAD(0x60);
		//UFG::qSafeArray<UFG::WheelModelsBinding, 4> mWheelModelBindings;

		EffectStatus_t mEffectStatusTable[EFFECT_TABLE_SIZE];
		RebindingComponentHandle<class CWaterFloatingTrackerComponent> mWaterFloatingTrackerComponent;
		RebindingComponentHandle<class CCompositeDrawableComponent> mDrawableComponent;
		RebindingComponentHandle<class CFXSimComponent> mFXComponent;
		RebindingComponentHandle<class CPhysicsMoverInterface> mMoverComponent;
		RebindingComponentHandle<class CRoadSpaceComponent> mRoadSpaceComponent;
		RebindingComponentHandle<class CVehicleDriverInterface> mVehicleDriverComponent;
		unsigned long mSkidEmitters[4];
		CTransformNodeComponent* mTransformNodes[16];
		unsigned long mWheelBoneId[4];
		unsigned long mBumperBoneId[4];
		unsigned long mSkidEffect[4];
		unsigned long mRimSparksEffect[4];
		unsigned long mBumperSparksEffect[4];
		unsigned long mWetSurfaceEffect[4];
		void* mLastPhysicsSurfacProperty[4];

		UFG_PAD(0x50);
		//UFG::HullSprayEffects mSprayEffects[2];

		qVector3 mSprayVector;
		qSymbol mEffectGroup;
		unsigned int mLevelOfDetail;
		unsigned int mNumWheels;
		unsigned int mNumQueuedHeadlightChanges;

		UFG_PAD(0x4);
		class CRoadNetworkLane* mPreTurnLane;

		float mSpeedLevelThreshold[4];
		unsigned int mSpeedLevel;
		unsigned int mRigUID;
		unsigned int mVandalizedDamage;
		CDamageRig* mDamageRig;
		float mInitialGrimePercentage;
		float mInitialGrimeFactor;
		float mExtinguishFireCountdown;
		float mAirTime;
		float mSignalTimer;
		float mHeadlightFlashesLength;
		float mHeadlightFlashesTimer;
		float mHeadlightFlareOnTime;
		float mHeadlightFlareOffTime;
		bool mIsOffGround;
		unsigned int mFramesOffGround;
		unsigned __int32 mOnFire : 1;
		unsigned __int32 mBlownOutWindows : 1;
		unsigned __int32 mInWater : 1;
		unsigned __int32 mUsesHeadlightsInRain : 1;
		unsigned __int32 mScriptLightsEnabled : 1;
		unsigned __int32 mHeadlightsAlwaysOn : 1;
		unsigned __int32 mHeadlightsAlwaysOff : 1;
		unsigned __int32 mAreEffectMarkersResolved : 1;

		UFG_INLINE bool IsEffectEnabled(UFG::VehicleEffectId p_EffectID)
		{
			return mEffectStatusTable[p_EffectID].mState == EffectStatus_t::Enabled;
		}

		UFG_INLINE void TurnOnCopLights()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68E020))(this);
		}

		UFG_INLINE void TurnOffCopLights()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68D7F0))(this);
		}

		UFG_INLINE void TurnOnScriptedLights()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68EB30))(this);
		}

		UFG_INLINE void TurnOffScriptedLights()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68DFF0))(this);
		}

		UFG_INLINE void TurnOnHeadLights(bool p_bIsNightTime)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x68E770))(this, p_bIsNightTime);
		}

		UFG_INLINE void TurnOffHeadLights()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68DCA0))(this);
		}

		UFG_INLINE void TurnOnLightEffects(UFG::VehicleEffectId p_EffectID)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68E850))(this, p_EffectID);
		}

		UFG_INLINE void TurnOffLightEffects(UFG::VehicleEffectId p_EffectID)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68DD20))(this, p_EffectID);
		}

		UFG_INLINE void TurnOnEffect_New(UFG::VehicleEffectId p_EffectID)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68E350))(this, p_EffectID);
		}

		UFG_INLINE void TurnOffEffect_New(UFG::VehicleEffectId p_EffectID)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68D840))(this, p_EffectID);
		}

		UFG_INLINE void SetAllDamageMarkers(float p_fDamage, bool p_bTriggersOnly, bool p_bSuppressSoundEffects)
		{
			if (mDamageRig) {
				reinterpret_cast<void(__fastcall*)(void*, void*, float, bool, bool)>(UFG_RVA(0x3AEDD0))(mDamageRig, this, p_fDamage, p_bTriggersOnly, p_bSuppressSoundEffects);
			}
		}
	};
	UFG_ASSERT_CLASS(CVehicleEffectsComponent, 0x760);
}