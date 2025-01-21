#pragma once

namespace UFG
{
	enum eVehicleTrunkTypeEnum : u32
	{
		eVEHICLE_TRUNK_TYPE_NONE,
		eVEHICLE_TRUNK_TYPE_CAR_NARROW,
		eVEHICLE_TRUNK_TYPE_CAR_STANDARD,
		eVEHICLE_TRUNK_TYPE_CAR_WIDE,
		eVEHICLE_TRUNK_TYPE_CAR_WIDER,
		eVEHICLE_TRUNK_TYPE_VAN_STANDARD,
		eVEHICLE_TRUNK_TYPE_VAN_WIDE,
		eVEHICLE_TRUNK_TYPE_VAN_WIDER,
		eVEHICLE_TRUNK_TYPE_VAN_NARROW,
		NUM_VEHICLE_TRUNK_TYPES
	};

	class RammingState
	{
	public:
		enum ERamState : i32
		{
			ERS_Boosting,
			ERamState_BoostedWaitingToDecel,
			ERamState_DeceleratingToGoalSpeed,
			ERamState_DoneDecelWaitingToEnd
		};

		qSafePointer<SimObject> mTarget;
		ERamState mState;
		qVector3 mCounterSpin;
		qVector3 mVelocityToAdd;
		qVector3 mMotionIntentionDirection;
		f32 mForwardsness;
		f32 mOriginalForwardSpeedKPH;
		f32 mMinForwardSpeedKPH;
		f32 mMaxForwardSpeedKPH;
		f32 mMinAddSpeedKPH;
		f32 mMaxAddSpeedKPH;
		f32 mForwardSpeedPenaltyPercent;
		f32 mForwardSpeedPenaltyDecelKPHPS;
		f32 mNoTargetModifier;
		f32 mCounterSwerveModifier;
		f32 mSwerveImpulse;
		f32 mTargetMaxDistance;
		f32 mTargetForwardsVelocityModifier;
		f32 mTargetAngle;
	};

	class VehicleDamageState
	{
	public:
		qSafeArray<f32, 4> tireDamage;
		f32 engineDamage;
	};

	class PhysicsMoverInterface : public SimComponent, public UpdateInterface, public qNode<PhysicsMoverInterface>
	{
	public:
		enum { _TypeUID = 0xE4000001 };

		enum DamageType
		{
			dtWORLD_COLLISION,
			dtVEHICLE_COLLISION,
			dtBULLET,
			dtATTACK,
			dtSCRIPT
		};

		enum DestructState : i32
		{
			PRE_DESTRUCT,
			MID_DESTRUCT,
			POST_DESTRUCT
		};

		enum ELODLockMode : i32
		{
			ELODLockMode_FOREVER,
			ELODLockMode_TIMED,
			ELODLockMode_UNTIL_AT_REST,
			ELODLockMode_NOT_LOCKED
		};

		enum ReloadReason
		{
			RELOAD_AI,
			RELOAD_HUMAN,
			RELOAD_NAMED,
			RELOAD_TUNING_HUMAN,
			RELOAD_TUNING_AI
		};

