#pragma once

namespace UFG
{
	class ActionTreeComponent;

	//-------------------------------------------------------------------
	// Enums
	//-------------------------------------------------------------------

	enum eAttackPhaseEnum : int
	{
		eATTACK_PHASE_INVALID,
		eATTACK_PHASE_EXECUTION,
		eATTACK_PHASE_COLLISION,
		eATTACK_PHASE_RECOVERY,
		NUM_ATTACK_PHASES
	};

	//-------------------------------------------------------------------
	// Classes
	//-------------------------------------------------------------------

	class CollisionInfo
	{
	public:
		u64 mPhysicsObjectPropertyHandleUID;
		u64 mAttackerPhysicsObjectPropertyHandleUID;
		u64 mSurfacePropertyHandleUID;
		u64 mAttackerSurfacePropertyHandleUID;
		qVector3 mHitLocation;
		qVector3 mHitImpulse;
		qVector3 mOtherVelocity;
		f32 mSpeed;
		f32 mForwardSpeed;
		f32 mEstimatedImpulseMagnitude;
	};
	SDK_ASSERT_SIZEOF(CollisionInfo, 0x50);

	class MeleeInfo
	{
	public:
		int mAttackLocationLateralID;
		int mAttackLocationHorizontalID;
		bool mAttackFromBehind;
		u32 mAttackMaterialUID;
		u32 mAudioIntensityUID;
		u32 mAttackIntensityUID;
		qVector3 mHitPosition;
		qVector3 mHitDirection;
		qVector3 mHitNormal;
		ActionPath mActionPath;
	};
	SDK_ASSERT_SIZEOF(MeleeInfo, 0x50);

	class HitRecord
	{
	public:
		bool mHitRecordProcessed;
		bool mIsDeadly;
		bool mDamageHandled;
		bool mEffectTriggered;
		int mAttackTypeID;
		int mDamage;
		qSafePointer<SimObject> mAttacker;
		f32 mTimeSinceHit;
		int mFramesSinceHit;
		MeleeInfo mMeleeInfo;
		ProjectileInfo mProjectileInfo;
		CollisionInfo mCollisionInfo;
		int mEffectBone;
		qVector3 mEffectOffset;
		f32 mDistanceFromExplosionSquared;
		ExplosionTypeInfo* mExplosionInfo;
		u32 mAttackerNetworkID;
		HitRecord* mNext;
	};
	SDK_ASSERT_SIZEOF(HitRecord, 0x128);

	class IncomingAttackInfo
	{
	public:
		eAttackPhaseEnum mAttackPhaseEnum;
		int mAttackTypeID;
		qSafePointer<SimObject> mAttacker;
		int mAttackLocationLateralID;
		int mAttackLocationHorizontalID;
		int mTimeSinceUpdated;
	};
	SDK_ASSERT_SIZEOF(IncomingAttackInfo, 0x30);

	//-------------------------------------------------------------------
	// Component
	//-------------------------------------------------------------------

	class HitReactionComponent : public SimComponent, public UpdateInterface, public qNode<HitReactionComponent>
	{
	public:
		struct StateVariables
		{
			float mAttackTimer;
			eAttackPhaseEnum mAttackPhaseEnum;
		};

		StateVariables mStateVariables;
		bool mHitRecordProcessing;
		u32 mReceiverDamageMultiplierPct;
		qSharedString mHitTreeFileName;
		ActionPath mHitReactionOpeningBranchFullPath;
		ActionNode* mHitTree;
		IncomingAttackInfo mIncomingAttackInfo;
		HitRecord mHitRecord;
		int mNumHits;
		RebindingComponentHandle<ActionTreeComponent> mActionTreeComponent;
		bool mWasProxy;

		/* Functions */

		void AddToCurrentHitRecord(const HitRecord& hitrecord) { reinterpret_cast<void(SDK_CALL*)(void*, const HitRecord&)>(SDK_RVA(0x521420))(this, hitrecord); }

		void ApplyBulletImpactImpulse(const qVector3& vPoint, const qVector3& vBulletVelocity, const ProjectileInfo& projectileInfo) { reinterpret_cast<void(SDK_CALL*)(void*, const qVector3&, const qVector3&, const ProjectileInfo&)>(SDK_RVA(0x5218A0))(this, vPoint, vBulletVelocity, projectileInfo); }
		
		void CleanUpHitRecords() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x522CE0))(this); }

		void HandleHitReaction(const HitRecord& hitrecord) { reinterpret_cast<void(SDK_CALL*)(void*, const HitRecord&)>(SDK_RVA(0x534420))(this, hitrecord); }

		void HandleIncomingAttack(const IncomingAttackInfo& incomingAttackInfo) { reinterpret_cast<void(SDK_CALL*)(void*, const IncomingAttackInfo&)>(SDK_RVA(0x534470))(this, incomingAttackInfo); }

		void InitActionTree() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x5363D0))(this); }

		void Reset() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x549810))(this); }

		void SetHitRecord(const HitRecord& hitrecord) { reinterpret_cast<void(SDK_CALL*)(void*, const HitRecord&)>(SDK_RVA(0x54D4E0))(this, hitrecord); }
	};
	SDK_ASSERT_SIZEOF(HitReactionComponent, 0x220);
}