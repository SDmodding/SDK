#pragma once

namespace UFG
{
	//==========================================================================================
	// No clue where to put this atm...

	enum eAttackTypeID : int // AttackCollisionTypes.xml
	{
		eAttackTypeID_PropOnly,
		eAttackTypeID_CrowdPush,
		eAttackTypeID_CombatBuff,
		eAttackTypeID_Pushed,
		eAttackTypeID_Nudge,
		eAttackTypeID_PushAway,
		eAttackTypeID_Bump,
		eAttackTypeID_BumpLight,
		eAttackTypeID_Light,
		eAttackTypeID_Medium,
		eAttackTypeID_PlayerStrike,
		eAttackTypeID_Heavy,
		eAttackTypeID_Stun,
		eAttackTypeID_OverheadFinisher,
		eAttackTypeID_VehicleTireShot,
		eAttackTypeID_VehicleGasTankShot,
		eAttackTypeID_Projectile,
		eAttackTypeID_FakeAttacks,
		eAttackTypeID_KnockDown,
		eAttackTypeID_RemoveDriver,
		eAttackTypeID_BikeCrash,
		eAttackTypeID_WorldCollision,
		eAttackTypeID_Explosion,
		eAttackTypeID_ExplosionNoDamage,
		eAttackTypeID_FireDamage,
		eAttackTypeID_Scary,
	};

	//==========================================================================================

	class CCollisionInfo
	{
	public:
		uint64_t mPhysicsObjectPropertyHandleUID;
		uint64_t mAttackerPhysicsObjectPropertyHandleUID;
		uint64_t mSurfacePropertyHandleUID;
		uint64_t mAttackerSurfacePropertyHandleUID;
		qVector3 mHitLocation;
		qVector3 mHitImpulse;
		qVector3 mOtherVelocity;
		float mSpeed;
		float mForwardSpeed;
		float mEstimatedImpulseMagnitude;
	};
	UFG_ASSERT_CLASS(CCollisionInfo, 0x50);

	class CExplosionTypeInfo
	{
	public:
		qSymbol mPropertySetName;
		qSymbol mSimObjectToSpawn;
		uint32_t mExplosionEffectID;
		float mExplosionRadius;
		float mExplosionDuration;
		float mCameraShakeAmplitude;
		float mCameraShakeMaxDistanceSquared;
		float mMassMagnitudeValue[10][2];
		float mDistanceMagnitudeRatio[10][2];
		bool mExplosionNoDamage : 1;
		bool mExplosionCanTriggerVehicleExplosion : 1;
	};
	UFG_ASSERT_CLASS(CExplosionTypeInfo, 0xC0);

	class CMeleeInfo
	{
	public:
		int mAttackLocationLateralID;
		int mAttackLocationHorizontalID;
		bool mAttackFromBehind;
		uint32_t mAttackMaterialUID;
		uint32_t mAudioIntensityUID;
		uint32_t mAttackIntensityUID;
		qVector3 mHitPosition;
		qVector3 mHitDirection;
		qVector3 mHitNormal;
		CActionPath mActionPath;
	};
	UFG_ASSERT_CLASS(CMeleeInfo, 0x50);

	class CProjectileInfo
	{
	public:
		qSafePointer<CSimWeaponPropertiesComponent> m_pSOWPC;
		class CSubTargetingLocation* m_pSubTargetingLocation;
		bool m_bIsFullyAccurate;
		bool m_bIsHardLocked;
	};
	UFG_ASSERT_CLASS(CProjectileInfo, 0x28);

	class CHitRecord
	{
	public:
		bool mHitRecordProcessed;
		bool mIsDeadly;
		bool mDamageHandled;
		bool mEffectTriggered;
		eAttackTypeID mAttackTypeID;
		int mDamage;
		qSafePointer<CSimObject> mAttacker;
		float mTimeSinceHit;
		int mFramesSinceHit;
		CMeleeInfo mMeleeInfo;
		CProjectileInfo mProjectileInfo;
		CCollisionInfo mCollisionInfo;
		int mEffectBone;
		qVector3 mEffectOffset;
		float mDistanceFromExplosionSquared;
		CExplosionTypeInfo* mExplosionInfo;
		uint32_t mAttackerNetworkID;
		CHitRecord* mNext;
	};
	UFG_ASSERT_CLASS(CHitRecord, 0x128);

	class CIncomingAttackInfo
	{
	public:
		eAttackPhaseEnum mAttackPhaseEnum;
		int mAttackTypeID;
		qSafePointer<CSimObject> mAttacker;
		int mAttackLocationLateralID;
		int mAttackLocationHorizontalID;
		int mTimeSinceUpdated;
	};
	UFG_ASSERT_CLASS(CIncomingAttackInfo, 0x30);

	//==========================================================================================

	class CHitReactionComponent : public CSimComponent
	{
	public:
		void* m_UpdateInterfaceVfptr;
		qNode<CHitReactionComponent> mNode;
		float mAttackTimer;
		eAttackPhaseEnum mAttackPhaseEnum;
		bool mHitRecordProcessing;
		uint32_t mReceiverDamageMultiplierPct;
		qSharedString mHitTreeFileName;
		CActionPath mHitReactionOpeningBranchFullPath;
		CActionNode* mHitTree;
		CIncomingAttackInfo mIncomingAttackInfo;
		CHitRecord mHitRecord;
		int mNumHits;
		RebindingComponentHandle<CActionTreeComponent> mActionTreeComponent;
		bool mWasProxy;
	};
	UFG_ASSERT_CLASS(CHitReactionComponent, 0x220);
}