		VehicleInput mInput;
		RebindingComponentHandle<VehicleDriverInterface> mDriverComponent;
		VehicleDamageState mDamageState;
		DestructState mDestructState;
		f32 mDestructTimer;
		f32 mDestructTimerInitial;
		f32 mDestructPercentage;
		qSafePointer<SimObject, SimObject> mLastDamageSource;
		qSymbol mPropertySetNameAI;
		qSymbol mPropertySetNameHuman;
		qSymbol mPropertySetExplosion;
		TargetSphere mTargetSpheres[5];
		VehicleParams mParameters;
		PhysicsVehicle* mPhysicsVehicle;
		RammingState* mRammingState;
		f32 mPostRamImmunityTimer;
		qVector3 mBoundingBoxMin;
		qVector3 mBoundingBoxMax;
		f32 mForwardSpeed;
		f32 mOdometer;
		f32 mDamageMultiplierWorldCollisions;
		f32 mDamageMultiplierVehicleCollisions;
		f32 mDamageMultiplierAttack;
		f32 mDamageMultiplierBullets;
		f32 mDamageMultiplierTires;
		f32 mTireShotImpulse;
		f32 mTireBlownImpulse;
		f32 mWheelRenderAngle;
		f32 mLowLodThrottleAcceleration;
		f32 mLowLodBrakesAcceleration;
		f32 mLowLodCoastAcceleration;
		f32 mLowLodMaxSpeed;
		f32 mLowLodMaxLateralAcceleration;
		f32 mLowLodMinTurningRadius;
		f32 mAutoDeterioratingDamageThreshold;
		f32 mAutoDeterioratingDamageRate;
		f32 mNotMovingTime;
		f32 mPropellerAngle;
		int mGroundFixupRequired;
		qSafeArray<int, 4> mAxleBoneId;
		qSafeArray<int, 4> mWheelBoneId;
		qSafeArray<int, 2> mMotorBoneId;
		qSafeArray<int, 2> mPropellerBoneId;
		int mNumWheels;
		ELODLockMode mLockAtHighLODMode;
		f32 mLockAtHighLODTime;
		f32 mVehicleCollisionMinImpulseRequiredToTakeDamage;
		f32 mVehicleCollisionDamageDealtAtMinImpulse;
		f32 mVehicleCollisionDamageDealtAtMaxImpulse;
		f32 mVehicleCollisionDamageDealtAtMinRamImpulse;
		f32 mVehicleCollisionDamageDealtAtMaxRamImpulse;
		f32 mVehicleCollisionExtraDamageMultiplier;
		f32 mVehicleCollisionMinImpulseRequiredToDealDamage;
		f32 mVehicleCollisionMaxImpulseForDealingDamage;
		f32 mVehicleCollisionMinRamImpulseRequiredToDealDamage;
		f32 mVehicleCollisionMaxRamImpulseForDealingDamage;
		f32 mSecondsSinceAppliedSpeedBoostRewardFromVehicleTakedown;
		f32 mSecondsEngineHasBeenDeteriorating;
		qVector3 mRamVelocity;
		u32 mLockedAtLowLOD : 1;
		u32 mSuspended : 1;
		u32 mNotMoving : 1;
		u32 mNisMode : 1;
		u32 mCannotExplode : 1;
		bool mVehicleCollisionForceDamageDealer : 1;
		bool mIsRoofSliding : 1;
		bool mLastEngineDamageCouldBeATakedown : 1;
		bool mRamming : 1;
		bool mCollisionShouldTriggerExplosion : 1;
		bool mbWasEngineDeteriorating : 1;
		f32 mDistanceToHighLod;
		f32 mDistanceToMedLod;
		bool mDoorsLocked;
		bool mUntargetable;
		bool mCreatedWithTemporaryRig;
		eVehicleTrunkTypeEnum mTrunkType;

		/* Impl Functions */

		SDK_INLINE bool CanApplySpeedBoostRewardFromVehicleTakedown() { return mSecondsSinceAppliedSpeedBoostRewardFromVehicleTakedown > 5.f; }
		SDK_INLINE f32 GetEngineDamage() { return mDamageState.engineDamage; }
		SDK_INLINE hkpRigidBody* GetRigidBody() { return (mPhysicsVehicle ? mPhysicsVehicle->mRigidBody->mBody : nullptr); }
		SDK_INLINE bool IsTireBlown(int tireIndex) { return mDamageState.tireDamage[tireIndex] >= 1.f; }

		/* Functions */

