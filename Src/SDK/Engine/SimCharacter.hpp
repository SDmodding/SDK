#pragma once

namespace UFG
{
	class CActionTreeComponent;
	// ...

	class CIntention
	{
	public:
		float mMotionIntentionSpeedRaw;
		qVector3 mMotionIntentionDirectionRaw;
		float mMotionIntentionSpeed;
		qVector3 mMotionIntentionDirection;
		bool mEnableManualStrafeFacingDirection;
		qVector3 mManualStrafeFacingDirection;
		qVector3 mFacingIntentionDirection;
		bool mDesireToLookAtPoint;
		qVector3 mDesiredLookAtPoint;
		bool mDesireToLookAtPointEye;
		qVector3 mDesiredLookAtPointEye;

		UFG_PAD(0x4C);

		unsigned __int64 mSignals;
		unsigned __int64 mActionRequests[9];
		char mActionRequestChargeTimes[548];

		void SetSpeed(float m_Value)
		{
			mMotionIntentionSpeedRaw = mMotionIntentionSpeed = m_Value;
		}

		void SetDirection(qVector3 m_Direction)
		{
			mMotionIntentionDirectionRaw = mMotionIntentionDirection = m_Direction;
		}

		void Set(unsigned int action_request, float chargeTime = 4.25f)
		{
			auto action_bitwise = (1i64 << (action_request & 0x3F));
			mActionRequests[(signed __int64)(signed int)action_request >> 6] |= action_bitwise;
			mActionRequestChargeTimes[action_request] = static_cast<char>(fminf(255.f, chargeTime * 60.f));
			mSignals |= action_bitwise;
		}

		bool Has(unsigned int action_request)
		{
			auto v10 = mActionRequests[(signed __int64)(signed int)action_request >> 6];
			return _bittest64((const signed __int64*)&v10, action_request & 0x3F);
		}
	};

	class CCharacterRigidBody
	{
	public:
	};

