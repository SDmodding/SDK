#pragma once

namespace UFG
{
	enum CharacterCollisionMode
	{
		CP_INVALID,
		CP_WALK,
		CP_CROUCH,
		CP_CRAWL,
		CP_DRIVING,
		CP_ENTER_EXIT_VEHICLE,
		CP_DISABLED,
		CP_SITTING,
		CP_COMBAT,
		CP_DEAD,
		CP_GRAPPLE,
		CP_GRAPPLE_SMALL,
		CP_COVER,
		CP_FREERUN,
		CP_NUM_SHAPES
	};

	class CharacterCollisionListener : public hkpContactListener
	{
	public:
		qSafePointer<CharacterPhysicsComponent> mCharacterPhysicsComponent;
	};

	class CharacterPhysicsParameters
	{
	public:
		f32 mCollisionHeight[CP_NUM_SHAPES];
		f32 mCollisionRadius[CP_NUM_SHAPES];
		f32 mMass;
		f32 mMaxClimableSlope;
		f32 mMaxForce;
	};

	class GroundProperties
	{
	public:
		qVector3 groundPosition;
		qVector3 groundNormal;
		f32 heightAboveGround;
		f32 maxOffGroundElevation;
		f32 timeOffGround;
		f32 latchedFallDistance;
		f32 latchedFallTime;
		u64 groundObjectHandleUid;
		u64 groundSurfaceHandleUid;
		hkpSurfaceInfo::SupportedState support;
		u32 isOnGround : 1;
		u32 isOnGroundFiltered : 1;
		u32 prevOnGround : 1;
		u32 partiallySupported : 1;
	};

	class CharacterPhysicsComponent : public SimComponent, public BasePhysicsObject, public qNode<CharacterPhysicsComponent>
	{
	public:
		enum { _TypeUID = 0x7A000001 };

		enum GrappleMode
		{
			GRAPPLE_REGULAR,
			GRAPPLE_SMALL
		};

		RebindingComponentHandle<RagdollComponent> mRagdollComponent;
		qSafePointer<WaterFloatingTrackerComponent> mWaterTracker;
		qSafePointer<SimObject> mGrapplePartner;
		CharacterPhysicsParameters mParam;
		GroundProperties mGroundProperties;
		qVector3 mAdditiveVelocity;
		CharacterRigidBody* mHavokCharacter;
		hkpShape* mCollisionShapes[CP_NUM_SHAPES];
		CharacterCollisionListener* mCharacterListener;
		CharacterCollisionMode mCollisionModelType;
		CharacterCollisionMode mDesiredCollisionModelType;
		qVector3 mCurbBullShitHackNormal;
		f32 mSpeedZ;
		f32 mGravity;
		f32 mHeightFixup;
		f32 mFacing;
		i16 mAsyncRaycastBucket;
		u16 mCollisionSystem;
		u32 mGrappleState;
		u32 mFollowAnimationZ : 1;
		u32 mDetailedOnGroundCheck : 1;
		u32 mDidDetailedOnGroundTest : 1;
		u32 mEnableZFiltering : 1;
		u32 mBallisticMode : 1;
		u32 mVelocitySlopeMode : 1;
		u32 mEnableBullShitCurbHack : 1;
		u32 mIsPlayer : 1;
		u32 mBullShitCurbHack : 1;

		/* Impl Functions */

		SDK_INLINE void ClearSuperMassive() { mHavokCharacter->m_superMassive = 0; }
		SDK_INLINE void DisableDetailedOnGroundCheck() { mDetailedOnGroundCheck = 0; }
		SDK_INLINE void EnableDetailedOnGroundCheck() { mDetailedOnGroundCheck = 1; }
		SDK_INLINE f32 GetHeight(CharacterCollisionMode model) { return mParam.mCollisionHeight[model]; }
		SDK_INLINE f32 GetRadius(CharacterCollisionMode model) { return mParam.mCollisionRadius[model]; }
		SDK_INLINE f32 GetRadius() { return mParam.mCollisionRadius[mCollisionModelType]; }
		SDK_INLINE hkpRigidBody* GetRigidBody() { return mHavokCharacter->m_character; }
		SDK_INLINE void SetCollisionModel(CharacterCollisionMode type) { mDesiredCollisionModelType = type; }
		SDK_INLINE void SetSuperMassive() { mHavokCharacter->m_superMassive = 1; }

		/* Functions */

		void ClearPairedGrapple() { SDK_CALL_FUNC(void, 0x45A690, void*)(this); }
		qVector3 GetVelocity() { return SDK_CALL_FUNC(qVector3, 0x468150, void*)(this); }
		f32 GetWaterElevation() { return SDK_CALL_FUNC(f32, 0x4683E0, void*)(this); }
		void GrappleFixup(f32 deltaT) { SDK_CALL_FUNC(void, 0x468630, void*, f32)(this, deltaT); }
		bool IsInWater() { return SDK_CALL_FUNC(bool, 0x46AF80, void*)(this); }
		void MagicCurbBullShitHack() { SDK_CALL_FUNC(void, 0x46BE00, void*)(this); }
		void PlaceOnGroundAfterNIS() { SDK_CALL_FUNC(void, 0x46F8A0, void*)(this); }
		void SetPairedGrappleMaster(CharacterPhysicsComponent* slave, GrappleMode mode) { SDK_CALL_FUNC(void, 0x475370, void*, CharacterPhysicsComponent*, GrappleMode)(this, slave, mode); }
		void SetPairedGrappleSlave(CharacterPhysicsComponent* master) { SDK_CALL_FUNC(void, 0x4753E0, void*, CharacterPhysicsComponent*)(this, master); }
		void SetVelocity(const qVector3& velocity) { SDK_CALL_FUNC(void, 0x4757C0, void*, const qVector3&)(this, velocity); }
	};
	SDK_ASSERT_SIZEOF(CharacterPhysicsComponent, 0x260);
}