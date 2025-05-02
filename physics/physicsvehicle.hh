#pragma once

namespace UFG
{
	enum VehicleResetOptions
	{
		RESET_TO_LAST_GOOD,
		RESET_IN_PLACE,
		VELOCITY
	};

	class VehicleAction : public hkpUnaryAction
	{
	public:
		PhysicsWheeledVehicle* mVehicle;
		f32 mFlatTireDistance;
	};

	class VehicleParams
	{
	public:
		qSymbol mPhysicsPropertiesName;
		qSafePointer<SimObject> mSimObject;
		qString modelName;
		int firstFrontWheel;
		int lastFrontWheel;
		int firstRearWheel;
		int lastRearWheel;
	};
	SDK_ASSERT_SIZEOF(VehicleParams, 0x58);

	class VehicleCollisionListener : public hkpContactListener, public hkpEntityListener
	{
	public:
		hkpRigidBody* mBody;
		hkVector4f mInverseMassScale;
	};

	class PhysicsVehicle : public BasePhysicsObject
	{
	public:
		enum Lod : i32
		{
			LOD_UNINITIALIZED,
			LOD_LOW,
			LOD_MEDIUM,
			LOD_HIGH,
			LOD_NIS,
			LOD_RESOURCES_UNLOADED
		};

		WaterFloatingTrackerComponent* mWaterFloatingTrackerComponent;
		VehicleParams* mParams;
		qReflectHandle<BaseVehiclePhysicsDef> mDnaDefinition;
		RigidBodyComponent* mRigidBody;
		hkpRigidBody* mBulletCollider;
		hkpRigidBody* mVolumeRigidBody;
		PhysicsResourceHandle mCollisionMeshBundle;
		CollisionMeshData* mBodyCollisionMesh;
		CollisionMeshData* mBulletCollisionMesh;
		__declspec(align(16)) qMatrix44 mLastGoodPosition;
		qMatrix44 mBodyTransform;
		qMatrix44 mVolumeOffset;
		qMatrix44 mTargetTransform;
		qVector4 mLastFixupPosition;
		f32 mLastGoodPositionSampleTimer;
		VehicleCollisionListener* mCollisionListener;
		hkpReorientAction* mReorientActionRoll;
		hkpReorientAction* mReorientActionPitch;
		qSafePointer<class ParkourComponent> mParkourComponent;
		qSafePointer<class DynamicCoverComponent> mCoverComponent;
		Lod mDesiredLod;
		Lod mCurrentLod;
		bool mIsProxy;
		f32 mAirSteerYawRate;
		f32 mVerticalVelocityDampingDown;
		f32 mVerticalVelocityDampingUp;
		f32 mHighSpeedGovernor;
		f32 mReverseSpeedGovernor;
		f32 mSuperStopDrag;
		f32 mPitchStability;
		f32 mRollStability;
		f32 mSpeedKPH;
		f32 mDollarValue;
		f32 mRotMassScaleForCollisions;
		i16 mSystemId;
		u32 mNumWheels : 3;
		u32 mSuperStop : 1;
		u32 mIsAIControlled : 1;

		/* Virtual Functions */