	class CCharacterControllerInterface : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		RebindingComponentHandle<CActionTreeComponent> m_pActionTreeComponent;
	};

	// Components
	class CHealthComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		bool m_bInitialized;
		float m_fHealth;
		float m_fMinHealth;
		float m_fMaxHealth;
		float m_fMaxUpgradedHealth;
		float m_NonPlayerDamageMultiplier;
		float m_ProjectileDamageMultiplier;
		float m_fHealthBoost;
		float m_fArmour;
		bool m_bIsKnockedOut;
		bool m_bIsInvulnerable;
		bool m_bIsTakingDamage;
		bool m_bRegenerativeHealthLossPenaltyAllowed;
		bool m_bHasDeathTouch;
		bool m_bHealthClampedToMinimum;
		float m_fRegenerativeHealthRate;
		float m_fRegenerativeHealthRatio;

		void SetHealth(int uHealth)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, void*)>(UFG_RVA(0x54D3D0))(this, uHealth, nullptr);
		}

		void SetRegenerativeHealthRatio(float fRegenerativeHealthRatio, bool saveSnapshot)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x54E570))(this, fRegenerativeHealthRatio, saveSnapshot);
		}
	};

	class CCharacterPropertiesComponent : public CSimObjectPropertiesComponent
	{
	public:
		UFG_PAD(0x18);

		bool mIsTired;
		bool m_ActionTreeStateFlag[10];

		UFG_PAD(0x1);

		eGenderEnum m_eGender;
		eCharacterTypeEnum m_eCharacterType;
		eFightingClassEnum m_eFightingClass;
		eFactionClassEnum m_eFactionClass;
		qSymbol m_symFactionClass;
	};

	class CActionTreeComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x68);

		bool mNisUpdated;
		const char* mActionTreeFileName;
		CActionContext* mpActionContext;
		CActionController mActionController;
	};

	class CHitReactionComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x18);

		float mAttackTimer;
		eAttackPhaseEnum mAttackPhaseEnum;
		bool mHitRecordProcessing;
		unsigned int mReceiverDamageMultiplierPct;
		qSharedString mHitTreeFileName;
		CActionPath mHitReactionOpeningBranchFullPath;
		CActionNode* mHitTree;

		struct IncomingAttackInfo_t
		{
			eAttackPhaseEnum mAttackPhaseEnum;
			int mAttackTypeID;
			qSafePointer<CSimObject> mAttacker;
			int mAttackLocationLateralID;
			int mAttackLocationHorizontalID;
			int mTimeSinceUpdated;
		};
		IncomingAttackInfo_t mIncomingAttackInfo;

		struct HitRecord_t
		{
			bool mHitRecordProcessed;
			bool mIsDeadly;
			bool mDamageHandled;
			bool mEffectTriggered;
			int mAttackTypeID;
			int mDamage;
			qSafePointer<CSimObject> mAttacker;
			float mTimeSinceHit;
			int mFramesSinceHit;
			/*UFG::MeleeInfo mMeleeInfo;
			UFG::ProjectileInfo mProjectileInfo;
			UFG::CollisionInfo mCollisionInfo;
			int mEffectBone;
			UFG::qVector3 mEffectOffset;
			float mDistanceFromExplosionSquared;
			UFG::ExplosionTypeInfo* mExplosionInfo;
			unsigned int mAttackerNetworkID;
			HitRecord_t* mNext;*/
		};
		HitRecord_t mHitRecord;

		/*int mNumHits;
		UFG::RebindingComponentHandle<UFG::ActionTreeComponent, 0> mActionTreeComponent;
		bool mWasProxy;*/
	};
	UFG_PAD(sizeof(CHitReactionComponent));

	class CAIScriptInterfaceComponent
	{
	public:

		void SetDesiredTarget(eTargetTypeEnum target_type, CSimObject* target_object)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, CSimObject*)>(UFG_RVA(0x386060))(this, target_type, target_object);
		}
	};

	class CAIActionTreeComponent
	{
	public:
		UFG_PAD(0xD8);
		CActionController mActionController;

		void OnAttach(CSimObject* object)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x377E00))(this, object);
		}

		void OnDetach()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x379620))(this);
		}
	};

	class CAICoverComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		void* m_pQuery;
		void* m_pCoverObject;
		void* m_pTargetedCoverPosition;
		void* m_pProbeCoverObject;
		void* m_pCurrentCoverPosition;
		void* m_pSyncCoverPosition;
		eCoverPopoutSideEnum m_ePopoutSide;
		qSafePointer<CSimObject> m_pSimTargetSync;
		qSafePointer<CSimObject> m_pSimTargetPopout;
		int m_iHoldCoverPositionRefs;
		int m_iAllowHoldCoverPositionUpdateRefs;
		int m_iSyncBoneID;
	};

	class CTargetingSystemPedBaseComponent : public CTargetingSystemBaseComponent
	{
	public:
		void OnAttach(CSimObject* object)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x53F000))(this, object);
		}

		void SetTargetLock(eTargetTypeEnum eTargetType, bool bLock, const bool bModifyCollisionAccordingToLock)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, bool, bool)>(UFG_RVA(0x54EE70))(this, eTargetType, bLock, bModifyCollisionAccordingToLock);
		}

		void AttackTarget(CSimObject* m_Target)
		{
			static eTargetTypeEnum m_AttackTypes[] =
			{
				eTARGET_TYPE_ATTACKER, eTARGET_TYPE_CLOSEST_PED, eTARGET_TYPE_FACING,
				eTARGET_TYPE_FOCUS, eTARGET_TYPE_AI_OBJECTIVE, eTARGET_TYPE_PLAYER,
				eTARGET_TYPE_STIMULUS_PRODUCER, eTARGET_TYPE_CONDITION_STIMULUS_PRODUCER, eTARGET_TYPE_LAST_THREAT, eTARGET_TYPE_ATTACKING
			};

			for (eTargetTypeEnum m_AttackType : m_AttackTypes)
			{
				SetTarget(m_AttackType, m_Target);
				SetTargetLock(m_AttackType, true, false);
			}
		}
	};

	class CAICharacterControllerBaseComponent : public CCharacterControllerInterface
	{
	public:
		CIntention m_Intention;
	};

	class CActiveAIEntityComponent
	{
	public:
		void AddSupplementaryAttackTarget(CSimObject* attack_target)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x340E10))(this, attack_target);
		}

		void AddThreatTarget(CSimObject* pTarget, float radius)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, float)>(UFG_RVA(0x341190))(this, pTarget, radius);
		}

		void SetCurrentObjective(eAIObjective objective)
		{
			reinterpret_cast<void(__fastcall*)(void*, eAIObjective, void*)>(UFG_RVA(0x3852B0))(this, objective, nullptr);
		}
	};

	class CCharacterPhysicsComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x160);

		qVector3 mAdditiveVelocity;

		UFG_PAD(0x4);

		CCharacterRigidBody* mHavokCharacter;
		void* mCollisionShapes[14];
		void* mCharacterListener;
		eCharacterCollisionMode mCollisionModelType;
		eCharacterCollisionMode mDesiredCollisionModelType;
		qVector3 mCurbBullShitHackNormal;
		float mSpeedZ;
		float mGravity;
		float mHeightFixup;
		float mFacing;
		__int16 mAsyncRaycastBucket;
		unsigned __int16 mCollisionSystem;
		unsigned int mGrappleState;
		unsigned __int32 mFollowAnimationZ : 1;
		unsigned __int32 mDetailedOnGroundCheck : 1;
		unsigned __int32 mDidDetailedOnGroundTest : 1;
		unsigned __int32 mEnableZFiltering : 1;
		unsigned __int32 mBallisticMode : 1;
		unsigned __int32 mVelocitySlopeMode : 1;
		unsigned __int32 mEnableBullShitCurbHack : 1;
		unsigned __int32 mIsPlayer : 1;
		unsigned __int32 mBullShitCurbHack : 1;
	};

	class CRagdollComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x30);

		void* mRagdoll;
		void* mPose;
		float mRagDollWeight;
		float mVelocityFromProxyScale;
		RagdollComponent::PoseState mPoseState;
		RagdollComponent::PoseState mDesiredPoseState;
		unsigned int mLevelOfDetail;
		unsigned int mDesiredLevelOfDetail;

		bool IsActive()
		{
			return (mPoseState == RagdollComponent::STATE_POWERED_TRACKING);
		}

		void ApplyAngularImpulse(int bone, qVector3* impulse, float connectionTransfer)
		{
			reinterpret_cast<bool(__fastcall*)(void*, int, qVector3*, float)>(UFG_RVA(0x456310))(this, bone, impulse, connectionTransfer);
		}
	};

	class CCharacterOccupantComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		unsigned int mTargetType;
		unsigned int mSeatIndex;

		UFG_PAD(0x18);

		CVehicleOccupantComponent* mCurrentVOC;

		CSimVehicle* GetCurrentVehicle()
		{
			if (mCurrentVOC)
				return reinterpret_cast<CSimVehicle*>(mCurrentVOC->m_pSimObject);

			return nullptr;
		}
	};

	class __declspec(align(16)) CCharacterSubjectComponent
	{
	public:
		UFG_PAD(0x130);

		qMatrix44 mHeadTransformation;
		qMatrix44 mCamboneTransformation;
		qMatrix44 mPelvisTransformation;
		qMatrix44 mSyncTransformation;
		qMatrix44 mTargetWorld;
		bool bElevationLock;
		float rLockedElevationDef;
		float rLockedElevationCam;
		float rLockedElevationHip;
		float rLockedElevationHed;
		float rLockedElevationFocusCreatureCambone;
		float rLockedElevationFocusCreaturePelvis;
		float rLockedElevationFocusCreatureHead;
		int mIsHostage;
		int mJogging;
		bool mSprinting;
		bool mFallingAttack;
		int mActionHijacking;
		int mWalking;
		qSymbol mContextOverrideScriptGlobal[8];
		qSymbol mContextOverrideFreemanNPC[8];
		qSymbol mContextOverrideFreemanPlayer[8];
		qSymbol mContextOverrideScriptLocal[8];
		int mTypeOverrideFreeman;
		bool bGotoRise;
		float rGotoRise;
		float rGotoRiseRate;
		float rGotoRisePatience;
		bool bGotoRadius;
		float rGotoRadius;
		float rGotoRadiusRate;
		float rGotoRadiusPatience;
		bool bGotoAngle;
		float rGotoAngle;
		float rGotoAngleRate;
		float rGotoAnglePatience;
		bool bGotoAngleWorldSpace;
		bool bGotoAngleUseSecond;
		float rGotoAngleSecond;
		bool bGotoAngleFarthestAngle;
		bool bGotoAngleAdditive;
		void* mParkourHandle;
		qVector3 mFilteredPosition;
		float mPositionFilterSpeed;
		qVector3 mFilteredVelocity;
		float mFilteredSpeed;
		float mVelocityFilterSpeed;
		int mBoneHead;
		int mBoneCamera;
		int mBonePelvis;
		int mBoneSync;
		qVector3 mHeadPosition;
		qVector3 mCambonePosition;
		qVector3 mPelvisPosition;
		qVector3 mSyncPosition;
		bool mHeadDirty;
		bool mCamboneDirty;
		bool mPelvisDirty;
		bool mSyncDirty;
		qVector3 mAntiJitterPosition;
		qVector3 mGrapplePosition;
		qVector3 mLastAliveHeadPosition;
		qBox mBox;
		float mRadius;
		RebindingComponentHandle<CCharacterPhysicsComponent> pCharacterPhysicsComponent;
		RebindingComponentHandle<CBaseAnimationComponent> pCharacterAnimationComponent;
		RebindingComponentHandle<CTargetingSystemBaseComponent> pTargetingSystemBaseComponent;
		RebindingComponentHandle<CCharacterSubjectComponent> pSocialTargetOverrideComponent;

		bool IsWalking()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x53C2F0))(this);
		}

		bool IsJogging()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x53B0A0))(this);
		}
	};

	class CCharacterNavComponent : public CSimComponent
	{
	public:
		void AddGoalPoint(CHavokNavPosition* npDestination, AiPathGoalMode goalMode, float speed, float fDestinationTolerance)
		{
			reinterpret_cast<void(__fastcall*)(void*, CHavokNavPosition*, AiPathGoalMode, float, float)>(UFG_RVA(0x263430))(this, npDestination, goalMode, speed, fDestinationTolerance);
		}
	};

	class CInventoryComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x1C);

		int m_InventoryItems[209];
		eInventoryItemEnum m_SellableItem;
		qSymbol m_SellableItemProp;
		bool m_InfiniteSellableItem;
		bool m_bCheatUnlimitedAmmo;
		bool m_bDebugDrawInventory;

		void Equip(CSimObject* pObjectToEquip, bool useEquipSlot = false, int inventoryEquipSlot = 0)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, bool, int)>(UFG_RVA(0x526F90))(this, pObjectToEquip, useEquipSlot, inventoryEquipSlot);
		}

		void UnEquip(int slot = 0, bool bDeleteFromWorld = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool, int)>(UFG_RVA(0x557A40))(this, slot, bDeleteFromWorld);
		}
	};

	class CAimingBaseComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x18);

		float m_fAimPositionDistance;
		float m_fAimTransitionRadPerS;
		float m_fAimTransitionMultiplier;
		int m_iAimOriginBoneID;
		qVector3 m_vAimOriginPosition;
		qVector3 m_vAimIntentionTargetPosition;
		qVector3 m_vAimPosition;
		qVector3 m_vAimIntention;
		qVector3 m_vAimDirectionLS;
		float m_fAccuracyUnclamped;
		float m_fAccuracyMinimum;
		float m_fAccuracyMaximum;
		float m_fAccuracyPenalty;
		float m_fAccuracyOverride;
		bool m_bEnsureMiss;

		UFG_PAD(0xE0);
	};

	class CAimingPlayerComponent : public CAimingBaseComponent
	{
	public:
		UFG_PAD(0x40);

		bool m_bFocusTargetProbed;
		bool m_bFocusTargetObstructed;
		bool m_bCameraZoomMode;
		bool m_bUsingCover;
		bool m_bSupressReticle;
		bool m_bPreventFreeAimSpeedModifier;
		bool m_bAimingControlsCamera;
		float m_fBlendedReticleSize;
		float m_fBlendedReticleRadius;
		float m_fOverrideReticleSize;
		float m_fAxisXSpeed;
		float m_fAxisYSpeed;
		float m_fDampenedAxisXSpeed;
		float m_fDampenedAxisYSpeed;
		float m_fAimObstructedDuration;
		qVector3 m_vFreeAimLastFramePosition;
		qVector3 m_vFreeAimCastOrigin;
		bool m_bFreeAimRootDirty;
		qVector3 m_vFreeAimRootPosSS;
		qQuaternion m_qFreeAimRootOriSS;
		bool m_bFreeAimRootMovementLock;
		qVector3 m_vFreeAimOrigin;
		qVector3 m_vFreeAimBaseOffset;
		qVector3 m_vFreeAimIntention;
		qVector3 m_vFreeAimTargetPosition;

		UFG_PAD(0x44);
		/*UFG::qSafePointer<UFG::SimObject, UFG::SimObject> m_FreeAimSimObject;
		UFG::qReflectHandle<UFG::PhysicsObjectProperties> m_FreeAimPhysicsObjectProperties;*/

		int m_iFreeAimOriginBoneID;
		int m_iFreeAimSyncBoneID;
		float m_fReticleBlend;
		float m_fReticleBlendRate;
		qVector2 m_vReticleLockedOnCoordsScreen;
		qVector2 m_vReticleBlendedCoordsScreen;
		qVector3 m_vFocusTargetSegA;
		qVector3 m_vFocusTargetSegB;
		qVector3 m_vFocusTargetClosestPos;
		qVector3 m_vFocusTargetSegClosestPos;
		float m_fFocusTargetRadius;
		float m_fFocusTargetDistanceSeg;
		bool m_bResetSoftLockOffset;
		AimingPlayerComponent::eSoftLockTypeEnum m_eSoftLockType;
		UFG::qVector3 m_vSoftLockOffset;
		float m_fFreeAimSpeedModifier;
		float m_fInterpolatedFreeAimConeClamp;
		UFG::eTargetTypeEnum m_eSnapFreeAimIntentionToTarget;

		UFG_PAD(0x20);
		/*UFG::qList<AimingSoftLockTask, AimingSoftLockList, 0, 0> m_AimingSoftLockTaskList;
		UFG::qList<AimingFreeAimConeClampTask, AimingFreeAimConeClampList, 0, 0> m_AimingFreeAimConeClampTaskList;*/

		__int8 m_bPerformAimObscuredCheck : 1;
		float m_fUnobscuredAimCheckDistance;
		float m_fUnobscuredAimTargetPositionPadDistance;
		float m_fUnobscuredAimNewPositionPadDistance;

		UFG_PAD(0x30);
		/*UFG::qSafePointer<UFG::SimObject, UFG::SimObject> m_pAimTargetPositionSimObject;
		UFG::qSafePointer<UFG::SimComponent, UFG::TransformNodeComponent> m_pAimTargetPositionTNC;*/

		AimingPlayerComponent::eAimBlendMode m_eAimBlendMode;
	};

	UFG_PAD(sizeof(CAimingPlayerComponent));

	// Main
	class CSimCharacter : public CSimObject
	{
	public:
		CCharacterPropertiesComponent* GetCharacterProperties()
		{
			CSimComponent* m_Component = m_Components.p[3].m_pComponent;

			// CharacterPropertiesComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xB2000005);
				else
					m_Component = GetComponentOfType(0xB2000005);
			}

			return reinterpret_cast<CCharacterPropertiesComponent*>(m_Component);
		}

		CAIScriptInterfaceComponent* GetAIScriptInterface()
		{
			CSimComponent* m_Component = m_Components.p[5].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterAIScriptInterfaceComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterAIScriptInterfaceComponent_TypeUID);
			}

			return reinterpret_cast<CAIScriptInterfaceComponent*>(m_Component);
		}

		CAICoverComponent* GetAICover()
		{
			CSimComponent* m_Component = nullptr;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0 && !((m_Flags >> 13) & 1) && !((m_Flags >> 12) & 1))
				m_Component = GetComponentOfType(CharacterAICoverComponent_TypeUID);
			else
				m_Component = GetComponentOfTypeHK(CharacterAICoverComponent_TypeUID);

			return reinterpret_cast<CAICoverComponent*>(m_Component);
		}

		CHealthComponent* GetHealth()
		{
			CSimComponent* m_Component = m_Components.p[6].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterHealthComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterHealthComponent_TypeUID);
			}

			return reinterpret_cast<CHealthComponent*>(m_Component);
		}

		CActionTreeComponent* GetActionTree()
		{
			CSimComponent* m_Component = m_Components.p[7].m_pComponent;

			// ActionTreeComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					m_Component = m_Components.p[6].m_pComponent;
				else if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xC8000001);
				else
					m_Component = GetComponentOfType(0xC8000001);
			}

			return reinterpret_cast<CActionTreeComponent*>(m_Component);
		}

		CBaseAnimationComponent* GetAnimation()
		{
			CSimComponent* m_Component = m_Components.p[9].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					m_Component = m_Components.p[9].m_pComponent;
				else if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterAnimationComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterAnimationComponent_TypeUID);
			}

			return reinterpret_cast<CBaseAnimationComponent*>(m_Component);
		}

		CHitReactionComponent* GetHitReaction()
		{
			CSimComponent* m_Component = m_Components.p[15].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					m_Component = m_Components.p[15].m_pComponent;
				else if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterHitReactionComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterHitReactionComponent_TypeUID);
			}

			return reinterpret_cast<CHitReactionComponent*>(m_Component);
		}

		CAIActionTreeComponent* GetAIActionTree()
		{
			CSimComponent* m_Component = m_Components.p[19].m_pComponent;

			// AIActionTreeComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					m_Component = m_Components.p[6].m_pComponent;
				else if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0x52000001);
				else
					m_Component = GetComponentOfType(0x52000001);
			}

			return reinterpret_cast<CAIActionTreeComponent*>(m_Component);
		}

		CTargetingSystemPedBaseComponent* GetTargetingSystemPed()
		{
			CSimComponent* m_Component = m_Components.p[20].m_pComponent;

			// TargetingSystemPedBaseComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xA0000003);
				else
					m_Component = GetComponentOfType(0xA0000003);
			}

			return reinterpret_cast<CTargetingSystemPedBaseComponent*>(m_Component);
		}

		CAICharacterControllerBaseComponent* GetAICharacterController()
		{
			CSimComponent* m_Component = m_Components.p[21].m_pComponent;

			// AICharacterControllerBaseComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0x44000003);
				else
					m_Component = GetComponentOfType(0x44000003);
			}

			return reinterpret_cast<CAICharacterControllerBaseComponent*>(m_Component);
		}

		CActiveAIEntityComponent* GetActiveAIEntity()
		{
			CSimComponent* m_Component = m_Components.p[22].m_pComponent;

			// AICharacterControllerBaseComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterActiveAIEntityComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterActiveAIEntityComponent_TypeUID);
			}

			return reinterpret_cast<CActiveAIEntityComponent*>(m_Component);
		}

		CCharacterPhysicsComponent* GetCharacterPhysics()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				m_Component = m_Components.p[27].m_pComponent;
			else
			{
				// CharacterPhysicsComponent::_TypeUID
				if ((m_Flags & 0x8000) == 0)
				{
					if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
						m_Component = GetComponentOfTypeHK(0x7A000001);
					else
						m_Component = GetComponentOfType(0x7A000001);
				}
				else
					m_Component = GetComponentOfTypeHK(0x7A000001);
			}

			return reinterpret_cast<CCharacterPhysicsComponent*>(m_Component);
		}

		CCharacterNavComponent* GetNav()
		{
			CSimComponent* m_Component = m_Components.p[36].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterNavComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterNavComponent_TypeUID);
			}

			return reinterpret_cast<CCharacterNavComponent*>(m_Component);
		}

		CCharacterSubjectComponent* GetCharacterSubject()
		{
			CSimComponent* m_Component = m_Components.p[37].m_pComponent;

			// CharacterPropertiesComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0x68000005);
				else
					m_Component = GetComponentOfType(0x68000005);
			}

			return reinterpret_cast<CCharacterSubjectComponent*>(m_Component);
		}

		CInventoryComponent* GetInventory()
		{
			CSimComponent* m_Component = m_Components.p[39].m_pComponent;

			// CharacterPropertiesComponent::_TypeUID
			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xAC000001);
				else
					m_Component = GetComponentOfType(0xAC000001);
			}

			return reinterpret_cast<CInventoryComponent*>(m_Component);
		}

		CRagdollComponent* GetRagdoll()
		{
			CSimComponent* m_Component = m_Components.p[42].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterRagdollComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterRagdollComponent_TypeUID);
			}

			return reinterpret_cast<CRagdollComponent*>(m_Component);
		}

		CCharacterOccupantComponent* GetCharacterOccupant()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				m_Component = m_Components.p[44].m_pComponent;
			else
			{
				// CharacterOccupantComponent::_TypeUID
				if ((m_Flags & 0x8000) == 0)
				{
					if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
						m_Component = GetComponentOfTypeHK(0x96000001);
					else
						m_Component = GetComponentOfType(0x96000001);
				}
				else
					m_Component = GetComponentOfTypeHK(0x96000001);
			}

			return reinterpret_cast<CCharacterOccupantComponent*>(m_Component);
		}

		CAimingPlayerComponent* GetAimingPlayer()
		{
			CSimComponent* m_Component = m_Components.p[47].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xA2000003);
				else
					m_Component = GetComponentOfType(0xA2000003);
			}

			return reinterpret_cast<CAimingPlayerComponent*>(m_Component);
		}
	};
}
#define Character_80sTriad 0x2965747A
#define Character_ACE 0x30704A5B
#define Character_Alex 0x72BC43A4
#define Character_AmandaCartwright 0x7F1E3BA3
#define Character_AmandaDate 0x9A9E9CB9
#define Character_AmandaDojo 0xC0CDA2A2
#define Character_AmbFemaleCaucasian 0x8396F588
#define Character_AmbMaleCaucasian 0xB5308CDF
#define Character_AmbSportBikeRider 0xC9C53EAC
#define Character_Amb_Business_F 0xD0E1AA4D
#define Character_Amb_Business_M 0xFBAA612C
#define Character_Amb_Business_M_d 0xE723FF84
#define Character_Amb_Business_WF 0x1C7961E3
#define Character_Amb_Business_WM 0x3732AA82
#define Character_AmbientFemale1 0xA24F9D35
#define Character_AmbientFemaleL 0x73360601
#define Character_AmbientFemaleM 0x77F71BB6
#define Character_AmbientFemaleU 0x1DEE2D7E
#define Character_AmbientFemale_shopper 0xF6DCB9CC
#define Character_AmbientMale1 0x6D8009BE
#define Character_AmbientMaleL 0xBCF9928A
#define Character_AmbientMaleL_NW 0xE6FFF70C
#define Character_AmbientMaleM 0xB8388F3D
#define Character_AmbientMaleNew 0x4F73B4A3
#define Character_AmbientMaleU 0xD221B9F5
#define Character_AmbientTest 0xF0170417
#define Character_BN_Chang 0xC141BB1D
#define Character_Bartender 0xCE6D2984
#define Character_Benny 0x90B3704F
#define Character_BigSmilesLee_Damage_HD 0x2E8D8777
#define Character_Bookie 0x34780E41
#define Character_Bouncer01 0xBB15996D
#define Character_Bouncer02 0xB656BFB4
#define Character_BouncerBoss01 0x3EDE3F42
#define Character_Brawler01 0xE26B9B6F
#define Character_BrokenNoseJiang 0x205E98A6
#define Character_BrokenNoseJiangFuneral 0x30312C63
#define Character_BusDriverMale 0x187B2C0
#define Character_ChopShopAccountant 0x54F6E3C5
#define Character_ChopShopMale01 0xC36AE956
#define Character_ChopShopMale02 0xCE29CF8F
#define Character_ClubGirl 0xF462AD30
#define Character_ClubberFemale 0xAAB1DCB5
#define Character_ClubberMale 0xEEF1B115
#define Character_CollegeFemale 0x5DD667D2
#define Character_CollegeMale 0xA00BCE98
#define Character_CommonPedestrian 0xB83AE074
#define Character_Conroy 0x7D6166F3
#define Character_Conroy_Amb 0xB499C460
#define Character_Conroy_tutorial 0x38CA7EFC
#define Character_Construction 0x75C360A1
#define Character_CookMale 0x621D8D8C
#define Character_Crystal 0x1E5C9287
#define Character_CultLeader 0xAAD4D4B3
#define Character_DJ_Female 0xC5BDA5C4
#define Character_Dancer 0xD21D7DCF
#define Character_Delivery 0x339C21C2
#define Character_DeliveryNW 0x3BC239A6
#define Character_DeliveryNoProps 0x97C17AFC
#define Character_DirtyMonk 0xCDE6EAD9
#define Character_DockWorker 0x70825FDA
#define Character_DockWorkerNW 0x6E87143
#define Character_DockWorkerThug 0xBCEA25B4
#define Character_DoctorFemale 0x7886125E
#define Character_DoctorJaiBe 0xDE663F22
#define Character_DoctorMale 0x5ECB2AE4
#define Character_DoctorTang 0x2528A09B
#define Character_DogeyesDamaged_HD 0x39B22C54
#define Character_DrunkClubberFemale 0xE4E49E07
#define Character_DrunkClubberMale 0xE7D52C36
#define Character_Duke 0xD2F1348E
#define Character_DukeTutorial 0x3978CDD8
#define Character_EMT 0x105CC274
#define Character_E_SS_WeakMonk 0x895DE9A0
#define Character_ElderlyAmbFemM 0xF0A18C51
#define Character_ElderlyAmbFemMNoCane 0x138EB4B
#define Character_ElderlyAmbMaleM 0x604760CA
#define Character_ElderlyAmbMaleNP 0xE1B9F843
#define Character_ElderlyFemaleU 0x62A9CBFC
#define Character_FM_Male_Worker 0x2898465
#define Character_FM_Worker 0xC84C9722
#define Character_Fireman 0x9CFE2C55
#define Character_FloristGirl 0xCD1FD0AA
#define Character_GamblerFemale01 0x3C931C35
#define Character_GamblerFemale02 0x31D03AEC
#define Character_GamblerFemale03 0x3511275B
#define Character_GamblerMale01 0x2B5236E
#define Character_GamblerMale02 0xFF605B7
#define Character_GamblerMale03 0xB371800
#define Character_GamblerMale04 0x15704805
#define Character_GamblerMale05 0x11B155B2
#define Character_GamblerMale06 0x1CF2736B
#define Character_GamblerMale07 0x18336EDC
#define Character_GamblerMale08 0x207CD361
#define Character_GamblerMale09 0x24BDCED6
#define Character_Gigi 0x5CCB612B
#define Character_Grappler01 0x53268323
#define Character_Horseface 0xA06EF9D5
#define Character_HotShot 0x7746B9AC
#define Character_IllyanaDate 0xF961D932
#define Character_JackieMovingUp 0x302BF7C
#define Character_JackieMovingUpDead 0x53B87D70
#define Character_JackiePimping 0x65FD8777
#define Character_JackieSanitation 0xA3C48828
#define Character_JaneTeng 0xAD95E4CB
#define Character_JiuMei 0x28943605
#define Character_Johnny 0xB9D2BB1F
#define Character_JohnnyCaterer 0x588809F2
#define Character_JohnnyDamaged_HD 0x5261E215
#define Character_King 0xBD0B97A0
#define Character_King_HD 0x2DACF501
#define Character_MartialArts_Student 0x4495B524
#define Character_MartialArts_Student1 0x62C4528C
#define Character_MartialArts_Student2 0x6F877455
#define Character_MartialArts_Student3 0x6B4669E2
#define Character_MartialArts_Student4 0x750139E7
#define Character_MartialArts_Teacher 0x54672FDF
#define Character_MeatCleaverWu 0x8B3C5298
#define Character_Mechanic 0x177C65E
#define Character_MeterMaid 0x9A5DB9C9
#define Character_MidAgeAmbFemM 0xA4AFF0B4
#define Character_MidAgeAmbMaleM 0x5A85811
#define Character_Monk 0x4C3B830A
#define Character_MrTong 0xBA6D1CD3
#define Character_MrTongDamaged_HD 0x371C5FA7
#define Character_MrsChuWedding 0xEA2C3D21
#define Character_NM_ElderlyAmbFemM 0x66CAB8CE
#define Character_NM_ElderlyAmbMaleM 0x34E889E6
#define Character_Naz 0x579211F2
#define Character_Newshoes 0x897AEAFB
#define Character_NotPing 0x2290F6E1
#define Character_NotPingDate 0x1E59F48A
#define Character_NurseFemale 0x89E3B181
#define Character_OldSaltyCrab 0xD6F4EA4E
#define Character_PCPolice_A 0x729CE849
#define Character_PCPolice_B 0x7FDFCE90
#define Character_PCPolice_C 0x7B1ED327
#define Character_Painter 0xAAE13703
#define Character_Patsy 0xE054302E
#define Character_PeggyLi 0x71695DB
#define Character_PeggyLiWedDead 0x60A3D6A4
#define Character_PeggyLiWedding 0x33295D80
#define Character_PendrewPrison_HD 0xFB753894
#define Character_PoliceChief 0xC10402E
#define Character_Ponytail 0xA449FAE2
#define Character_PonytailDamaged 0x7206578C
#define Character_PonytailDamaged_HD 0xD0E08752
#define Character_Postman 0xE53A49C1
#define Character_PublicWorks 0x86F8163F
#define Character_PublicWorksNW 0x96DD1C35
#define Character_RickyFuneral 0x9D16F268
#define Character_RickyNonCombat 0x3D37565F
#define Character_RickyWong 0xF0362D68
#define Character_RivalEnforcer01 0xA9161807
#define Character_Robowei_nis_nmc 0x7F45E85C
#define Character_RolandHo 0xACC60244
#define Character_SS_Worker 0x43190426
#define Character_Sandra 0x4643CAC5
#define Character_SandraDate 0xA8713E60
#define Character_ScrubsFemale 0xDF543B8B
#define Character_ScrubsMale 0xEA912D71
#define Character_SecurityGuard02 0xF9DECB81
#define Character_SecurityGuard_A 0xC84B97FD
#define Character_SecurityGuard_B 0xC508B124
#define Character_ShopkeeperFemale 0x7EA335E5
#define Character_ShopkeeperFemaleNormal 0xB1174D4A
#define Character_SifuHenryKwok 0xD6DFC731
#define Character_StatsBrawler 0x75D7E5D4
#define Character_StatsGrappler 0x592EC93E
#define Character_StatsMonk 0xAEE9D21B
#define Character_StatsRangedWeapon 0x58AF318C
#define Character_StatsStriker 0x15DD6562
#define Character_StatsStrikerQuick 0xCF8B7935
#define Character_StreetWorker 0x850731B2
#define Character_Striker01 0x2CB217D3
#define Character_TaxiDriverMale 0xAFF8273C
#define Character_ThugElite 0x28C6AF87
#define Character_Thug_18k_BrawlerA01_NIS 0x18F54629
#define Character_Thug_18k_GrapplerA01_NIS 0x8962B85A
#define Character_Thug_18k_brawler 0xCB79A69F
#define Character_Thug_18k_brawler_POI 0xA92A02C3
#define Character_Thug_18k_brawler_amb 0xBD54237C
#define Character_Thug_18k_brawler_easy 0xADB75AAB
#define Character_Thug_18k_brawler_hard 0x5B00886C
#define Character_Thug_18k_brawler_pistol 0x8B1C2559
#define Character_Thug_18k_grap 0x2DFA571
#define Character_Thug_18k_grap_POI 0xA3044CE4
#define Character_Thug_18k_grap_amb 0xB77A6D5B
#define Character_Thug_18k_grap_easy 0xAC73AB7D
#define Character_Thug_18k_grap_hard 0x5AC479BA
#define Character_Thug_18k_grap_parkour 0xA12AD350
#define Character_Thug_18k_grap_pistol 0xE65D02C0
#define Character_Thug_18k_quick 0x10085B9E
#define Character_Thug_18k_quickA01_NIS 0x57D47EFE
#define Character_Thug_18k_quick_POI 0xBB6DAEA
#define Character_Thug_18k_quick_amb 0x1FC8FB55
#define Character_Thug_18k_quick_easy 0xC9C21ECB
#define Character_Thug_18k_quick_hard 0x3F75CC0C
#define Character_Thug_18k_striker 0xAB732629
#define Character_Thug_18k_strikerA01_NIS 0x5D83D68
#define Character_Thug_18k_striker_POI 0xBA90F105
#define Character_Thug_18k_striker_amb 0xAEEED0BA
#define Character_Thug_18k_striker_easy 0x56166102
#define Character_Thug_18k_striker_hard 0xA0A1B3C5
#define Character_Thug_18k_turret 0xDD378917
#define Character_Thug_BsL_brawler 0x6C68216C
#define Character_Thug_BsL_brawler_amb 0xC033BF3E
#define Character_Thug_BsL_brawler_easy 0x1B52839F
#define Character_Thug_BsL_grap 0xBDA7000A
#define Character_Thug_BsL_grap_amb 0x49959850
#define Character_Thug_BsL_grap_easy 0xF6B0FD7E
#define Character_Thug_BsL_quick 0xEDDC105D
#define Character_Thug_BsL_quick_amb 0x450BAD56
#define Character_Thug_BsL_quick_easy 0x5D89601A
#define Character_Thug_BsL_striker 0xC62A1DA
#define Character_Thug_BsL_striker_amb 0xD3894CF8
#define Character_Thug_BsL_striker_easy 0xE0F3B836
#define Character_Thug_Cult_Brawler 0x24B6F52D
#define Character_Thug_Cult_BrawlerBomb 0x67A31DE4
#define Character_Thug_Cult_BrawlerYellow 0xD2C21599
#define Character_Thug_Cult_Grappler 0x4468868E
#define Character_Thug_Cult_Quick 0x24B3D37
#define Character_Thug_Cult_QuickMask 0x6159FB39
#define Character_Thug_Cult_Striker 0x44BC759B
#define Character_Thug_Cult_StrikerMask 0xC6619081
#define Character_Thug_Dbs_brawler 0xAE9F02C7
#define Character_Thug_Dbs_brawlerA01_NIS 0x5C778351
#define Character_Thug_Dbs_brawlerA02_NIS 0x87602BC6
#define Character_Thug_Dbs_brawler_amb 0x3A19B370
#define Character_Thug_Dbs_brawler_easy 0x976CE640
#define Character_Thug_Dbs_grap 0x8F1C429A
#define Character_Thug_Dbs_grap_amb 0xEABE98A7
#define Character_Thug_Dbs_grap_easy 0x21DC7AA9
#define Character_Thug_Dbs_grapplerA01_NIS 0x2C25C6F1
#define Character_Thug_Dbs_grapplerB01_NIS 0xFDDC7EC2
#define Character_Thug_Dbs_quick 0x8B2ED6A3
#define Character_Thug_Dbs_quickA01_NIS 0x6D0FC215
#define Character_Thug_Dbs_quickB01_NIS 0xBCF67A26
#define Character_Thug_Dbs_quick_amb 0x92672A81
#define Character_Thug_Dbs_quick_easy 0x3ED2ACF6
#define Character_Thug_Dbs_striker 0xCE958271
#define Character_Thug_Dbs_strikerA01_GUNIS 0xDEB91482
#define Character_Thug_Dbs_strikerA01_NIS 0x99ABCD88
#define Character_Thug_Dbs_strikerA02_NIS 0x42BC651F
#define Character_Thug_Dbs_striker_amb 0x29A340B6
#define Character_Thug_Dbs_striker_easy 0x6CCDDDE9
#define Character_Thug_Dbs_striker_tutorial 0x44987D19
#define Character_Thug_Dbs_striker_tutorial_K 0x8933EAA2
#define Character_Thug_Dbs_tutorial_A 0x989BB530
#define Character_Thug_Dbs_tutorial_B 0x95D893E9
#define Character_Thug_Dbs_tutorial_C 0x91198E5E
#define Character_Thug_Dbs_tutorial_blocker 0x4DC09C11
#define Character_Thug_Soy_BrawlerA01_NIS 0xEF92DD61
#define Character_Thug_Soy_BrawlerA02_NIS 0x348575F6
#define Character_Thug_Soy_GrapplerA01_NIS 0x79065D56
#define Character_Thug_Soy_GrapplerA02_NIS 0xA211F5C1
#define Character_Thug_Soy_QuickA01_NIS 0x40758318
#define Character_Thug_Soy_QuickA02_NIS 0x9B622B8F
#define Character_Thug_Soy_StrikerA01_NIS 0x2A4E93B8
#define Character_Thug_Soy_StrikerA02_NIS 0xF1593B2F
#define Character_Thug_Soy_brawler 0x1B8E4841
#define Character_Thug_Soy_brawler_aggressive 0xF35412A9
#define Character_Thug_Soy_brawler_amb 0x25BE4B37
#define Character_Thug_Soy_brawler_defensive 0x28FA1B57
#define Character_Thug_Soy_brawler_no_cover 0x62D62E1A
#define Character_Thug_Soy_grap 0x4E8231A4
#define Character_Thug_Soy_grap_amb 0x510FF8B2
#define Character_Thug_Soy_grap_balanced 0xE4525F9C
#define Character_Thug_Soy_quick 0x4C16658D
#define Character_Thug_Soy_quick_amb 0xB572799E
#define Character_Thug_Soy_striker 0x7B84C8F7
#define Character_Thug_Soy_striker_0_grap 0xC2CA9614
#define Character_Thug_Soy_striker_amb 0x3604B8F1
#define Character_Thug_Soy_striker_weapon_light 0x38A6A3C2
#define Character_Thug_Wsg_QuickA01_NIS 0x5AA867AB
#define Character_Thug_Wsg_QuickB01_NIS 0x8B51DF98
#define Character_Thug_Wsg_brawler 0x70BA8B2C
#define Character_Thug_Wsg_brawler_amb 0x8A6DF638
#define Character_Thug_Wsg_grap 0xBDE2E005
#define Character_Thug_Wsg_grap_amb 0xE2229844
#define Character_Thug_Wsg_quick 0xA83C1F5D
#define Character_Thug_Wsg_quick_amb 0x286F2439
#define Character_Thug_Wsg_striker 0x10B00B9A
#define Character_Thug_Wsg_striker_amb 0x99D705FE
#define Character_Thug_Wsg_striker_tutorial 0xC23FD341
#define Character_Thug_Wsg_striker_tutorialD 0x4C59EC5C
#define Character_Tiffany 0xC1055423
#define Character_TiffanyDate 0x4281E370
#define Character_Tommy 0x94FD2853
#define Character_TouristAsianFemale 0xDC416BF2
#define Character_TouristAsianMale 0x3968B1B
#define Character_TouristAsianMale_d 0x955A53C3
#define Character_TouristWestFemale 0x445F685C
#define Character_TouristWestMale 0x752F1890
#define Character_TouristWestMale_d 0xD44506D
#define Character_Tran 0x211F4884
#define Character_TwoChinTsao 0x22B9D61A
#define Character_UnclePoHospital 0x94CB0B66
#define Character_UnclePoWedding 0x7644A0F3
#define Character_UnclePoWeddingDamaged_HD 0x5A0E03D8
#define Character_Undercover01 0x9DDF438A
#define Character_VIPbouncer 0x46E3E802
#define Character_Valet 0x85BF7299
#define Character_ValetCNY 0x95E72CEE
#define Character_Vincent 0x8875617A
#define Character_VincentTutorial 0xE79291B2
#define Character_VivienneAssasin 0x5522150C
#define Character_VivienneDate 0x3A1528CD
#define Character_WaitressFemale01 0x8F895C1C
#define Character_Wei2 0x9E3A063E
#define Character_WeiLucha 0x5BE41794
#define Character_Wei_Beatcop 0xF606181F
#define Character_Wei_Cultist 0xE64DEB33
#define Character_Wei_Hitman 0xA445FE8D
#define Character_Wei_MMAmerican 0xC54ABCB9
#define Character_Wei_Maori 0xB86BBC68
#define Character_Wei_MuayThai 0x413CD37B
#define Character_Wei_Russian 0xB90AA021
#define Character_Wei_SuperSwatNH 0x9D54B1B6
#define Character_Wei_SwordMaster 0xDF75F685
#define Character_Wei_Yakuza 0x994BE361
#define Character_Weiplainclothes 0xAFA655C3
#define Character_WeiplainclothesNB 0xB21E138B
#define Character_WindowWasher 0xA753D98D
#define Character_WinstonWedDead 0xE1A8CA9
#define Character_WinstonWedding 0x5D90078D
#define Character_YarKwai 0xE5C5D11B
#define Character_attendant 0x41D212C9
#define Character_bartendermale 0x5B9A3552
#define Character_bartenderunique 0xA4E3AB5D
#define Character_bigsmileslee 0xBCD89912
#define Character_bouncer 0x63E7A37E
#define Character_bouncer2 0x9BF5C8B0
#define Character_bouncerboss 0xDCA8141B
#define Character_bouncerdoor 0xC7BB9498
#define Character_calvin 0xEADC0AA3
#define Character_calvinPiP 0x16E3CE2F
#define Character_candy 0x8C948735
#define Character_chickNoCircle 0x397D4C8B
#define Character_clubOwner 0xE229E04F
#define Character_clubgirlNoCircle 0xCB710D37
#define Character_crashstar 0xE5567290
#define Character_dirtyming 0x265AEBE4
#define Character_dirtymingPiP 0x640B26BB
#define Character_dirtymingworker 0x18A1D1E8
#define Character_dj 0x9E4FFDF0
#define Character_dogeyes 0x58BFCD2C
#define Character_dogeyesDam 0x75079B69
#define Character_doorguard 0xE0BF0104
#define Character_elderly_base 0xCCC6D6B2
#define Character_gambler 0xDA76CCE4
#define Character_gaptooth 0x6310B914
#define Character_illyana 0x36BF724A
#define Character_informant 0x51030C77
#define Character_initiation_yung 0x7E5B44BD
#define Character_jackie 0xF36273C8
#define Character_jackieSARS 0x899F1980
#define Character_janitor 0xA4FB9106
#define Character_mrschu 0x8DA6A40C
#define Character_nina 0xEDFC4A51
#define Character_npcPlayer 0x16237E96
#define Character_npcPlayerFull 0x5FE49197
#define Character_passenger1M_MB 0x1C4597C9
#define Character_passenger2M_MB 0xC7523F5E
#define Character_passenger3M_MB 0x8E5F58D3
#define Character_ped1 0x78673B5A
#define Character_ped2 0x75241D83
#define Character_ped3 0x71E50034
#define Character_ped4 0x6FA25031
#define Character_pendrew 0xA360EB72
#define Character_pendrew_nis 0xC3BEC61F
#define Character_player 0xBD387BEE
#define Character_playerbloody 0x7EA83CA5
#define Character_pockmarkcheuk 0xFD70345D
#define Character_pockmarkcheukfuneral 0xD54632E9
#define Character_police 0x95576162
#define Character_police_ambient 0x309915CE
#define Character_police_base 0x1CE0872D
#define Character_police_swat 0xD6B3D080
#define Character_police_variation1 0x34317ACA
#define Character_police_variation2 0x39725C13
#define Character_police_variation3 0x3DB341A4
#define Character_police_variation4a 0xC915EA19
#define Character_police_variation4b 0xC456CCC0
#define Character_policebuddycopdlc 0x123CA7F1
#define Character_policeold 0xC02DD39
#define Character_policeyoung 0xEA57FD95
#define Character_policeyoung_nis 0x3AD7193B
#define Character_politician 0x25E682C2
#define Character_politiciangf 0xA7A12AD
#define Character_popstar 0x8101ADC9
#define Character_raymond 0xA0DC7AEE
#define Character_raymond_HD 0x6669B6C5
#define Character_ricky 0xA593135
#define Character_rico 0xBE0CB0D0
#define Character_rivaldriverM_MB 0xF64E18CA
#define Character_scamgirl 0x1794B3C8
#define Character_sexygirlRed 0x3BD560DB
#define Character_shopkeeper 0xE06C9051
#define Character_shopkeeper1 0x79CA075E
#define Character_shopkeeper2 0x74892187
#define Character_shopkeeper3 0x70483C30
#define Character_shopkeeper4 0x6E0F6C35
#define Character_shopkeeper5 0x6ACE7182
#define Character_shopkeeperJackie 0xA9C945F8
#define Character_shopkeeperNormal 0xB145D4DC
#define Character_siuwah 0x5EF14AEB
#define Character_sonny 0x1CF9A8B2
#define Character_student 0x2BBD802E
#define Character_student_brawler 0x48BE009C
#define Character_student_grap 0xC0BE901B
#define Character_student_quick 0x25359A69
#define Character_student_striker 0x28B4802A
#define Character_taxi_driver_faceaction 0x3A13482D
#define Character_teacher 0x3B4F1AD5
#define Character_test_dude 0x6C9B9C65
#define Character_thief 0x726E4014
#define Character_thugA 0x40D526AA
#define Character_thugB 0x4D960073
#define Character_thugC 0x49571DC4
#define Character_thugD 0x57104DC1
#define Character_thugE 0x53D15076
#define Character_thugE_Amb 0x651FC41
#define Character_thugF 0x5E9276AF
#define Character_thugG 0x5A536B18
#define Character_thugH 0x621CD6A5
#define Character_thugHTutorial 0x749932D0
#define Character_thugI 0x66DDCB12
#define Character_thugJ 0x6B9EEDCB
#define Character_thugK 0x6F5FF07C
#define Character_thugL 0x7118A079
#define Character_thugM 0x75D9BDCE
#define Character_thugN 0x789A9B17
#define Character_thugO 0x7C5B86A0
#define Character_thug_am_025_nis 0x63B457AA
#define Character_twochintsaofuneral 0x1625F6B3
#define Character_unclepo 0x59DFB91
#define Character_vagrant 0xBDEE9D16
#define Character_vagrant_d 0x980B2AC5
#define Character_vagrant_junkie 0x99290F7D
#define Character_vivienne 0x586CA72E
#define Character_watchvendor 0x713FA438
#define Character_wei_base_bag 0xA7EF904C
#define Character_wei_nis_default 0xA6FA3DF6
#define Character_wei_nis_election 0x6B379F30
#define Character_wei_nis_election_intro 0x463CDBEE
#define Character_wei_nis_electionscar 0xC39F4009
#define Character_wei_nis_electionscar2 0x1239E9BE
#define Character_wei_nis_electionsuit 0x4A086D8B
#define Character_wei_nis_electionsuitDam 0xB8A257CE
#define Character_wei_nis_flashback 0xC6B32839
#define Character_wei_nis_globals 0xD9571BF1
#define Character_wei_nis_nmc 0xBCA5D8E
#define Character_wei_nis_nmc_end 0x2E450377
#define Character_wei_nis_topglamour 0x48675E8B
#define Character_wei_nis_topglamourhelmet 0xFB6CCDDE
#define Character_wei_tactical 0x5C2D2B52
#define Character_wei_weddingsuit_nis 0x6E9A1C5A
#define Character_winston 0x55C27E6A
#define Character_motion_tester 0x74149586

