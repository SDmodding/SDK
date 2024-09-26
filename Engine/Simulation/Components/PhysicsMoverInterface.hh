#pragma once

namespace UFG
{
	//==========================================================================================
	// VehicleInput is only used in PhysicsMoverInterface so we define it here...

	class CVehicleInput
	{
	public:
		float mSteering;
		float mForwardWeightShift;
		float mGasBrakes;
		float mRawGasBrakes;
		uint32_t mInReverse : 1;
		uint32_t mForceNeutral : 1;
		uint32_t mHandBrakeSet : 1;
		uint32_t mDoWheelie : 1;
		uint32_t mDoOneEighty : 1;
		uint32_t mDoBurnout : 1;
		uint32_t mFreemanStopTask : 1;
		uint32_t mFreemanSteerTask : 1;
		uint32_t mFreemanPreventWheelie : 1;
		uint32_t mHasHumanDriver : 1;
		uint32_t mHasAiDriver : 1;
	};
	UFG_ASSERT_CLASS(CVehicleInput, 0x14);

	//==========================================================================================

	class CPhysicsMoverInterface : public SimComponent
	{
	public:
		void* m_UpdateInterfaceVfptr;
		qNode<CPhysicsMoverInterface> mNode;
		CVehicleInput mInput;

		UFG_PAD(0x21C);

		class CPhysicsVehicle* mPhysicsVehicle;
		void* mRammingState;
		float mPostRamImmunityTimer;
		qVector3 mBoundingBoxMin;
		qVector3 mBoundingBoxMax;
		float mForwardSpeed;
		float mOdometer;
		float mDamageMultiplierWorldCollisions;
		float mDamageMultiplierVehicleCollisions;
		float mDamageMultiplierAttack;
		float mDamageMultiplierBullets;
		float mDamageMultiplierTires;
		float mTireShotImpulse;
		float mTireBlownImpulse;
		float mWheelRenderAngle;
		float mLowLodThrottleAcceleration;
		float mLowLodBrakesAcceleration;
		float mLowLodCoastAcceleration;
		float mLowLodMaxSpeed;
		float mLowLodMaxLateralAcceleration;
		float mLowLodMinTurningRadius;
		float mAutoDeterioratingDamageThreshold;
		float mAutoDeterioratingDamageRate;
		float mNotMovingTime;
		float mPropellerAngle;
		int mGroundFixupRequired;
		int mAxleBoneId[4];

		// Right wheel check: (x % 2) == 1 
		int mWheelBoneId[4];

		int mMotorBoneId[2];
		int mPropellerBoneId[2];
		int mNumWheels;
		int mLockAtHighLODMode;
		float mLockAtHighLODTime;
		float mVehicleCollisionMinImpulseRequiredToTakeDamage;
		float mVehicleCollisionDamageDealtAtMinImpulse;
		float mVehicleCollisionDamageDealtAtMaxImpulse;
		float mVehicleCollisionDamageDealtAtMinRamImpulse;
		float mVehicleCollisionDamageDealtAtMaxRamImpulse;
		float mVehicleCollisionExtraDamageMultiplier;
		float mVehicleCollisionMinImpulseRequiredToDealDamage;
		float mVehicleCollisionMaxImpulseForDealingDamage;
		float mVehicleCollisionMinRamImpulseRequiredToDealDamage;
		float mVehicleCollisionMaxRamImpulseForDealingDamage;
		float mSecondsSinceAppliedSpeedBoostRewardFromVehicleTakedown;
		float mSecondsEngineHasBeenDeteriorating;
		qVector3 mRamVelocity;
		uint32_t mLockedAtLowLOD : 1;
		uint32_t mSuspended : 1;
		uint32_t mNotMoving : 1;
		uint32_t mNisMode : 1;
		uint32_t mCannotExplode : 1;
		bool mVehicleCollisionForceDamageDealer : 1;
		bool mIsRoofSliding : 1;
		bool mLastEngineDamageCouldBeATakedown : 1;
		bool mRamming : 1;
		bool mCollisionShouldTriggerExplosion : 1;
		bool mbWasEngineDeteriorating : 1;
		float mDistanceToHighLod;
		float mDistanceToMedLod;
		bool mDoorsLocked;
		bool mUntargetable;
		bool mCreatedWithTemporaryRig;
		eVehicleTrunkTypeEnum mTrunkType;

		static UFG_INLINE qList<CPhysicsMoverInterface>* GetList()
		{
			// You can itter through list (node) to get all physics mover interface active in the world.
			// mNode->GetPointerSub<offsetof(CPhysicsMoverInterface, mNode)>();
			return reinterpret_cast<qList<CPhysicsMoverInterface>*>(UFG_RVA(0x2091398));
		}

		UFG_INLINE void SetLOD(PhysicsVehicle::Lod p_Lod)
		{
			reinterpret_cast<void(__fastcall*)(void*, PhysicsVehicle::Lod)>(UFG_RVA(0x68A9B0))(this, p_Lod);
		}

		UFG_INLINE void RepairDamage()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x6899D0))(this);
		}

		UFG_INLINE float GetEngineDamage()
		{
			return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0x67A630))(this);
		}

		UFG_INLINE void SetEngineDamage(float p_Damage)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x68A5C0))(this, p_Damage);
		}

		UFG_INLINE void SetCannotExplode(bool p_CannotExplode)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x68A470))(this, p_CannotExplode);
		}

		UFG_INLINE bool AreAllWheelsOnGround()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x670840))(this);
		}

		UFG_INLINE void Reload(uint32_t p_Reason)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x6892E0))(this, p_Reason);
		}
	};
	UFG_ASSERT_CLASS(CPhysicsMoverInterface, 920);
}