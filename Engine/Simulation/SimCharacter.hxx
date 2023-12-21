#pragma once

namespace UFG
{
	// ...

	class CCharacterRigidBody
	{
	public:
		UFG_PAD(0x20);

		hkpRigidBody* m_character;

		UFG_PAD(0x8);

		hkVector4f mTopVertex;
		hkVector4f mBottomVertex;
		hkVector4f m_up;
		float m_maxSlopeCosine;
		int m_userPlanes;
		float m_penetrationRecoverySpeed;
		float m_maxSpeedForSimplexSolver;
		float m_supportDistance;
		float mSupportRadius;
		float m_heightAboveGround;
		bool m_isPlayer;
		bool m_fixCurbContacts;
		bool m_supportedOffCentre;
		bool m_isInWater;
		bool m_superMassive;

		UFG_PAD(0x18);
		//hkArray<CharacterRigidBody::VertPointInfo, hkContainerHeapAllocator> m_verticalContactPoints;

		hkVector4f m_acceleration;
		float m_maxForce;
	};

	class CCharacterControllerInterface : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		RebindingComponentHandle<CActionTreeComponent> m_pActionTreeComponent;
	};

	// Components
	class CAIAwarenessComponent : public UFG::CSimComponent
	{
	public:
		qNode<CAIAwarenessComponent> mNode;
		AIAwareness::CProfile* mpCurrentProfile;
		AIAwareness::CEffector* mpHeadEffector;
		AIAwareness::CEffector* mpEyeEffector;
		AIAwareness::CKnowledgeSpace* mpKnowledgeSpace;
		bool mEnabled;
	};

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

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5497A0))(this);
		}

		void SetHealth(int uHealth)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, void*)>(UFG_RVA(0x54D3D0))(this, uHealth, nullptr);
		}

		void SetRegenerativeHealthRatio(float fRegenerativeHealthRatio, bool saveSnapshot)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x54E570))(this, fRegenerativeHealthRatio, saveSnapshot);
		}
	};

	class CAttackRightsComponent : public CSimComponent
	{
	public:
		// Constructor, call with caution!
		static CAttackRightsComponent* PropertiesOnActivate(CSceneObjectProperties* m_ObjectProperties)
		{
			return reinterpret_cast<CAttackRightsComponent * (__fastcall*)(CSceneObjectProperties*)>(UFG_RVA(0x37E560))(m_ObjectProperties);
		}

		static bool HasComponent(CSceneObjectProperties* m_ObjectProperties)
		{
			return reinterpret_cast<bool(__fastcall*)(CSceneObjectProperties*)>(UFG_RVA(0x364DA0))(m_ObjectProperties);
		}

		void InitFromProperties(qPropertySet* m_PropertySet)
		{
			reinterpret_cast<void(__fastcall*)(void*, qPropertySet*)>(UFG_RVA(0x366D40))(this, m_PropertySet);
		}

		void InitDefaultProperties()
		{
			// default-component-AttackRights
			qPropertySet* m_PropertySet = PropertySetManager::GetPropertySet(0xE29C0011);

			InitFromProperties(m_PropertySet);
		}
	};

	// Original Name: ActorAudioComponent
	class CCharacterAudioComponent
	{
	public:
		UFG_PAD(0x190);

		void* m_AudioEvent;
		CAudioEntity* m_SFXEntity;
		CVoiceProfile* m_voiceProfile;
		unsigned int m_curPlayingPriority;
		float m_interiorCheckTimer;
		float m_distance2ToListener;
		unsigned int m_activeAmbientConversationId;
		unsigned int m_subtitleId;
		int m_isSpeakingCnt;
		void* m_leftFootstep;
		void* m_rightFootstep;

		UFG_PAD(0x58);
		/*UFG::AmbientContextManager m_ambientContexts;
		UFG::qSafePointer<UFG::SimComponent, UFG::HealthComponent> m_healthComponent;
		UFG::qSafePointer<UFG::SimComponent, UFG::TransformNodeComponent> m_transformNodeComponent;
		UFG::qSafePointer<UFG::SimComponent, UFG::SimObjectCharacterPropertiesComponent> m_simObjectCharacterPropertiesComponent;*/

		__int8 m_isSpeakingInConversation : 1;
		__int8 m_isListeningInAConversation : 1;
		__int8 m_isNearby : 1;
		__int8 m_enableTaggedDialogue : 1;
		__int8 m_enableInCarReactions : 1;
		__int8 m_charcterIsAmbient : 1;
		__int8 m_forceInitialize : 1;
		__int8 m_forceDisable : 1;
		__int8 m_failedSpeechCondition : 1;
		__int8 m_debugActor : 1;
		__int8 m_inCar : 1;
		__int8 m_isPlayer : 1;
		__int8 m_inConversationButTooFarToPlay : 1;
		__int8 m_inConversationWithActionRequests : 1;
		__int8 m_isMale : 1;
		__int8 m_highHeel : 1;
		__int8 m_isPossessed : 1;

		bool PlaySpeech(uint32_t m_EventID, uint32_t m_FileID, void* m_Callback = nullptr, uint32_t m_Priority = 5, bool m_Subtitle = false)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t, uint32_t, void*, uint32_t, bool)>(UFG_RVA(0x5A8E20))(this, m_EventID, m_FileID, m_Callback, m_Priority, m_Subtitle);
		}

		void StopCurrentlyPlaying(bool m_Force = true)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x5AC9F0))(this, m_Force);
		}
	};

	class CCharacterEffectsComponent : public CSimComponent, public qNode<CCharacterEffectsComponent>
	{
	public:
		enum Foot
		{
			Foot_Left = 0x0,
			Foot_Right = 0x1,
			Foot_Num = 0x2,
		};

		enum Node
		{
			Node_WaterFootstepLeft = 0x0,
			Node_WaterFootstepRight = 0x1,
			Node_Num = 0x2,
		};

		struct PhysVolumeRef_t
		{
			qNodeRB mNode;
			bool mActive;
			bool mForceInactive;
			float mTimeInVolume;
			float mTimeOutVolume;
			class CPhysicsVolumeProperties* mPhysVolume;
			bool mPhysVolume_HitRecordPlayed;
		};

		bool InvulnerableToFire;
		bool ShowHealthBar;
		CTransformNodeComponent* mNodes[2];
		RebindingComponentHandle<class CCharacterAnimationComponent> mCharacterAnimationComponent;
		RebindingComponentHandle<class CCCharacterPhysicsComponent> mCharacterPhysicsComponent;
		RebindingComponentHandle<class CPhantomVolumeComponent> mPhantomVolumeComponent;
		qSymbol mWalkingThroughWaterEffect;
		float mWalkingThroughWaterMinSpeedForEffectSqr;
		float mMaxWaterDepthForWalkingThroughWaterEffect;
		qTreeRB mPhysVolumeRefs;
		uint32_t mActiveVolumeUID[5];
		uint32_t mActiveSurfaceUID;
		uint32_t mActiveWetSurfaceUID;
		bool mIsOnFire;
		uint32_t mFireEffectID[3];
		bool mIsSmoldering;
		uint32_t mSmolderEffectID[3];
		float mFireExtinguishTime;
		float mSmolderExtinguishTime;
		float mQueuedHealthDamage;
		hkpRigidBody* mPhantomRigidBody;
		bool mIsAttachedToPlayer;
		uint32_t mFootstepOverride[2];
		uint32_t mUIElementIndex;
		bool mIsEliteFighter;
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

	class CAIScriptInterfaceComponent
	{
	public:

		void SetDesiredTarget(eTargetTypeEnum target_type, CSimObject* target_object)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, CSimObject*)>(UFG_RVA(0x386060))(this, target_type, target_object);
		}
	};

	class CAIActionTreeComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x98);
		CActionController mActionController;
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

		static CAICoverComponent* PropertiesOnActivate(CSceneObjectProperties* p_SceneObj)
		{
			return reinterpret_cast<CAICoverComponent*(__fastcall*)(CSceneObjectProperties*)>(UFG_RVA(0x37E330))(p_SceneObj);
		}
	};

	class CAICharacterControllerBaseComponent : public CCharacterControllerInterface
	{
	public:
		CIntention m_Intention;
		bool m_IntentionUpdated;

		UFG_PAD(0x7);
		UFG_PAD(0x48);
		//UFG::qStaticBitField<548> m_ActionRequestMask;

		bool m_HoldMotionIntention;
		qVector3 m_HoldMotionIntentionDirection;
		float m_HoldMotionIntentionSpeed;
		float m_HoldBlend;
		float m_HoldBlendDelay;

		void DoParkour(UFG::qVector3* p_Direction, uint32_t p_CheckTypes)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*, void*, uint32_t, CIntention*, bool)>(UFG_RVA(0x352DE0))(this, p_Direction, nullptr, p_CheckTypes, &m_Intention, false);
		}

		void UpdateHoldMotionIntention(float p_TimeDelta)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x396CA0))(this, p_TimeDelta);
		}
	};

	class CAICharacterControllerComponent : public CAICharacterControllerBaseComponent
	{
	public:
	};

	class CAIEntityComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x4F8);
		/*UFG::RebindingComponentHandle<UFG::TransformNodeComponent, 0> m_pTransformNodeComponent;
		UFG::RebindingComponentHandle<UFG::ActionTreeComponent, 0> m_pActionTreeComponent;
		UFG::RebindingComponentHandle<UFG::RigidBodyComponent, 0> m_pRigidBodyComponent;
		UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent, 0> m_pCharacterAnimationComponent;
		UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent, 0> m_pSimObjectCharacterPropertiesComponent;
		UFG::RebindingComponentHandle<UFG::AttackRightsComponent, 0> m_pAttackRightsComponent;
		UFG::RebindingComponentHandle<UFG::SceneObjectProperties, 0> m_pSceneObjectProperties;
		UFG::RebindingComponentHandle<UFG::HealthComponent, 0> m_pHealthComponent;
		UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent, 0> m_pTargetingSystemBaseComponent;
		UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent, 0> m_pCharacterOccupantComponent;
		UFG::SidewalkWanderData m_WanderData;
		UFG::HeadTrackTarget m_HeadTrackingTarget;
		bool m_AIPositionValid;
		bool m_HostilityEnabled;
		UFG::NearbyCharacter* m_pNearbyCharacter;
		UFG::qSafePointer<UFG::GroupComponent, UFG::GroupComponent> m_pGroupComponent;
		UFG::qSafePointer<UFG::CombatRegion, UFG::CombatRegion> m_pCombatRegion;
		UFG::qFixedArray<UFG::ThreatTarget, 10> m_ThreatTargets;
		UFG::qVector3 m_vCombatRegionMoveToVec;
		bool m_bActive;
		bool m_bCanWander;
		bool m_bRefreshWander;
		bool m_bCanUseCrosswalks;*/
	};

	class CActiveAIEntityComponent : public CAIEntityComponent
	{
	public:
		UFG_PAD(0xAF8);

		float m_MaxEngagementDistanceXY;
		float m_MaxEngagementDistanceZ;
		bool m_EngagementOverrideEnabled;
		eAIEmotion m_CurrentEmotion;
		eAIEmotion m_FacialEmotion;
		eAIObjective m_CurrentObjective;
		bool m_PrevObjectiveWasHostile;
		eTargetTypeEnum m_TargetToStayNear;
		float m_MaxDistanceFromTargetToStayNear;
		float m_MaxDistanceFromTargetToStayNearHysteresis;
		float m_ChanceOfCleanVault;
		eParkourType m_ScriptedParkourTypeNearGoal;
		eParkourType m_ScriptedParkourTypeFarGoal;
		bool m_ScriptOverrideFreerunning;
		bool m_CleanNextVault;
		bool m_IsSpawning;
		bool m_InPOIDynamicBranch;
		bool m_InPropInteractBranch;

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

		void SetBehaviourTree(const char* behaviour_tree_name)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0x385000))(this, behaviour_tree_name);
		}
	};

	class CCharacterPhysicsComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x38);

		RebindingComponentHandle<class CRagdollComponent> mRagdollComponent;

		UFG_PAD(0xB0);

		struct GroundProperties_t
		{
			qVector3 groundPosition;
			qVector3 groundNormal;
			float heightAboveGround;
			float maxOffGroundElevation;
			float timeOffGround;
			float latchedFallDistance;
			float latchedFallTime;
			uint64_t groundObjectHandleUid;
			uint64_t groundSurfaceHandleUid;
			uint32_t support;
			uint32_t isOnGround : 1;
			uint32_t isOnGroundFiltered : 1;
			uint32_t prevOnGround : 1;
			uint32_t partiallySupported : 1;
		};
		GroundProperties_t mGroundProperties;
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

		void Update(float m_DeltaTime)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x476DC0))(this, m_DeltaTime);
		}

		void GetVelocity(qVector3* m_Result)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0x468150))(this, m_Result);
		}

		void SetVelocity(qVector3* m_Velocity)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0x4757C0))(this, m_Velocity);
		}
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

		void ApplyAngularImpulse(int m_Bone, qVector3 m_Impulse, float m_ConnectionTransfer)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qVector3*, float)>(UFG_RVA(0x456310))(this, m_Bone, &m_Impulse, m_ConnectionTransfer);
		}

		void ApplyImpulse(int m_Bone, qVector3 m_Location, qVector3 m_Impulse)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qVector3*, qVector3*)>(UFG_RVA(0x4585F0))(this, m_Bone, &m_Location, &m_Impulse);
		}

		void SetVelocity(qVector3 m_Velocity)
		{
			if (mRagdoll)
				reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0xB2780))(this, &m_Velocity);
		}

		void SetMotorMaxForce(float m_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x475360))(this, m_Value);
		}

		void SetLimitStiffness(float m_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x475160))(this, m_Value);
		}

		void SetPositionTrackingStiffness(float m_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x475540))(this, m_Value);
		}
	};

	class CCharacterOccupantComponent : public CSimComponent
	{
	public:
		qNode<CCharacterOccupantComponent> mNode;
		UFG::eTargetTypeEnum mTargetType;
		uint32_t mSeatIndex;
		RebindingComponentHandle<CVehicleOccupantComponent> mCurrentVOC;

		CSimVehicle* GetCurrentVehicle()
		{
			if (mCurrentVOC.m_pSimComponent)
				return reinterpret_cast<CSimVehicle*>(mCurrentVOC.m_pSimComponent->m_pSimObject);

			return nullptr;
		}
	};

	class CCharacterSubjectComponent : public CSimComponent
	{
	public:
		UFG_PAD(0xF0);

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
		qNode<CInventoryComponent> m_Node;
		qFixedArray<bool, 6> m_EquipSlots;
		int m_InventoryItems[209];
		eInventoryItemEnum m_SellableItem;
		qSymbol m_SellableItemProp;
		bool m_InfiniteSellableItem;
		bool m_bCheatUnlimitedAmmo;
		bool m_bDebugDrawInventory;

		static UFG::eTargetTypeEnum GetSlotTarget(int m_Slot)
		{
			switch (m_Slot)
			{
				default: return UFG::eTARGET_TYPE_EQUIPPED;
				case 1: return UFG::eTARGET_TYPE_EQUIPPED_LEFT_HAND;
				case 2: return UFG::eTARGET_TYPE_EQUIPPED_HAT;
				case 3: return UFG::eTARGET_TYPE_EQUIPPED_GLASSES;
				case 4: return UFG::eTARGET_TYPE_STOWED_WEAPON;
				case 5: return UFG::eTARGET_TYPE_STOWED_2H_WEAPON;
			}
		}

		void SetCanDrop(int m_Slot, bool m_CanDrop)
		{
			m_EquipSlots.p[m_Slot] = m_CanDrop;
		}

		bool Equip(CSimObject* m_ObjectToEquip, bool m_UseEquipSlot = false, int m_Slot = 0)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, CSimObject*, bool, int)>(UFG_RVA(0x526F90))(this, m_ObjectToEquip, m_UseEquipSlot, m_Slot);
		}

		void UnEquip(int m_Slot = 0, bool m_DeleteFromWorld = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool, int)>(UFG_RVA(0x557A40))(this, m_Slot, m_DeleteFromWorld);
		}
		
		void RemoveObjectFromInventory(CSimObject* m_Object)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x549120))(this, m_Object);
		}

		void Stow(int m_Slot, int m_DestinationSlot)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, int)>(UFG_RVA(0x552A40))(this, m_Slot, m_DestinationSlot);
		}
	};

	class CInterestPointUserComponent : public CSimComponent
	{
	public:
		void StopPOI()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3892D0))(this);
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
		qSafePointer<CSimObject> m_FreeAimSimObject;

		UFG_PAD(0x28);
		//UFG::qReflectHandle<UFG::PhysicsObjectProperties> m_FreeAimPhysicsObjectProperties;

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
		qSafePointer<CSimObject> m_pAimTargetPositionSimObject;
		qSafePointer<CTransformNodeComponent> m_pAimTargetPositionTNC;

		AimingPlayerComponent::eAimBlendMode m_eAimBlendMode;
	};

	class CCharacterAnimationComponent : public CBaseAnimationComponent
	{
	public:
		qNode<CCharacterAnimationComponent> mNode;
		bool mEnableUpdateTransforms;
		CCharacterDamageRig* mDamageRig;

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58B320))(this);
		}
	};

	class CSensorComponent : public CSimComponent
	{
	public:
		CParkourHandle* FindClosestParkourHandle(UFG::qVector3* p_Position, UFG::qVector3* p_Orentation, float p_Angle, float p_BufferZone, float p_DistanceMinXY, float p_DistanceMaxXY, float p_DistanceMinZ, float p_DistanceMaxZ, eSimObjectVehicleTypeEnum checkAttachedToVehicleType, Parkour::CheckFlags p_CheckFlags, UFG::qVector3* p_ContactPosition)
		{
			return reinterpret_cast<CParkourHandle*(__fastcall*)(void*, UFG::qVector3*, UFG::qVector3*, float, float, float, float, float, float, eSimObjectVehicleTypeEnum, Parkour::CheckFlags, UFG::qVector3*)>(UFG_RVA(0x27B370))(this, p_Position, p_Orentation, p_Angle, p_BufferZone, p_DistanceMinXY, p_DistanceMaxXY, p_DistanceMinZ, p_DistanceMaxZ, checkAttachedToVehicleType, p_CheckFlags, p_ContactPosition);
		}
	};

	class CWorldContextComponent : public CSimComponent
	{
	public:
		qNode<CWorldContextComponent> mNode;
		qMatrix44 mLatchTest;
		qMatrix44 mLatchContactPoint;
		qMatrix44 mWorldAnchor;
		bool mSyncFeet;
		bool mSyncLatchedHandle;
		int mSyncBoneIndex;
		bool mSyncPositionOnly;
		bool mSyncToClosestEndpoint;
		bool mSyncPlanar;
		bool mSyncXForward;
		bool mSyncLeftEdge;
		bool mSyncRightEdge;
		bool mLockSyncPosition;
		bool mSyncPositionLocked;
		float mDistanceFromEdge;
		float mBlendRate;
		float mBlendWeight;
		int mFocusLatchCount;
		qSafePointer<CParkourHandle> mFocusParkourHandle;
		qSafePointer<CParkourHandle> mParkourHandle;

		UFG_PAD(0x80);
		/*UFG::CoverCornerHandle mFocusCoverCornerHandle;
		UFG::CoverCornerHandle mLatchedCoverCornerHandle;*/

		void* mpCoverPosition;
		bool mbSyncingCoverParkour;
		bool mbSyncingCoverLCorner;
		bool mbSyncingCoverRCorner;
		qList<CAttachment> mAttachments;
		RebindingComponentHandle<CCharacterPhysicsComponent> mCharacterPhysicsComponent;
		CActionNode* mToSwimming;
		RebindingComponentHandle<CActionTreeComponent> mActionTreeComponent;

		void SetFocusParkourHandle(CParkourHandle* p_NewHandle)
		{
			reinterpret_cast<void(__fastcall*)(void*, CParkourHandle*, void*)>(UFG_RVA(0x54D1B0))(this, p_NewHandle, nullptr);
		}

		void SetParkourHandle(CParkourHandle* p_NewHandle)
		{
			reinterpret_cast<void(__fastcall*)(void*, CParkourHandle*)>(UFG_RVA(0x53C8D0))(this, p_NewHandle);
		}

		void ClearParkourHandles()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x522DB0))(this);
		}

		bool IsSyncing()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x53C1C0))(this);
		}

		void StopSync()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5528C0))(this);
		}
	};

	// Main
	class CSimCharacter : public CSimObject
	{
	public:
		__inline CCharacterAudioComponent* GetAudio()
		{
			return reinterpret_cast<CCharacterAudioComponent*>(GetComponentOfType(CharacterAudioComponent_TypeUID));
		}

		__inline CCharacterPropertiesComponent* GetCharacterProperties()
		{
			return GetComponentOfType<CCharacterPropertiesComponent>(CharacterPropertiesComponent_TypeUID);
		}

		__inline CAIScriptInterfaceComponent* GetAIScriptInterface()
		{
			return GetComponentOfType<CAIScriptInterfaceComponent>(CharacterAIScriptInterfaceComponent_TypeUID);
		}

		__inline CAICoverComponent* GetAICover()
		{
			return GetComponentOfType<CAICoverComponent>(CharacterAICoverComponent_TypeUID);
		}

		__inline CHealthComponent* GetHealth()
		{
			return GetComponentOfType<CHealthComponent>(CharacterHealthComponent_TypeUID);
		}

		__inline CCharacterAnimationComponent* GetAnimation()
		{
			return GetComponentOfType<CCharacterAnimationComponent>(CharacterAnimationComponent_TypeUID);
		}

		__inline CHitReactionComponent* GetHitReaction()
		{
			return GetComponentOfType<CHitReactionComponent>(CharacterHitReactionComponent_TypeUID);
		}

		__inline CAIActionTreeComponent* GetAIActionTree()
		{
			return GetComponentOfType<CAIActionTreeComponent>(CharacterAIActionTreeComponent_TypeUID);
		}

		__inline CTargetingSystemPedBaseComponent* GetTargetingSystemPed()
		{
			return GetComponentOfType<CTargetingSystemPedBaseComponent>(CharacterTargetingPedComponent_TypeUID);
		}

		__inline CTargetingSystemPedPlayerComponent* GetTargetingSystemPlayer()
		{
			return GetComponentOfType<CTargetingSystemPedPlayerComponent>(CharacterTargetingPedPlayerComponent_TypeUID);
		}

		__inline CAICharacterControllerBaseComponent* GetAICharacterController()
		{
			return GetComponentOfType<CAICharacterControllerBaseComponent>(CharacterAICharacterControllerComponent_TypeUID);
		}

		__inline CActiveAIEntityComponent* GetActiveAIEntity()
		{
			return GetComponentOfType<CActiveAIEntityComponent>(CharacterActiveAIEntityComponent_TypeUID);
		}

		__inline CCharacterPhysicsComponent* GetCharacterPhysics()
		{
			return GetComponentOfType<CCharacterPhysicsComponent>(CharacterPhysicsComponent_TypeUID);
		}

		__inline CCharacterNavComponent* GetNav()
		{
			return GetComponentOfType<CCharacterNavComponent>(CharacterNavComponent_TypeUID);
		}

		__inline CCharacterSubjectComponent* GetCharacterSubject()
		{
			return GetComponentOfType<CCharacterSubjectComponent>(CharacterSubjectComponent_TypeUID);
		}

		__inline CInventoryComponent* GetInventory()
		{
			return GetComponentOfType<CInventoryComponent>(CharacterInventoryComponent_TypeUID);
		}

		__inline CRagdollComponent* GetRagdoll()
		{
			return GetComponentOfType<CRagdollComponent>(CharacterRagdollComponent_TypeUID);
		}

		__inline CCharacterOccupantComponent* GetCharacterOccupant()
		{
			return GetComponentOfType<CCharacterOccupantComponent>(CharacterOccupantComponent_TypeUID);
		}

		__inline CAttackRightsComponent* GetAttackRights()
		{
			return GetComponentOfType<CAttackRightsComponent>(CharacterAttackRightsComponent_TypeUID);
		}

		__inline CAimingPlayerComponent* GetAimingPlayer()
		{
			return GetComponentOfType<CAimingPlayerComponent>(CharacterAimingPlayerComponent_TypeUID);
		}
	};
}