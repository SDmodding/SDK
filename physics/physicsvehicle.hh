#pragma once

namespace UFG
{
	enum VehicleResetOptions
	{
		RESET_TO_LAST_GOOD,
		RESET_IN_PLACE,
		VELOCITY
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
		qVector3 GetAngularVelocity() { return SDK_CALL_FUNC(qVector3, 0x4660D0, void*)(this); }
		void GetMass() { SDK_CALL_FUNC(void, 0x466B80, void*)(this); }
		qVector3 GetVelocity() { return SDK_CALL_FUNC(qVector3, 0x4681D0, void*)(this); }
		void LoadProperties() { SDK_CALL_FUNC(void, 0x46BAB0, void*)(this); }
		void Reload(const qSymbol& physicsPropertiesName) { SDK_CALL_FUNC(void, 0x472BC0, void*, const qSymbol&)(this, physicsPropertiesName); }
		void Reset(VehicleResetOptions options) { SDK_CALL_FUNC(void, 0x473510, void*, VehicleResetOptions)(this, options); }
		void ResourceUnloaded(PhysicsResourceHandle* resource) { SDK_CALL_FUNC(void, 0x473C70, void*, PhysicsResourceHandle*)(this, resource); }
		void Restore() { SDK_CALL_FUNC(void, 0x473EA0, void*)(this); }
		void RestoreSuperStopDrag() { SDK_CALL_FUNC(void, 0x474270, void*)(this); }
		void SetControlledByAi(bool aiControlled) { SDK_CALL_FUNC(void, 0x474A10, void*, bool)(this, aiControlled); }
		void SetMassScaleForCollisions(f32 scaleMass, f32 scaleRotMass) { SDK_CALL_FUNC(void, 0x475170, void*, f32, f32)(this, scaleMass, scaleRotMass); }
		void SetPositionAndOrientation(const qMatrix44& mat) { SDK_CALL_FUNC(void, 0x475440, void*, const qMatrix44&)(this, mat); }
		void SetUserData(SimComponent* component) { SDK_CALL_FUNC(void, 0x475750, void*, SimComponent*)(this, component); }
		void SetVelocity(const qVector3& velocity) { SDK_CALL_FUNC(void, 0x475850, void*, const qVector3&)(this, velocity); }
		void SetupCollisionGeometry(const char* modelName) { SDK_CALL_FUNC(void, 0x4758A0, void*, const char*)(this, modelName); }
		void Teleport(const qMatrix44& mat) { SDK_CALL_FUNC(void, 0x4767A0, void*, const qMatrix44&)(this, mat); }
		void UpdateTransforms(const qMatrix44& rootTransform) { SDK_CALL_FUNC(void, 0x4803D0, void*, const qMatrix44&)(this, rootTransform); }
	};
	SDK_ASSERT_SIZEOF(PhysicsVehicle, 0x260);
}