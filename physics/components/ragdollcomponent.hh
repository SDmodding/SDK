#pragma once

namespace UFG
{
	class RagdollComponent : public SimComponent, public qSafePointerNode<RagdollComponent>, public qNode<RagdollComponent>
	{
	public:
		enum { _TypeUID = 0x82000001 };

		enum LevelOfDetail
		{
			LOD_UNDEFINED,
			LOD_LOW,
			LOD_HIGH
		};

		enum PoseState
		{
			STATE_VELOCITY_TRACKING,
			STATE_POWERED_TRACKING,
			STATE_TRANSITION_TO_POWERED,
			STATE_FORCE,
			STATE_UNINITIALIZED,
			STATE_KEYFRAME_TRACKING,
			STATE_FREEZE_TRACKING
		};

		bool mDebugDraw;
		Ragdoll* mRagdoll;
		SkeletalPose* mPose;
		f32 mRagDollWeight;
		f32 mVelocityFromProxyScale;
		PoseState mPoseState;
		PoseState mDesiredPoseState;
		LevelOfDetail mLevelOfDetail;
		LevelOfDetail mDesiredLevelOfDetail;
		__declspec(align(16)) qMatrix44 mPelvisRagdollWS;
		bool mLockHighLOD;
		int mAnimPelvisBoneIndex;
		int mReferenceCount;
		int mNumFramesInKeyframedMode;
		RebindingComponentHandle<CharacterAnimationComponent> mAnimationComponent;
		qSafePointer<Constraint> mConstraint[4];

		/* Static Functions */

		SDK_SINLINE RagdollComponent* Acquire(SimObject* obj) { return SDK_CALL_FUNC(RagdollComponent*, 0x454510, SimObject*)(obj); }
		SDK_SINLINE void Release(SimObject* obj, bool bForceRelease) { SDK_CALL_FUNC(void, 0x472950, SimObject*, bool)(obj, bForceRelease); }

		/* Impl Functions */

		SDK_INLINE hkArray<hkpRigidBody*>* GetRigidBodies() { return &mRagdoll->mRagdollInstance->m_rigidBodies; }

		/* Functions */

		bool AddConstraint(Constraint* constraint) { return SDK_CALL_FUNC(bool, 0x454E80, void*, Constraint*)(this, constraint); }

		void ApplyAngularImpulse(int bone, const qVector3& impulse, f32 connectionTransfer) {
			SDK_CALL_FUNC(void, 0x456310, void*, int, const qVector3&, f32)(this, bone, impulse, connectionTransfer);
		}

		void ApplyImpulse(int bone, const qVector3& location, const qVector3& impulse) {
			SDK_CALL_FUNC(void, 0x4585F0, void*, int, const qVector3&, const qVector3&)(this, bone, location, impulse);
		}

		void ClearConstraints() { SDK_CALL_FUNC(void, 0x45A5A0, void*)(this); }
		void CreateMyRagdoll(SimObject* simObject) { SDK_CALL_FUNC(void, 0x45E1E0, void*, SimObject*)(this, simObject); }
		void FeedPoseIntoCreature(const qMatrix44& worldTransform) { SDK_CALL_FUNC(void, 0x463EE0, void*, const qMatrix44&)(this, worldTransform); }
		void FeedProceduralBonesIntoCreature() { SDK_CALL_FUNC(void, 0x4640E0, void*)(this); }
		f32 GetLimitStiffness() { return SDK_CALL_FUNC(f32, 0x466B60, void*)(this); }
		f32 GetMotorMaxForce() { return SDK_CALL_FUNC(f32, 0x466BD0, void*)(this); }
		f32 GetPositionTrackingStiffness() { return SDK_CALL_FUNC(f32, 0x466FD0, void*)(this); }
		bool HasConstraints() { return SDK_CALL_FUNC(bool, 0x468970, void*)(this); }
		void Release(bool bForceRelease) { SDK_CALL_FUNC(void, 0x472930, void*, bool)(this, bForceRelease); }
		void RemoveConstraint(hkpRigidBody* owner, hkpRigidBody* external) { SDK_CALL_FUNC(void, 0x473140, void*, hkpRigidBody*, hkpRigidBody*)(this, owner, external); }
		void ResetState() { SDK_CALL_FUNC(void, 0x473BC0, void*)(this); }
		void Restore() { SDK_CALL_FUNC(void, 0x473FA0, void*)(this); }
		void ScaleMass(f32 mu) { SDK_CALL_FUNC(void, 0x4742E0, void*, f32)(this, mu); }
		void SetCollisionState(Ragdoll::CollisionState state) { SDK_CALL_FUNC(void, 0x474A00, void*, Ragdoll::CollisionState)(this, state); }
		void SetFriction(f32 mu) { SDK_CALL_FUNC(void, 0x474CA0, void*, f32)(this, mu); }
		void SetLimitStiffness(f32 p) { SDK_CALL_FUNC(void, 0x475160, void*, f32)(this, p); }
		void SetMotorMaxForce(f32 force) { SDK_CALL_FUNC(void, 0x475360, void*, f32)(this, force); }
		void SetPositionTrackingStiffness(f32 p) { SDK_CALL_FUNC(void, 0x475540, void*, f32)(this, p); }
		void SetPositionTrackingStiffnessAtJoint(f32 p, int skeletonBoneID) { SDK_CALL_FUNC(void, 0x475550, void*, f32, int)(this, p, skeletonBoneID); }
	};
	SDK_ASSERT_SIZEOF(RagdollComponent, 0x180);
}