namespace UFG
{
	unsigned int m_CharacterIDs[] = { Character_80sTriad, Character_ACE, Character_Alex, Character_AmandaCartwright, Character_AmandaDate, Character_AmandaDojo, Character_AmbFemaleCaucasian, Character_AmbMaleCaucasian, Character_AmbSportBikeRider, Character_Amb_Business_F, Character_Amb_Business_M, Character_Amb_Business_M_d, Character_Amb_Business_WF, Character_Amb_Business_WM, Character_AmbientFemale1, Character_AmbientFemaleL, Character_AmbientFemaleM, Character_AmbientFemaleU, Character_AmbientFemale_shopper, Character_AmbientMale1, Character_AmbientMaleL, Character_AmbientMaleL_NW, Character_AmbientMaleM, Character_AmbientMaleNew, Character_AmbientMaleU, Character_AmbientTest, Character_BN_Chang, Character_Bartender, Character_Benny, Character_BigSmilesLee_Damage_HD, Character_Bookie, Character_Bouncer01, Character_Bouncer02, Character_BouncerBoss01, Character_Brawler01, Character_BrokenNoseJiang, Character_BrokenNoseJiangFuneral, Character_BusDriverMale, Character_ChopShopAccountant, Character_ChopShopMale01, Character_ChopShopMale02, Character_ClubGirl, Character_ClubberFemale, Character_ClubberMale, Character_CollegeFemale, Character_CollegeMale, Character_CommonPedestrian, Character_Conroy, Character_Conroy_Amb, Character_Conroy_tutorial, Character_Construction, Character_CookMale, Character_Crystal, Character_CultLeader, Character_DJ_Female, Character_Dancer, Character_Delivery, Character_DeliveryNW, Character_DeliveryNoProps, Character_DirtyMonk, Character_DockWorker, Character_DockWorkerNW, Character_DockWorkerThug, Character_DoctorFemale, Character_DoctorJaiBe, Character_DoctorMale, Character_DoctorTang, Character_DogeyesDamaged_HD, Character_DrunkClubberFemale, Character_DrunkClubberMale, Character_Duke, Character_DukeTutorial, Character_EMT, Character_E_SS_WeakMonk, Character_ElderlyAmbFemM, Character_ElderlyAmbFemMNoCane, Character_ElderlyAmbMaleM, Character_ElderlyAmbMaleNP, Character_ElderlyFemaleU, Character_FM_Male_Worker, Character_FM_Worker, Character_Fireman, Character_FloristGirl, Character_GamblerFemale01, Character_GamblerFemale02, Character_GamblerFemale03, Character_GamblerMale01, Character_GamblerMale02, Character_GamblerMale03, Character_GamblerMale04, Character_GamblerMale05, Character_GamblerMale06, Character_GamblerMale07, Character_GamblerMale08, Character_GamblerMale09, Character_Gigi, Character_Grappler01, Character_Horseface, Character_HotShot, Character_IllyanaDate, Character_JackieMovingUp, Character_JackieMovingUpDead, Character_JackiePimping, Character_JackieSanitation, Character_JaneTeng, Character_JiuMei, Character_Johnny, Character_JohnnyCaterer, Character_JohnnyDamaged_HD, Character_King, Character_King_HD, Character_MartialArts_Student, Character_MartialArts_Student1, Character_MartialArts_Student2, Character_MartialArts_Student3, Character_MartialArts_Student4, Character_MartialArts_Teacher, Character_MeatCleaverWu, Character_Mechanic, Character_MeterMaid, Character_MidAgeAmbFemM, Character_MidAgeAmbMaleM, Character_Monk, Character_MrTong, Character_MrTongDamaged_HD, Character_MrsChuWedding, Character_NM_ElderlyAmbFemM, Character_NM_ElderlyAmbMaleM, Character_Naz, Character_Newshoes, Character_NotPing, Character_NotPingDate, Character_NurseFemale, Character_OldSaltyCrab, Character_PCPolice_A, Character_PCPolice_B, Character_PCPolice_C, Character_Painter, Character_Patsy, Character_PeggyLi, Character_PeggyLiWedDead, Character_PeggyLiWedding, Character_PendrewPrison_HD, Character_PoliceChief, Character_Ponytail, Character_PonytailDamaged, Character_PonytailDamaged_HD, Character_Postman, Character_PublicWorks, Character_PublicWorksNW, Character_RickyFuneral, Character_RickyNonCombat, Character_RickyWong, Character_RivalEnforcer01, Character_Robowei_nis_nmc, Character_RolandHo, Character_SS_Worker, Character_Sandra, Character_SandraDate, Character_ScrubsFemale, Character_ScrubsMale, Character_SecurityGuard02, Character_SecurityGuard_A, Character_SecurityGuard_B, Character_ShopkeeperFemale, Character_ShopkeeperFemaleNormal, Character_SifuHenryKwok, Character_StatsBrawler, Character_StatsGrappler, Character_StatsMonk, Character_StatsRangedWeapon, Character_StatsStriker, Character_StatsStrikerQuick, Character_StreetWorker, Character_Striker01, Character_TaxiDriverMale, Character_ThugElite, Character_Thug_18k_BrawlerA01_NIS, Character_Thug_18k_GrapplerA01_NIS, Character_Thug_18k_brawler, Character_Thug_18k_brawler_POI, Character_Thug_18k_brawler_amb, Character_Thug_18k_brawler_easy, Character_Thug_18k_brawler_hard, Character_Thug_18k_brawler_pistol, Character_Thug_18k_grap, Character_Thug_18k_grap_POI, Character_Thug_18k_grap_amb, Character_Thug_18k_grap_easy, Character_Thug_18k_grap_hard, Character_Thug_18k_grap_parkour, Character_Thug_18k_grap_pistol, Character_Thug_18k_quick, Character_Thug_18k_quickA01_NIS, Character_Thug_18k_quick_POI, Character_Thug_18k_quick_amb, Character_Thug_18k_quick_easy, Character_Thug_18k_quick_hard, Character_Thug_18k_striker, Character_Thug_18k_strikerA01_NIS, Character_Thug_18k_striker_POI, Character_Thug_18k_striker_amb, Character_Thug_18k_striker_easy, Character_Thug_18k_striker_hard, Character_Thug_18k_turret, Character_Thug_BsL_brawler, Character_Thug_BsL_brawler_amb, Character_Thug_BsL_brawler_easy, Character_Thug_BsL_grap, Character_Thug_BsL_grap_amb, Character_Thug_BsL_grap_easy, Character_Thug_BsL_quick, Character_Thug_BsL_quick_amb, Character_Thug_BsL_quick_easy, Character_Thug_BsL_striker, Character_Thug_BsL_striker_amb, Character_Thug_BsL_striker_easy, Character_Thug_Cult_Brawler, Character_Thug_Cult_BrawlerBomb, Character_Thug_Cult_BrawlerYellow, Character_Thug_Cult_Grappler, Character_Thug_Cult_Quick, Character_Thug_Cult_QuickMask, Character_Thug_Cult_Striker, Character_Thug_Cult_StrikerMask, Character_Thug_Dbs_brawler, Character_Thug_Dbs_brawlerA01_NIS, Character_Thug_Dbs_brawlerA02_NIS, Character_Thug_Dbs_brawler_amb, Character_Thug_Dbs_brawler_easy, Character_Thug_Dbs_grap, Character_Thug_Dbs_grap_amb, Character_Thug_Dbs_grap_easy, Character_Thug_Dbs_grapplerA01_NIS, Character_Thug_Dbs_grapplerB01_NIS, Character_Thug_Dbs_quick, Character_Thug_Dbs_quickA01_NIS, Character_Thug_Dbs_quickB01_NIS, Character_Thug_Dbs_quick_amb, Character_Thug_Dbs_quick_easy, Character_Thug_Dbs_striker, Character_Thug_Dbs_strikerA01_GUNIS, Character_Thug_Dbs_strikerA01_NIS, Character_Thug_Dbs_strikerA02_NIS, Character_Thug_Dbs_striker_amb, Character_Thug_Dbs_striker_easy, Character_Thug_Dbs_striker_tutorial, Character_Thug_Dbs_striker_tutorial_K, Character_Thug_Dbs_tutorial_A, Character_Thug_Dbs_tutorial_B, Character_Thug_Dbs_tutorial_C, Character_Thug_Dbs_tutorial_blocker, Character_Thug_Soy_BrawlerA01_NIS, Character_Thug_Soy_BrawlerA02_NIS, Character_Thug_Soy_GrapplerA01_NIS, Character_Thug_Soy_GrapplerA02_NIS, Character_Thug_Soy_QuickA01_NIS, Character_Thug_Soy_QuickA02_NIS, Character_Thug_Soy_StrikerA01_NIS, Character_Thug_Soy_StrikerA02_NIS, Character_Thug_Soy_brawler, Character_Thug_Soy_brawler_aggressive, Character_Thug_Soy_brawler_amb, Character_Thug_Soy_brawler_defensive, Character_Thug_Soy_brawler_no_cover, Character_Thug_Soy_grap, Character_Thug_Soy_grap_amb, Character_Thug_Soy_grap_balanced, Character_Thug_Soy_quick, Character_Thug_Soy_quick_amb, Character_Thug_Soy_striker, Character_Thug_Soy_striker_0_grap, Character_Thug_Soy_striker_amb, Character_Thug_Soy_striker_weapon_light, Character_Thug_Wsg_QuickA01_NIS, Character_Thug_Wsg_QuickB01_NIS, Character_Thug_Wsg_brawler, Character_Thug_Wsg_brawler_amb, Character_Thug_Wsg_grap, Character_Thug_Wsg_grap_amb, Character_Thug_Wsg_quick, Character_Thug_Wsg_quick_amb, Character_Thug_Wsg_striker, Character_Thug_Wsg_striker_amb, Character_Thug_Wsg_striker_tutorial, Character_Thug_Wsg_striker_tutorialD, Character_Tiffany, Character_TiffanyDate, Character_Tommy, Character_TouristAsianFemale, Character_TouristAsianMale, Character_TouristAsianMale_d, Character_TouristWestFemale, Character_TouristWestMale, Character_TouristWestMale_d, Character_Tran, Character_TwoChinTsao, Character_UnclePoHospital, Character_UnclePoWedding, Character_UnclePoWeddingDamaged_HD, Character_Undercover01, Character_VIPbouncer, Character_Valet, Character_ValetCNY, Character_Vincent, Character_VincentTutorial, Character_VivienneAssasin, Character_VivienneDate, Character_WaitressFemale01, Character_Wei2, Character_WeiLucha, Character_Wei_Beatcop, Character_Wei_Cultist, Character_Wei_Hitman, Character_Wei_MMAmerican, Character_Wei_Maori, Character_Wei_MuayThai, Character_Wei_Russian, Character_Wei_SuperSwatNH, Character_Wei_SwordMaster, Character_Wei_Yakuza, Character_Weiplainclothes, Character_WeiplainclothesNB, Character_WindowWasher, Character_WinstonWedDead, Character_WinstonWedding, Character_YarKwai, Character_attendant, Character_bartendermale, Character_bartenderunique, Character_bigsmileslee, Character_bouncer, Character_bouncer2, Character_bouncerboss, Character_bouncerdoor, Character_calvin, Character_calvinPiP, Character_candy, Character_chickNoCircle, Character_clubOwner, Character_clubgirlNoCircle, Character_crashstar, Character_dirtyming, Character_dirtymingPiP, Character_dirtymingworker, Character_dj, Character_dogeyes, Character_dogeyesDam, Character_doorguard, Character_elderly_base, Character_gambler, Character_gaptooth, Character_illyana, Character_informant, Character_initiation_yung, Character_jackie, Character_jackieSARS, Character_janitor, Character_mrschu, Character_nina, Character_npcPlayer, Character_npcPlayerFull, Character_passenger1M_MB, Character_passenger2M_MB, Character_passenger3M_MB, Character_ped1, Character_ped2, Character_ped3, Character_ped4, Character_pendrew, Character_pendrew_nis, Character_player, Character_playerbloody, Character_pockmarkcheuk, Character_pockmarkcheukfuneral, Character_police, Character_police_ambient, Character_police_base, Character_police_swat, Character_police_variation1, Character_police_variation2, Character_police_variation3, Character_police_variation4a, Character_police_variation4b, Character_policebuddycopdlc, Character_policeold, Character_policeyoung, Character_policeyoung_nis, Character_politician, Character_politiciangf, Character_popstar, Character_raymond, Character_raymond_HD, Character_ricky, Character_rico, Character_rivaldriverM_MB, Character_scamgirl, Character_sexygirlRed, Character_shopkeeper, Character_shopkeeper1, Character_shopkeeper2, Character_shopkeeper3, Character_shopkeeper4, Character_shopkeeper5, Character_shopkeeperJackie, Character_shopkeeperNormal, Character_siuwah, Character_sonny, Character_student, Character_student_brawler, Character_student_grap, Character_student_quick, Character_student_striker, Character_taxi_driver_faceaction, Character_teacher, Character_test_dude, Character_thief, Character_thugA, Character_thugB, Character_thugC, Character_thugD, Character_thugE, Character_thugE_Amb, Character_thugF, Character_thugG, Character_thugH, Character_thugHTutorial, Character_thugI, Character_thugJ, Character_thugK, Character_thugL, Character_thugM, Character_thugN, Character_thugO, Character_thug_am_025_nis, Character_twochintsaofuneral, Character_unclepo, Character_vagrant, Character_vagrant_d, Character_vagrant_junkie, Character_vivienne, Character_watchvendor, Character_wei_base_bag, Character_wei_nis_default, Character_wei_nis_election, Character_wei_nis_election_intro, Character_wei_nis_electionscar, Character_wei_nis_electionscar2, Character_wei_nis_electionsuit, Character_wei_nis_electionsuitDam, Character_wei_nis_flashback, Character_wei_nis_globals, Character_wei_nis_nmc, Character_wei_nis_nmc_end, Character_wei_nis_topglamour, Character_wei_nis_topglamourhelmet, Character_wei_tactical, Character_wei_weddingsuit_nis, Character_winston, Character_motion_tester, static_cast<unsigned int>(-1) };
}