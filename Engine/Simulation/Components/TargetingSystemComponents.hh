#pragma once

namespace UFG
{
	class CTargetingSimObject
	{
	public:
		qNode<CTargetingSimObject> mNode;
		class CTargetingSystemBaseComponent* m_pTSBC;
		qSafePointer<CSimObject> m_pTarget;
		uint8_t m_eTargetType;
		bool m_bLock;
	};

	//================================================================================================================================

	class CTargetingSystemBaseComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x18);

		CTargetingSimObject* m_pTargets;

		struct TargetingMap_t
		{
			uint32_t m_uNumValidTargetTypes;
			qFixedArray<uint8_t, 91> m_Map;
		};
		TargetingMap_t* m_pTargetingMap;
		qList<CTargetingSimObject> m_TargetedBy;

		CTargetingSimObject* GetTarget(eTargetTypeEnum m_TargetType)
		{
			return &m_pTargets[m_pTargetingMap->m_Map.p[m_TargetType]];
		}

		void SetTarget(eTargetTypeEnum m_TargetType, CSimObject* m_SimObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, CSimObject*)>(UFG_RVA(0x54ED20))(this, m_TargetType, m_SimObject);
		}

		void ClearTarget(eTargetTypeEnum m_TargetType)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum)>(UFG_RVA(0x15DFB0))(this, m_TargetType);
		}
	};

	//================================================================================================================================

	class CTargetingSystemPedBaseComponent : public CTargetingSystemBaseComponent
	{
	public:
		qNode<CTargetingSystemPedBaseComponent> m_Node;
		RebindingComponentHandle<CTransformNodeComponent> m_pTransformNodeComponent;
		RebindingComponentHandle<class CAimingBaseComponent> m_pAimingBaseComponent;
		RebindingComponentHandle<class CActionTreeComponent> m_pActionTreeComponent;
		RebindingComponentHandle<class CActiveAIEntityComponent> m_pActiveAIEntityComponent;
		RebindingComponentHandle<class CCharacterPropertiesComponent> m_pSimObjectCharacterPropertiesComponent;
		RebindingComponentHandle<class CAICharacterControllerComponent> m_pAICharacterControllerComponent;
		RebindingComponentHandle<class CAICharacterControllerBaseComponent> m_pAICharacterControllerBaseComponent;
		RebindingComponentHandle<void*> m_pInterestPointUserComponent;
		qSafePointer<class CSimWeaponPropertiesComponent> m_pEquippedSOWPC;
		qList<void*> m_TargetSteerToTaskList;
		bool m_bHasRangedWeapon;
		bool m_bIsValidSocialTarget;
		uint32_t m_uUpdateBucket;
		uint32_t* m_pBucketList;
		bool m_bForceUpdate;
		qFixedArray<qSafePointer<CSimObject>, 80> m_CachedPedsList;

		struct ClosePhysicalTarget_t
		{
			float m_fDistance2;
			class CRigidBodyComponent* m_pRigidBodyComponent;
		};
		qFixedArray<ClosePhysicalTarget_t, 10> m_ClosePhysicalTargetsList;

		void* m_pActiveTargetingProfile;
		qVector3 m_vTargetingPosition;
		qVector3 m_vTargetingForward;
		qVector3 m_vTargetingLeft;
		qVector3 m_vTargetingIntention;
		void* m_pFocusTargetSubTargetingLocation;
		void* m_pLastFocusTargetSubTargetingLocation;
		void* m_pFocusTargetSubTargetingLocationOverride;
		CSimObject* m_pLastFocusTarget;
		float m_fMinimumTargetDistanceSquared;

		void SetTargetLock(eTargetTypeEnum eTargetType, bool bLock, const bool bModifyCollisionAccordingToLock)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, bool, bool)>(UFG_RVA(0x54EE70))(this, eTargetType, bLock, bModifyCollisionAccordingToLock);
		}
	};

	//================================================================================================================================

	class CTargetingSystemPedNPCCombatantComponent : public CTargetingSystemPedBaseComponent
	{
	public:

	};

	//================================================================================================================================

	class CTargetingSystemPedPlayerComponent : public CTargetingSystemPedBaseComponent
	{
	public:
		qNode<CTargetingSystemPedPlayerComponent> m_Node;
		RebindingComponentHandle<class CCharacterAnimationComponent> m_pCharacterAnimationComponent;
		RebindingComponentHandle<class CAimingPlayerComponent> m_pAimingPlayerComponent;
		RebindingComponentHandle<class CAttackRightsComponent> m_pAttackRightsComponent;
		qSafePointer<class CRagdollComponent> m_RagdollTarget;
		qSafePointer<class CRagdollComponent> m_FocusTargetsGrappleTarget;
		qSafePointer<CSimObject> m_pVehicleFocusTarget;
		qSafePointer<CSimObject> m_pFocusModeOverrideSimObject;
		qSafePointer<CSimObject> m_pOccupantOfVehicle;
		qSafePointer<CSimObject> m_pVehicleClosestPointSimObject;
		qSafePointer<CTransformNodeComponent> m_pVehicleClosestPointTNC;

		struct RimLighting_t
		{
			bool m_bEnabled;
			eTargetTypeEnum m_TargetType;
			qSafePointer<CSimObject> m_Target;
		};
		RimLighting_t m_RimLighting;

		qSafePointer<class CRagdollComponent> m_VehicleCharacterRagdolls[10];
		bool m_bIsAimingActive;
		bool m_bIsTransitionalAttackActive;
		bool m_bFocusModeJustRequested;
		bool m_bHasFreeAimInput;
		bool m_bHasAimInput;
		bool m_bHasNoAimInputTransition;
		bool m_bHasFullAimInput;
		bool m_bHasFullAimInputTransition;
		bool m_bFocusTargetIsHostile;
		bool m_bTargetAutoAcquisition;
		bool m_bTargetAutoAcquisitionJustRequested;
		bool m_bTargetingFreeShootingDesired;
		bool m_bTargetingFreeAimAssistance;
		float m_fAimInputLength;
		bool m_bAimInputRaw;
		qVector2 m_vAimInput;
		qVector2 m_vAimInputDir;
		qVector2 m_vLockedFreeAimInput;
		eFocusModeEnum m_eOverrideDesiredFocusMode;
		eFocusModeEnum m_eDesiredFocusMode;
		eFocusModeEnum m_eFocusMode;
		float m_fLastLocationTargetingAngle;
		float m_fTargetingIntentionIdleTime;
		qVector3 m_vDirectionalTargetingIntention;
		qVector3 m_vAimTargetingIntention;
		bool m_bHasPriorityTarget;
		bool m_bIsInAnyCombat;
		bool m_TransitTargetingDisabledByMiniGame;
		bool m_TransitTargetingDisabledByScript;
		int m_iVisibilityFromBoneID;
		CSceneObjectProperties* m_pDriverSceneObjectProperties;
		void* m_pDriverFaceActionComponent;
		int m_eDriverFaceActionType;
		eInventoryItemEnum m_eDriverSellableItemType;
		eInventoryItemEnum m_eDriverOriginalSellableItemType;
		qVector3* m_ConeToIntentionMap[6];
		float m_fTimeSinceStartedInput;
		bool m_bTargetCycleDirectionLeft;
		bool m_bTargetCycleDesired;

		struct CloseTarget_t
		{
			float m_fDistance2;
			class CSimObjectPropertiesComponent* m_pSimObjectPropertiesComponent;
			qMatrix44 m_Xform;
		};
		qFixedArray<CloseTarget_t, 100> m_CloseTargetsList;

		void SetFocusMode(eFocusModeEnum p_FocusMode)
		{
			reinterpret_cast<void(__fastcall*)(void*, eFocusModeEnum)>(UFG_RVA(0x54D100))(this, p_FocusMode);
		}
	};
}