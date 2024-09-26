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

	class CCharacterControllerInterface : public SimComponent
	{
	public:
		UFG_PAD(0x10);

		RebindingComponentHandle<CActionTreeComponent> m_pActionTreeComponent;
	};

	// Components
	class CAIAwarenessComponent : public SimComponent
	{
	public:
		qNode<CAIAwarenessComponent> mNode;
		AIAwareness::CProfile* mpCurrentProfile;
		AIAwareness::CEffector* mpHeadEffector;
		AIAwareness::CEffector* mpEyeEffector;
		AIAwareness::CKnowledgeSpace* mpKnowledgeSpace;
		bool mEnabled;
	};

	class CHealthComponent : public SimComponent
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

		UFG_INLINE void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5497A0))(this);
		}

		UFG_INLINE void SetHealth(int p_Health)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, void*)>(UFG_RVA(0x54D3D0))(this, p_Health, nullptr);
		}

		UFG_INLINE void SetRegenerativeHealthRatio(float p_RegenerativeHealthRatio, bool p_SaveSnapshot)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x54E570))(this, p_RegenerativeHealthRatio, p_SaveSnapshot);
		}
	};

	class CAttackRightsComponent : public SimComponent
	{
	public:
		// Constructor, call with caution!
		static CAttackRightsComponent* PropertiesOnActivate(SceneObjectProperties* m_ObjectProperties)
		{
			return reinterpret_cast<CAttackRightsComponent * (__fastcall*)(SceneObjectProperties*)>(UFG_RVA(0x37E560))(m_ObjectProperties);
		}

		static bool HasComponent(SceneObjectProperties* m_ObjectProperties)
		{
			return reinterpret_cast<bool(__fastcall*)(SceneObjectProperties*)>(UFG_RVA(0x364DA0))(m_ObjectProperties);
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
		/*AmbientContextManager m_ambientContexts;
		qSafePointer<SimComponent, HealthComponent> m_healthComponent;
		qSafePointer<SimComponent, TransformNodeComponent> m_transformNodeComponent;
		qSafePointer<SimComponent, SimObjectCharacterPropertiesComponent> m_simObjectCharacterPropertiesComponent;*/

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

	class CCharacterEffectsComponent : public SimComponent, public qNode<CCharacterEffectsComponent>
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

	class CCharacterPropertiesComponent : public SimObjectPropertiesComponent
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

	class CAIScriptInterfaceComponent
	{
	public:

		void SetDesiredTarget(eTargetTypeEnum target_type, SimObject* target_object)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, SimObject*)>(UFG_RVA(0x386060))(this, target_type, target_object);
		}
	};

	class CAIActionTreeComponent : public SimComponent
	{
	public:
		UFG_PAD(0x98);
		CActionController mActionController;
	};

	class CAICoverComponent : public SimComponent
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
		qSafePointer<SimObject> m_pSimTargetSync;
		qSafePointer<SimObject> m_pSimTargetPopout;
		int m_iHoldCoverPositionRefs;
		int m_iAllowHoldCoverPositionUpdateRefs;
		int m_iSyncBoneID;

		static CAICoverComponent* PropertiesOnActivate(SceneObjectProperties* p_SceneObj)
		{
			return reinterpret_cast<CAICoverComponent*(__fastcall*)(SceneObjectProperties*)>(UFG_RVA(0x37E330))(p_SceneObj);
		}
	};

	class CAICharacterControllerBaseComponent : public CCharacterControllerInterface
	{
	public:
		CIntention m_Intention;
		bool m_IntentionUpdated;

		UFG_PAD(0x7);
		UFG_PAD(0x48);
		//qStaticBitField<548> m_ActionRequestMask;

		bool m_HoldMotionIntention;
		qVector3 m_HoldMotionIntentionDirection;
		float m_HoldMotionIntentionSpeed;
		float m_HoldBlend;
		float m_HoldBlendDelay;

		void DoParkour(qVector3* p_Direction, uint32_t p_CheckTypes)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, void*, uint32_t, CIntention*, bool)>(UFG_RVA(0x352DE0))(this, p_Direction, nullptr, p_CheckTypes, &m_Intention, false);
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

	class CAIEntityComponent : public SimComponent
	{
	public:
		UFG_PAD(0x4F8);
		/*RebindingComponentHandle<TransformNodeComponent, 0> m_pTransformNodeComponent;
		RebindingComponentHandle<ActionTreeComponent, 0> m_pActionTreeComponent;
		RebindingComponentHandle<RigidBodyComponent, 0> m_pRigidBodyComponent;
		RebindingComponentHandle<CharacterAnimationComponent, 0> m_pCharacterAnimationComponent;
		RebindingComponentHandle<SimObjectCharacterPropertiesComponent, 0> m_pSimObjectCharacterPropertiesComponent;
		RebindingComponentHandle<AttackRightsComponent, 0> m_pAttackRightsComponent;
		RebindingComponentHandle<SceneObjectProperties, 0> m_pSceneObjectProperties;
		RebindingComponentHandle<HealthComponent, 0> m_pHealthComponent;
		RebindingComponentHandle<TargetingSystemPedBaseComponent, 0> m_pTargetingSystemBaseComponent;
		RebindingComponentHandle<CharacterOccupantComponent, 0> m_pCharacterOccupantComponent;
		SidewalkWanderData m_WanderData;
		HeadTrackTarget m_HeadTrackingTarget;
		bool m_AIPositionValid;
		bool m_HostilityEnabled;
		NearbyCharacter* m_pNearbyCharacter;
		qSafePointer<GroupComponent, GroupComponent> m_pGroupComponent;
		qSafePointer<CombatRegion, CombatRegion> m_pCombatRegion;
		qFixedArray<ThreatTarget, 10> m_ThreatTargets;
		qVector3 m_vCombatRegionMoveToVec;
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

		void AddSupplementaryAttackTarget(SimObject* attack_target)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*)>(UFG_RVA(0x340E10))(this, attack_target);
		}

		void AddThreatTarget(SimObject* pTarget, float radius)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*, float)>(UFG_RVA(0x341190))(this, pTarget, radius);
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

	class CCharacterPhysicsComponent : public SimComponent
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

		UFG_INLINE void Update(float p_TimeDelta)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x476DC0))(this, p_TimeDelta);
		}

		UFG_INLINE void GetVelocity(qVector3* p_Result)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0x468150))(this, p_Result);
		}

		UFG_INLINE void SetVelocity(const qVector3& p_Velocity)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&)>(UFG_RVA(0x4757C0))(this, p_Velocity);
		}
	};

	class CRagdollComponent : public SimComponent
	{
	public:
		enum CollisionState
		{
			CS_DYNAMIC = 0x0,
			CS_KEYFRAMED_RAGDOLL_LAYER = 0x1,
			CS_KEYFRAMED_RAGDOLL_LAYER_2 = 0x2,
			CS_KEYFRAMED_NO_COLLISION = 0x3
		};

		enum PoseState
		{
			STATE_VELOCITY_TRACKING = 0x0,
			STATE_POWERED_TRACKING = 0x1,
			STATE_TRANSITION_TO_POWERED = 0x2,
			STATE_FORCE = 0x3,
			STATE_UNINITIALIZED = 0x4,
			STATE_KEYFRAME_TRACKING = 0x5,
			STATE_FREEZE_TRACKING = 0x6,
		};

		UFG_PAD(0x30);

		void* mRagdoll;
		void* mPose;
		float mRagDollWeight;
		float mVelocityFromProxyScale;
		PoseState mPoseState;
		PoseState mDesiredPoseState;
		uint32_t mLevelOfDetail;
		uint32_t mDesiredLevelOfDetail;
		__declspec(align(16)) qMatrix44 mPelvisRagdollWS;
		bool mLockHighLOD;
		int mAnimPelvisBoneIndex;
		int mReferenceCount;
		int mNumFramesInKeyframedMode;

		// This is should be only use to check if ragdoll is currently ragdolling be collision or some other source.
		// This will return false if the ragdoll is keyframed by some animation!
		UFG_INLINE bool IsActive()
		{
			return (mPoseState == STATE_VELOCITY_TRACKING || mPoseState == STATE_POWERED_TRACKING);
		}

		static UFG_INLINE CRagdollComponent* Acquire(SimObject* p_Object)
		{
			return reinterpret_cast<CRagdollComponent*(__fastcall*)(SimObject*)>(UFG_RVA(0x454510))(p_Object);
		}

		UFG_INLINE void Update(float p_TimeDelta)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x47BDC0))(this, p_TimeDelta);
		}

		UFG_INLINE void ApplyAngularImpulse(int p_Bone, const qVector3& p_Impulse, float p_ConnectionTransfer)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, const qVector3&, float)>(UFG_RVA(0x456310))(this, p_Bone, p_Impulse, p_ConnectionTransfer);
		}

		UFG_INLINE void ApplyImpulse(int p_Bone, const qVector3& p_Location, const qVector3& p_Impulse)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, const qVector3&, const qVector3&)>(UFG_RVA(0x4585F0))(this, p_Bone, p_Location, p_Impulse);
		}

		UFG_INLINE void SetCollisionState(CollisionState p_CollisionState)
		{
			reinterpret_cast<void(__fastcall*)(void*, CollisionState)>(UFG_RVA(0x474A00))(this, p_CollisionState);
		}

		UFG_INLINE void SetVelocity(const qVector3& p_Velocity)
		{
			if (mRagdoll) {
				reinterpret_cast<void(__fastcall*)(void*, const qVector3&)>(UFG_RVA(0xB2780))(this, p_Velocity);
			}
		}

		UFG_INLINE void SetMotorMaxForce(float p_fValue)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x475360))(this, p_fValue);
		}

		UFG_INLINE void SetLimitStiffness(float p_fValue)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x475160))(this, p_fValue);
		}

		UFG_INLINE void SetPositionTrackingStiffness(float p_fValue)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x475540))(this, p_fValue);
		}
	};

	class CCharacterSubjectComponent : public SimComponent
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

	class CCharacterNavComponent : public SimComponent
	{
	public:
		void AddGoalPoint(CHavokNavPosition* npDestination, AiPathGoalMode goalMode, float speed, float fDestinationTolerance)
		{
			reinterpret_cast<void(__fastcall*)(void*, CHavokNavPosition*, AiPathGoalMode, float, float)>(UFG_RVA(0x263430))(this, npDestination, goalMode, speed, fDestinationTolerance);
		}
	};

	class CInventoryComponent : public SimComponent
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

		UFG_STATIC_INLINE eTargetTypeEnum GetSlotTarget(int m_Slot)
		{
			switch (m_Slot)
			{
				default: return eTARGET_TYPE_EQUIPPED;
				case 1: return eTARGET_TYPE_EQUIPPED_LEFT_HAND;
				case 2: return eTARGET_TYPE_EQUIPPED_HAT;
				case 3: return eTARGET_TYPE_EQUIPPED_GLASSES;
				case 4: return eTARGET_TYPE_STOWED_WEAPON;
				case 5: return eTARGET_TYPE_STOWED_2H_WEAPON;
			}
		}

		void SetCanDrop(int p_Slot, bool p_CanDrop)
		{
			m_EquipSlots.p[p_Slot] = p_CanDrop;
		}

		bool Equip(SimObject* p_ObjectToEquip, bool p_UseEquipSlot = false, int p_Slot = 0)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, SimObject*, bool, int)>(UFG_RVA(0x526F90))(this, p_ObjectToEquip, p_UseEquipSlot, p_Slot);
		}

		void UnEquip(int p_Slot = 0, bool p_DeleteFromWorld = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool, int)>(UFG_RVA(0x557A40))(this, p_Slot, p_DeleteFromWorld);
		}
		
		void RemoveObjectFromInventory(SimObject* p_Object)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*)>(UFG_RVA(0x549120))(this, p_Object);
		}

		void Stow(int p_Slot, int p_DestinationSlot)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, int)>(UFG_RVA(0x552A40))(this, p_Slot, p_DestinationSlot);
		}
	};

	class CInterestPointUserComponent : public SimComponent
	{
	public:
		void StopPOI()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3892D0))(this);
		}
	};

	class CAimingBaseComponent : public SimComponent
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
		qSafePointer<SimObject> m_FreeAimSimObject;

		UFG_PAD(0x28);
		//qReflectHandle<PhysicsObjectProperties> m_FreeAimPhysicsObjectProperties;

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
		qVector3 m_vSoftLockOffset;
		float m_fFreeAimSpeedModifier;
		float m_fInterpolatedFreeAimConeClamp;
		eTargetTypeEnum m_eSnapFreeAimIntentionToTarget;

		UFG_PAD(0x20);
		/*qList<AimingSoftLockTask, AimingSoftLockList, 0, 0> m_AimingSoftLockTaskList;
		qList<AimingFreeAimConeClampTask, AimingFreeAimConeClampList, 0, 0> m_AimingFreeAimConeClampTaskList;*/

		__int8 m_bPerformAimObscuredCheck : 1;
		float m_fUnobscuredAimCheckDistance;
		float m_fUnobscuredAimTargetPositionPadDistance;
		float m_fUnobscuredAimNewPositionPadDistance;
		qSafePointer<SimObject> m_pAimTargetPositionSimObject;
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

	class CSensorComponent : public SimComponent
	{
	public:
		CParkourHandle* FindClosestParkourHandle(qVector3* p_Position, qVector3* p_Orentation, float p_Angle, float p_BufferZone, float p_DistanceMinXY, float p_DistanceMaxXY, float p_DistanceMinZ, float p_DistanceMaxZ, eSimObjectVehicleTypeEnum checkAttachedToVehicleType, Parkour::CheckFlags p_CheckFlags, qVector3* p_ContactPosition)
		{
			return reinterpret_cast<CParkourHandle*(__fastcall*)(void*, qVector3*, qVector3*, float, float, float, float, float, float, eSimObjectVehicleTypeEnum, Parkour::CheckFlags, qVector3*)>(UFG_RVA(0x27B370))(this, p_Position, p_Orentation, p_Angle, p_BufferZone, p_DistanceMinXY, p_DistanceMaxXY, p_DistanceMinZ, p_DistanceMaxZ, checkAttachedToVehicleType, p_CheckFlags, p_ContactPosition);
		}
	};

	class CWorldContextComponent : public SimComponent
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
		/*CoverCornerHandle mFocusCoverCornerHandle;
		CoverCornerHandle mLatchedCoverCornerHandle;*/

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
	class SimCharacter : public SimObject
	{
	public:
		UFG_INLINE CCharacterAudioComponent* GetAudio()
		{
			return reinterpret_cast<CCharacterAudioComponent*>(GetComponentOfType(CharacterAudioComponent_TypeUID));
		}

		UFG_INLINE CCharacterPropertiesComponent* GetCharacterProperties()
		{
			return GetComponentOfType<CCharacterPropertiesComponent>(CharacterPropertiesComponent_TypeUID);
		}

		UFG_INLINE CAIScriptInterfaceComponent* GetAIScriptInterface()
		{
			return GetComponentOfType<CAIScriptInterfaceComponent>(CharacterAIScriptInterfaceComponent_TypeUID);
		}

		UFG_INLINE CAICoverComponent* GetAICover()
		{
			return GetComponentOfType<CAICoverComponent>(CharacterAICoverComponent_TypeUID);
		}

		UFG_INLINE CHealthComponent* GetHealth()
		{
			return GetComponentOfType<CHealthComponent>(CharacterHealthComponent_TypeUID);
		}

		UFG_INLINE CCharacterAnimationComponent* GetAnimation()
		{
			return GetComponentOfType<CCharacterAnimationComponent>(CharacterAnimationComponent_TypeUID);
		}

		UFG_INLINE CHitReactionComponent* GetHitReaction()
		{
			return GetComponentOfType<CHitReactionComponent>(CharacterHitReactionComponent_TypeUID);
		}

		UFG_INLINE CAIActionTreeComponent* GetAIActionTree()
		{
			return GetComponentOfType<CAIActionTreeComponent>(CharacterAIActionTreeComponent_TypeUID);
		}

		UFG_INLINE CTargetingSystemPedBaseComponent* GetTargetingSystemPed()
		{
			return GetComponentOfType<CTargetingSystemPedBaseComponent>(CharacterTargetingPedComponent_TypeUID);
		}

		UFG_INLINE CTargetingSystemPedPlayerComponent* GetTargetingSystemPlayer()
		{
			return GetComponentOfType<CTargetingSystemPedPlayerComponent>(CharacterTargetingPedPlayerComponent_TypeUID);
		}

		UFG_INLINE CAICharacterControllerBaseComponent* GetAICharacterController()
		{
			return GetComponentOfType<CAICharacterControllerBaseComponent>(CharacterAICharacterControllerComponent_TypeUID);
		}

		UFG_INLINE CActiveAIEntityComponent* GetActiveAIEntity()
		{
			return GetComponentOfType<CActiveAIEntityComponent>(CharacterActiveAIEntityComponent_TypeUID);
		}

		UFG_INLINE CCharacterPhysicsComponent* GetCharacterPhysics()
		{
			return GetComponentOfType<CCharacterPhysicsComponent>(CharacterPhysicsComponent_TypeUID);
		}

		UFG_INLINE CCharacterNavComponent* GetNav()
		{
			return GetComponentOfType<CCharacterNavComponent>(CharacterNavComponent_TypeUID);
		}

		UFG_INLINE CCharacterSubjectComponent* GetCharacterSubject()
		{
			return GetComponentOfType<CCharacterSubjectComponent>(CharacterSubjectComponent_TypeUID);
		}

		UFG_INLINE CInventoryComponent* GetInventory()
		{
			return GetComponentOfType<CInventoryComponent>(CharacterInventoryComponent_TypeUID);
		}

		UFG_INLINE CRagdollComponent* GetRagdoll()
		{
			return GetComponentOfType<CRagdollComponent>(CharacterRagdollComponent_TypeUID);
		}

		UFG_INLINE CharacterOccupantComponent* GetCharacterOccupant()
		{
			return GetComponentOfType<CharacterOccupantComponent>(CharacterOccupantComponent_TypeUID);
		}

		UFG_INLINE CAttackRightsComponent* GetAttackRights()
		{
			return GetComponentOfType<CAttackRightsComponent>(CharacterAttackRightsComponent_TypeUID);
		}

		UFG_INLINE CAimingPlayerComponent* GetAimingPlayer()
		{
			return GetComponentOfType<CAimingPlayerComponent>(CharacterAimingPlayerComponent_TypeUID);
		}
	}; 
	typedef SimCharacter CSimCharacter;
}