#pragma once

namespace UFG
{
	enum RagdollQuality
	{
		RQ_LOW,
		RQ_STANDARD
	};

	class RagdollData : public qSafePointerNode<RagdollData>
	{
	public:
		hkaSkeleton* ragdollSkeleton;
		hkaSkeletonMapper* ragdollToHighResMapper;
		hkaSkeletonMapper* highResToRagdollMapper;
		qArray<int> mCollisionFilterInfo;
		qArray<int> mExtremityBoneIndices;
		int mLastCoreRagdollBone;
		int mLastCoreRagdollConstraint;
		f32 m_penetrationErrorVelocity;
		f32 m_penetrationImpulseMax;
		f32 m_proceduralBoneBlendWeight;
		f32 m_timeSinceLastUsed;
		RagdollQuality mQuality;
		u32 rigGuid;
		int mRefcount;
		hkaRagdollInstance* havokInstance;
	};
	SDK_ASSERT_SIZEOF(RagdollData, 0x80);

	class RagdollPenetrationRaycastInterface : public hkReferencedObject, public hkaRagdollRaycastInterface
	{
	public:
		hkpWorld* mWorld;
	};

	class Ragdoll : public BasePhysicsObject
	{
	public:
		enum CollisionState
		{
			CS_DYNAMIC,
			CS_KEYFRAMED_RAGDOLL_LAYER,
			CS_KEYFRAMED_RAGDOLL_LAYER_2,
			CS_KEYFRAMED_NO_COLLISION
		};

		hkMassProperties mMassProperties;
		hkaRagdollInstance* mRagdollInstance;
		hkaRagdollRigidBodyController* mRigidBodyController;
		hkaKeyFrameHierarchyUtility::ControlData mDefaultControlData;
		hkaKeyFrameHierarchyUtility::ControlData mKeyframedControlData;
		hkpEaseConstraintsAction* mEaseConstraintsAction;
		qSafePointer<RagdollData> mRagdollData;
		hkArray<hkQsTransformf> mSnapShotPoseMS;
		hkpAabbPhantom* mPhantom;
		RagdollPenetrationRaycastInterface* mRagdollRaycastInterface;
		DetectRagdollPenetration* mDetectRagdollPenetration;
		DetectRagdollPenetration::Output mPenetratedBones;
		u32 mUID;
		u16 mCollisionSystem;
		CollisionState mCollisionState;
		f32 m_penetrationErrorVelocity;
		f32 m_penetrationImpulseMax;
		int m_framesSinceInterpenetration;
		bool mWasCreatedFromCache;

		/* Functions */

		void AddToWorld() { SDK_CALL_FUNC(void, 0xA0A00, void*)(this); }

		void ApplyAngularImpulse(int bone, const hkVector4f& impulse, f32 connectionTransfer) {
			SDK_CALL_FUNC(void, 0xA0B30, void*, int, const hkVector4f&, f32)(this, bone, impulse, connectionTransfer);
		}

		void ApplyCorrectionImpulse(hkpRigidBody* rb, int boneId, int parentId) { SDK_CALL_FUNC(void, 0xA0C20, void*, hkpRigidBody*, int, int)(this, rb, boneId, parentId); }

		void ApplyImpulse(int bone, const hkVector4f& location, const hkVector4f& impulse) {
			SDK_CALL_FUNC(void, 0xA0F40, void*, int, const hkVector4f&, const hkVector4f&)(this, bone, location, impulse);
		}

		void CreateRagdollPenetrationUtil(hkpWorld* world) { SDK_CALL_FUNC(void, 0xA5F40, void*, hkpWorld*)(this, world); }
		void DampMotionOfExtremities(f32 deltaT) { SDK_CALL_FUNC(void, 0xA66E0, void*, f32)(this, deltaT); }
		void DisableConstraints() { SDK_CALL_FUNC(void, 0xA7440, void*)(this); }
		void EnableConstraints() { SDK_CALL_FUNC(void, 0xA7850, void*)(this); }

		void ForcePose(hkaSkeleton* skel, hkaPose* pose, hkQsTransformf& worldTransform) {
			SDK_CALL_FUNC(void, 0xA8C50, void*, hkaSkeleton*, hkaPose*, hkQsTransformf&)(this, skel, pose, worldTransform);
		}

		void GetHighResPose(hkaSkeleton* skel, hkaPose* pose, hkQsTransformf& worldTransform) {
			SDK_CALL_FUNC(void, 0xAA110, void*, hkaSkeleton*, hkaPose*, hkQsTransformf&)(this, skel, pose, worldTransform);
		}

		f32 GetLimitStiffness() { return SDK_CALL_FUNC(f32, 0xAA8E0, void*)(this); }
		f32 GetMotorMaxForce() { return SDK_CALL_FUNC(f32, 0xAA9D0, void*)(this); }
		f32 GetMotorMaxForceAtJoint(int boneIndex) { return SDK_CALL_FUNC(f32, 0xAAAA0, void*, int)(this, boneIndex); }
		void GetPelvisTransformWS(qMatrix44& transformWS) { SDK_CALL_FUNC(void, 0xAB150, void*, qMatrix44&)(this, transformWS); }
		f32 GetPositionTrackingStiffness() { return SDK_CALL_FUNC(f32, 0xAB270, void*)(this); }
		hkpRigidBody* GetRigidBody(int skeletonBoneID) { return SDK_CALL_FUNC(hkpRigidBody*, 0xAB2B0, void*, int)(this, skeletonBoneID); }
		int GetRigidBodyID(int skeletonBoneID) { return SDK_CALL_FUNC(int, 0xAB320, void*, int)(this, skeletonBoneID); }
		void InitializePoweredTracking() { SDK_CALL_FUNC(void, 0xACB50, void*)(this); }
		void InitializeVelocityTracking() { SDK_CALL_FUNC(void, 0xACB70, void*)(this); }
		void RemoveFromWorld() { SDK_CALL_FUNC(void, 0xAF980, void*)(this); }
		void ResetKeyframeControllerParams() { SDK_CALL_FUNC(void, 0xB0010, void*)(this); }
		void ScaleMass(f32 mu) { SDK_CALL_FUNC(void, 0xB03F0, void*, f32)(this, mu); }
		void SetMotorMaxForceAtJoint(f32 force, int skeletonBoneID) { SDK_CALL_FUNC(void, 0xB19E0, void*, f32, int)(this, force, skeletonBoneID); }
		void SetMotorState(int b, bool onOff) { SDK_CALL_FUNC(void, 0xB1AD0, void*, int, bool)(this, b, onOff); }
		void SetPositionTrackingStiffness(f32 p) { SDK_CALL_FUNC(void, 0xB1CB0, void*, f32)(this, p); }
		void SetPositionTrackingStiffnessAtJoint(f32 p, int skeletonBoneID) { SDK_CALL_FUNC(void, 0xB23E0, void*, f32, int)(this, p, skeletonBoneID); }
		void SetUserData(SimComponent* component) { SDK_CALL_FUNC(void, 0xB26D0, void*, SimComponent*)(this, component); }
		void SetVelocity(const qVector3& v) { SDK_CALL_FUNC(void, 0xB2780, void*, const qVector3&)(this, v); }
		void ShutdownPoweredTracking() { SDK_CALL_FUNC(void, 0xB2B50, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(Ragdoll, 0x170);
}