		virtual void Reload(const qSymbol& physicsPropertiesName) = 0;
		virtual void Reset(VehicleResetOptions options) = 0;
		virtual void Update(qMatrix44* targetTransform, const VehicleInput& driverInput, f32 deltaTime) = 0;
		virtual void UpdateTransforms(const qMatrix44& rootTransform) = 0;
		virtual void Suspend() = 0;
		virtual void Restore() = 0;
		virtual void SetUserData(SimComponent* component) = 0;
		virtual void SetPositionAndOrientation(const qMatrix44& mat) = 0;
		virtual void Teleport(const qMatrix44& mat) = 0;
		virtual void SetEngineDamage(f32 damage) = 0;
		virtual bool IsInAir() = 0;
		virtual bool AreAllWheelsOnGround() = 0;
		virtual f32 GetHalfSteeringRange() = 0;
		virtual void SetLevelOfDetailInternal(Lod lod) = 0;
		virtual void applyForce(f32 deltaTime, const qVector3& force, const char* dbgName) = 0;
		virtual void applyForce(f32 deltaTime, const hkVector4f& force, const char* dbgName) = 0;
		virtual void applyTorque(f32 deltaTime, const qVector3& torque, const char* dbgName) = 0;
		virtual void applyTorque(f32 deltaTime, const hkVector4f& torque, const char* dbgName) = 0;
		virtual void applyAngularImpulse(const qVector3& imp, const char* dbgName) = 0;
		virtual void applyAngularImpulse(const hkVector4f& imp, const char* dbgName) = 0;
		virtual void applyLinearImpulse(const qVector3& imp, const char* dbgName) = 0;
		virtual void applyLinearImpulse(const hkVector4f& imp, const char* dbgName) = 0;
		virtual void applyPointImpulse(const qVector3& imp, const qVector3& p, const char* dbgName) = 0;
		virtual void applyPointImpulse(const hkVector4f& imp, const hkVector4f& p, const char* dbgName) = 0;
		virtual void setAngularVelocity(const qVector3& newVel, const char* dbgName) = 0;
		virtual void setAngularVelocity(const hkVector4f& newVel, const char* dbgName) = 0;
		virtual void setLinearVelocity(const qVector3& newVel, const char* dbgName) = 0;
		virtual void setLinearVelocity(const hkVector4f& newVel, const char* dbgName) = 0;

		/* Impl Functions */

		SDK_INLINE bool IsSuspended() { return !(mRigidBody->mFlags & RigidBody::INFLATED); }

		/* Functions */

		void ActivateVolume(u32 volumePropertyKey, const qVector3& halfExtents, const qMatrix44& markerOffset, f32 extendVolumeBy) {
			SDK_CALL_FUNC(void, 0x4547A0, void*, u32, const qVector3&, const qMatrix44&, f32)(this, volumePropertyKey, halfExtents, markerOffset, extendVolumeBy);
		}

		void ApplyImpulse(const qVector3& impulse, const qVector3& pos) { SDK_CALL_FUNC(void, 0x4585E0, void*, const qVector3&, const qVector3&)(this, impulse, pos); }
		void ClearMassScaleForCollisions() { SDK_CALL_FUNC(void, 0x45A630, void*)(this); }
		void ComputeBodyTransform() { SDK_CALL_FUNC(void, 0x45AF90, void*)(this); }
		hkVector4f ComputeLocalXTorsionalImpulseWS(f32 torqueFactor, const qVector3& collisionPoint) { 
			return SDK_CALL_FUNC(hkVector4f, 0x45B160, void*, f32, const qVector3&)(this, torqueFactor, collisionPoint); 
		}

		void DeactivateVolume() { SDK_CALL_FUNC(void, 0x4602E0, void*)(this); }
		void DeleteHavokComponents() { SDK_CALL_FUNC(void, 0x4611E0, void*)(this); }
		void DoKeyframes(f32 deltaTime) { SDK_CALL_FUNC(void, 0x461FB0, void*, f32)(this, deltaTime); }
		bool FixupTransformForGround(const qMatrix44& localWorld) { return SDK_CALL_FUNC(bool, 0x464F40, void*, const qMatrix44&)(this, localWorld); }
		void FlipVehicle(f32 torqueFactor, const qVector3& collisionPoint) { SDK_CALL_FUNC(void, 0x4654C0, void*, f32, const qVector3&)(this, torqueFactor, collisionPoint); }