		void ActivateTargetSpheres() { SDK_CALL_FUNC(void, 0x66F250, void*)(this); }
		bool AreAllWheelsOnGround() { return SDK_CALL_FUNC(bool, 0x670840, void*)(this); }
		void AutoDeteriorateEngineIfNotAlready() { SDK_CALL_FUNC(void, 0x670FE0, void*)(this); }
		bool DamageEngine(SimObject* pAttackerSimObject, f32 damage, DamageType dt) { return SDK_CALL_FUNC(bool, 0x6757B0, void*, SimObject*, f32, DamageType)(this, pAttackerSimObject, damage, dt); }
		void DamageTire(SimObject* pAttackerSimObject, int tireIndex, f32 damage) { SDK_CALL_FUNC(void, 0x676100, void*, SimObject*, int, f32)(this, pAttackerSimObject, tireIndex, damage); }
		void DeactivateTargetSpheres() { SDK_CALL_FUNC(void, 0x6761E0, void*)(this); }
		void EnableSuperStop() { SDK_CALL_FUNC(void, 0x677920, void*)(this); }
		void FlipVehicle(f32 torqueFactor, const qVector3& collisionPoint) { SDK_CALL_FUNC(void, 0x6795A0, void*, f32, const qVector3&)(this, torqueFactor, collisionPoint); }
		qVector3 GetAngularVelocity() { return SDK_CALL_FUNC(qVector3, 0x6795C0, void*)(this); }
		void GetBoundingBoxLocalSpace(qVector3& min, qVector3& max) { SDK_CALL_FUNC(void, 0x6796B0, void*, qVector3&, qVector3&)(this, min, max); }
		f32 GetCurvatureLimit(f32 speed) { return SDK_CALL_FUNC(f32, 0x67A250, void*, f32)(this, speed); }
		qVector3 GetFacingDirection() { return SDK_CALL_FUNC(qVector3, 0x67A640, void*)(this); }
		f32 GetHalfSteeringRange() { return SDK_CALL_FUNC(f32, 0x67A6C0, void*)(this); }
		PhysicsVehicle::Lod GetLOD() { return SDK_CALL_FUNC(PhysicsVehicle::Lod, 0x67A700, void*)(this); }
		f32 GetLinearVelocityMagnitude() { return SDK_CALL_FUNC(f32, 0x67A720, void*)(this); }
		f32 GetLinearVelocityMagnitudeKPH() { return SDK_CALL_FUNC(f32, 0x67A780, void*)(this); }
		f32 GetWheelRadius() { return SDK_CALL_FUNC(f32, 0x67BA50, void*)(this); }
		void InitializeDestructCountdown() { SDK_CALL_FUNC(void, 0x67E430, void*)(this); }
		void InitiateRamming(const RammingState& rs) { SDK_CALL_FUNC(void, 0x67E8B0, void*, const RammingState&)(this, rs); }
		void LockHighLod(ELODLockMode eMode, f32 time) { SDK_CALL_FUNC(void, 0x67FDD0, void*, ELODLockMode, f32)(this, eMode, time); }
		void NotifyProxyModeChanged(SimObject::eProxyMode proxyMode) { SDK_CALL_FUNC(void, 0x681EF0, void*, SimObject::eProxyMode)(this, proxyMode); }
		void OverrideSuperStopDrag(bool bOverride, f32 fDrag) { SDK_CALL_FUNC(void, 0x685E40, void*, bool, f32)(this, bOverride, fDrag); }
		void PropertiesLoad(const SceneObjectProperties* pSceneObj, const component_PhysicsMover* dataPtr) { 
			SDK_CALL_FUNC(void, 0x687750, void*, const SceneObjectProperties*, const component_PhysicsMover*)(this, pSceneObj, dataPtr); 
		}
		void Reload(ReloadReason reason) { SDK_CALL_FUNC(void, 0x6892E0, void*, ReloadReason)(this, reason); }
		void Reload(ReloadReason reason, const qSymbol& propertySetName) { SDK_CALL_FUNC(void, 0x689340, void*, ReloadReason, const qSymbol&)(this, reason, propertySetName); }
		void RepairDamage() { SDK_CALL_FUNC(void, 0x6899D0, void*)(this); }
		void Reset(VehicleResetOptions options) { SDK_CALL_FUNC(void, 0x689A00, void*, VehicleResetOptions)(this, options); }
		void Restore() { SDK_CALL_FUNC(void, 0x689A50, void*)(this); }
		void SetCannotExplode(bool cannotExplode) { SDK_CALL_FUNC(void, 0x68A470, void*, bool)(this, cannotExplode); }
		void SetDamageStateEngineDamage(f32 damage) { SDK_CALL_FUNC(void, 0x68A5C0, void*, f32)(this, damage); }
		void SetLOD(PhysicsVehicle::Lod lod) { SDK_CALL_FUNC(void, 0x68A9B0, void*, PhysicsVehicle::Lod)(this, lod); }
		void SetOccupantTargetLocks(bool lock) { SDK_CALL_FUNC(void, 0x68AA60, void*, bool)(this, lock); }
		void SetTireDamage(int tireIndex, f32 totalDamage) { SDK_CALL_FUNC(void, 0x68B710, void*, int, f32)(this, tireIndex, totalDamage); }
		bool ShouldIgnoreBulletImpactDamageSphereEvent(SimObject* weaponOwnerSimObject) { return SDK_CALL_FUNC(bool, 0x68BCA0, void*, SimObject*)(this, weaponOwnerSimObject); }
		void StartSlide() { SDK_CALL_FUNC(void, 0x68C4E0, void*)(this); }
		void TriggerExplosion() { SDK_CALL_FUNC(void, 0x68D360, void*)(this); }
		void UnlockHighLod() { SDK_CALL_FUNC(void, 0x68EE20, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(PhysicsMoverInterface, 0x398);
}