		qVector3 GetAngularVelocity() 
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0x4660D0, void*, qVector3*)(this, &res); 
		}

		f32 GetMass() { return SDK_CALL_FUNC(f32, 0x466B80, void*)(this); }

		qVector3 GetVelocity()
		{ 
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0x4681D0, void*, qVector3*)(this, &res); 
		}

		void LoadProperties() { SDK_CALL_FUNC(void, 0x46BAB0, void*)(this); }
		void ResourceUnloaded(PhysicsResourceHandle* resource) { SDK_CALL_FUNC(void, 0x473C70, void*, PhysicsResourceHandle*)(this, resource); }
		void RestoreSuperStopDrag() { SDK_CALL_FUNC(void, 0x474270, void*)(this); }
		void SetControlledByAi(bool aiControlled) { SDK_CALL_FUNC(void, 0x474A10, void*, bool)(this, aiControlled); }
		void SetMassScaleForCollisions(f32 scaleMass, f32 scaleRotMass) { SDK_CALL_FUNC(void, 0x475170, void*, f32, f32)(this, scaleMass, scaleRotMass); }
		void SetVelocity(const qVector3& velocity) { SDK_CALL_FUNC(void, 0x475850, void*, const qVector3&)(this, velocity); }
		void SetupCollisionGeometry(const char* modelName) { SDK_CALL_FUNC(void, 0x4758A0, void*, const char*)(this, modelName); }

		/* Helpers */

		SDK_INLINE bool IsPhysicsBike()
		{
			if (auto dna = mDnaDefinition.mData) {
				return dna->mTypeUID == 0xD9CACAF3309C8794; // UFG::BikePhysicsDef
			}
			return 0;
		}

		SDK_INLINE bool IsPhysicsBoat()
		{
			if (auto dna = mDnaDefinition.mData) {
				return dna->mTypeUID == 0x1474DC53D3EE5EC5; // UFG::BoatPhysicsDef
			}
			return 0;
		}

		SDK_INLINE bool IsPhysicsCar()
		{
			if (auto dna = mDnaDefinition.mData) {
				return dna->mTypeUID == 0x6EEBFB6A483AAF1B; // UFG::CarPhysicsDef
			}
			return 0;
		}
	};
	SDK_ASSERT_SIZEOF(PhysicsVehicle, 0x260);

	class PhysicsWheeledVehicle : public PhysicsVehicle
	{
	public:
		hkpVehicleWheelCollide* mWheelCollider;
		VehicleInstance* mHavokVehicle;
		VehicleAction* mVehicleAction;
		Engine* mEngine;
		Transmission* mTransmission;
		Brakes* mBrakes;
		Steering* mSteering;
		VehicleAerodynamics* mAerodynamics;
		hkVector4f mHardPointChassisSpace[4];
		hkVector4f mSuspensionDirChassisSpace[4];
		qSafeArray<f32, 4> mCurrentSuspensionLength;
		qSafeArray<f32, 4> mSkidStrength;
		qSafeArray<f32, 4> mForwardSkidStrength;
		qSafeArray<f32, 4> mLateralSkidStrength;
		qSafeArray<f32, 4> mWheelSpinAngle;
		qSafeArray<qVector3, 4> mGroundPoints;
		qSafeArray<bool, 4> mGroundHits;
		qSafeArray<f32, 4> mRestingSuspensionLength;
		qSafeArray<f32, 4> mSuspensionUpTravelLimit;
		qSafeArray<f32, 4> mSuspensionDownTravelLimit;
		qSafeArray<f32, 4> mTireDamage;
		f32 mWheelRadius;
		f32 mPreviousSpeed;
		f32 mBurnoutMinSpeed;
		f32 mBurnoutMaxSpeed;
		f32 mBurnoutSpinTorqueAtLowSpeed;
		f32 mBurnoutSpinTorqueAtHighSpeed;
		f32 mBurnoutSpinFrontTireFrictionAtLowSpeed;
		f32 mBurnoutSpinFrontTireFrictionAtHighSpeed;
		f32 mBurnoutSpinRearTireFrictionAtLowSpeed;
		f32 mBurnoutSpinRearTireFrictionAtHighSpeed;
		f32 mBurnoutTorqueFactor_LowSpeed;
		f32 mBurnoutFwdThrustFactor_LowSpeed;
		f32 mBurnoutSideThrustFactor_LowSpeed;
		f32 mBurnoutTorqueFactor_HighSpeed;
		f32 mBurnoutFwdThrustFactor_HighSpeed;
		f32 mBurnoutSideThrustFactor_HighSpeed;
		f32 mJTurnSpinTorque;
		f32 mJTurnSpinFrontTireFriction;
		f32 mJTurnSpinRearTireFriction;
		f32 mBlownTireWobbleMagnitude;
		f32 mBlownTireWobbleFrequency;
		f32 mBlownTireDrag;
		f32 mBlownTireFrictionMultiplier;
		f32 mLodHeightFixupFront;
		f32 mLodHeightFixupRear;
		u32 mGroundFixupRaysRecieved : 3;
		u32 mAllWheelsOffGround : 1;
		u32 mAllWheelsOnGround : 1;
		u32 mUseNewBurnoutMethod : 1;
		u32 mWheelFrictionMultiplierOverriddenByFreeman : 1;

		/* Impl Functions */

		f32 GetMaxSuspensionLength(int i) { return mSuspensionDownTravelLimit[i] + mRestingSuspensionLength[i]; }
		f32 GetMinSuspensionLength(int i) { return mRestingSuspensionLength[i] - mSuspensionUpTravelLimit[i]; }
		f32 GetWheelAngle(int index) { return mWheelSpinAngle[index]; }
		bool IsInAir() { return mAllWheelsOffGround; }
		bool IsWheelOnGround(int wheelNum) { return (mHavokVehicle && mHavokVehicle->m_wheelsInfo.m_data[wheelNum].m_contactBody); }

		/* Functions */

		void AddWheelPhantoms() { SDK_CALL_FUNC(void, 0x456030, void*)(this); }

		void ApplyGroundFixup(const RayCastData& data, SimComponent* simComponent, void* callbackUserData) {
			SDK_CALL_FUNC(void, 0x457230, const RayCastData&, SimComponent*, void*)(data, simComponent, callbackUserData);
		}

		void ClearSteeringDeadZone() { SDK_CALL_FUNC(void, 0x45A6E0, void*)(this); }
		void DeleteWheeledVehicleComponents() { SDK_CALL_FUNC(void, 0x461630, void*)(this); }
		u32 GetNumWheelsOnGround() { return SDK_CALL_FUNC(u32, 0x466BF0, void*)(this); }
		u64 GetObjectPropertyHandleUidUnderWheel(int wheelNum) { return SDK_CALL_FUNC(u64, 0x466C40, void*, int)(this, wheelNum); }
		f32 GetRPM() { return SDK_CALL_FUNC(f32, 0x467010, void*)(this); }
		u64 GetSurfacePropertyHandleUidUnderWheel(int wheelNum) { return SDK_CALL_FUNC(u64, 0x467B20, void*, int)(this, wheelNum); }
		f32 GetWheelFrictionMultiplier(int wheelIndex) { return SDK_CALL_FUNC(f32, 0x468410, void*, int)(this, wheelIndex); }
		void GetWheelMatrix(u32 i, qMatrix44* mat) { SDK_CALL_FUNC(void, 0x468460, void*, u32, qMatrix44*)(this, i, mat); }

		void GetWheelTransforms(hkQsTransformf* axleTransform, hkQuaternionf* wheelTransform, bool clampSuspensionTravel) {
			SDK_CALL_FUNC(void, 0x468510, void*, hkQsTransformf*, hkQuaternionf*, bool)(this, axleTransform, wheelTransform, clampSuspensionTravel);
		}

		bool IsInDeepWater() { return SDK_CALL_FUNC(bool, 0x46AF50, void*)(this); }
		void LoadProperties() { SDK_CALL_FUNC(void, 0x46BBB0, void*)(this); }

		void QueueAsyncQueryForGroundFixup(bool useLongRaysToFindGround, bool hasDriver, bool isMoving) {
			SDK_CALL_FUNC(void, 0x471F50, void*, bool, bool, bool)(this, useLongRaysToFindGround, hasDriver, isMoving);
		}

		void Reload(const qSymbol& propertySetName) { SDK_CALL_FUNC(void, 0x472C20, void*, const qSymbol&)(this, propertySetName); }
		void RemoveWheelPhantoms() { SDK_CALL_FUNC(void, 0x473320, void*)(this); }
		void SetTireDamage(int index, f32 damage) { SDK_CALL_FUNC(void, 0x4755D0, void*, int, f32)(this, index, damage); }
		void SetWheelFrictionMultiplier(u32 wheelIndex, f32 multiplier) { SDK_CALL_FUNC(void, 0x475860, void*, u32, f32)(this, wheelIndex, multiplier); }
		void UpdateSkids(const VehicleInput& input, f32 speed_delta) { SDK_CALL_FUNC(void, 0x47FC50, void*, const VehicleInput&, f32)(this, input, speed_delta); }
	};
	SDK_ASSERT_SIZEOF(PhysicsWheeledVehicle, 0x450);
}