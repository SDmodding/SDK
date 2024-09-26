#pragma once

namespace UFG
{
	class TargetingSimObject
	{
	public:
		qNode<TargetingSimObject> mNode;
		class TargetingSystemBaseComponent* m_pTSBC;
		qSafePointer<SimObject> m_pTarget;
		uint8_t m_eTargetType;
		bool m_bLock;
	}; typedef TargetingSimObject CTargetingSimObject;

	//================================================================================================================================

	class TargetingSystemBaseComponent : public SimComponent
	{
	public:
		UFG_PAD(0x18);

		TargetingSimObject* m_pTargets;

		struct TargetingMap_t
		{
			uint32_t m_uNumValidTargetTypes;
			qFixedArray<uint8_t, 91> m_Map;
		};
		TargetingMap_t* m_pTargetingMap;
		qList<TargetingSimObject> m_TargetedBy;

		UFG_INLINE TargetingSimObject* GetTarget(eTargetTypeEnum p_TargetType)
		{
			return &m_pTargets[m_pTargetingMap->m_Map.p[p_TargetType]];
		}

		template <typename T>
		UFG_INLINE T* GetTargetPtr(eTargetTypeEnum p_TargetType)
		{
			return reinterpret_cast<T*>(GetTarget(p_TargetType)->m_pTarget.m_pPointer);
		}

		UFG_INLINE void SetTarget(eTargetTypeEnum p_TargetType, SimObject* p_SimObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, SimObject*)>(UFG_RVA(0x54ED20))(this, p_TargetType, p_SimObject);
		}

		UFG_INLINE void ClearTarget(eTargetTypeEnum p_TargetType)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum)>(UFG_RVA(0x15DFB0))(this, p_TargetType);
		}
	}; typedef TargetingSystemBaseComponent CTargetingSystemBaseComponent;

	//================================================================================================================================

	class TargetingSystemPedBaseComponent : public TargetingSystemBaseComponent
	{
	public:
		qNode<TargetingSystemPedBaseComponent> m_Node;
		RebindingComponentHandle<TransformNodeComponent> m_pTransformNodeComponent;
		RebindingComponentHandle<class CAimingBaseComponent> m_pAimingBaseComponent;
		RebindingComponentHandle<class ActionTreeComponent> m_pActionTreeComponent;
		RebindingComponentHandle<class CActiveAIEntityComponent> m_pActiveAIEntityComponent;
		RebindingComponentHandle<class CCharacterPropertiesComponent> m_pSimObjectCharacterPropertiesComponent;
		RebindingComponentHandle<class CAICharacterControllerComponent> m_pAICharacterControllerComponent;
		RebindingComponentHandle<class CAICharacterControllerBaseComponent> m_pAICharacterControllerBaseComponent;
		RebindingComponentHandle<void*> m_pInterestPointUserComponent;
		qSafePointer<class SimWeaponPropertiesComponent> m_pEquippedSOWPC;
		qList<void*> m_TargetSteerToTaskList;
		bool m_bHasRangedWeapon;
		bool m_bIsValidSocialTarget;
		uint32_t m_uUpdateBucket;
		uint32_t* m_pBucketList;
		bool m_bForceUpdate;
		qFixedArray<qSafePointer<SimObject>, 80> m_CachedPedsList;

		struct ClosePhysicalTarget_t
		{
			float m_fDistance2;
			class RigidBodyComponent* m_pRigidBodyComponent;
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
		SimObject* m_pLastFocusTarget;
		float m_fMinimumTargetDistanceSquared;

		void SetTargetLock(eTargetTypeEnum eTargetType, bool bLock, const bool bModifyCollisionAccordingToLock)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, bool, bool)>(UFG_RVA(0x54EE70))(this, eTargetType, bLock, bModifyCollisionAccordingToLock);
		}
	}; typedef TargetingSystemPedBaseComponent CTargetingSystemPedBaseComponent;

	//================================================================================================================================

	class TargetingSystemPedNPCCombatantComponent : public TargetingSystemPedBaseComponent
	{
	public:

	}; typedef TargetingSystemPedNPCCombatantComponent CTargetingSystemPedNPCCombatantComponent;

	//================================================================================================================================

	class TargetingSystemPedPlayerComponent : public TargetingSystemPedBaseComponent
	{
	public:
		qNode<TargetingSystemPedPlayerComponent> m_Node;
		RebindingComponentHandle<class CCharacterAnimationComponent> m_pCharacterAnimationComponent;
		RebindingComponentHandle<class CAimingPlayerComponent> m_pAimingPlayerComponent;
		RebindingComponentHandle<class CAttackRightsComponent> m_pAttackRightsComponent;
		qSafePointer<class CRagdollComponent> m_RagdollTarget;
		qSafePointer<class CRagdollComponent> m_FocusTargetsGrappleTarget;
		qSafePointer<SimObject> m_pVehicleFocusTarget;
		qSafePointer<SimObject> m_pFocusModeOverrideSimObject;
		qSafePointer<SimObject> m_pOccupantOfVehicle;
		qSafePointer<SimObject> m_pVehicleClosestPointSimObject;
		qSafePointer<TransformNodeComponent> m_pVehicleClosestPointTNC;

		struct RimLighting_t
		{
			bool m_bEnabled;
			eTargetTypeEnum m_TargetType;
			qSafePointer<SimObject> m_Target;
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
		SceneObjectProperties* m_pDriverSceneObjectProperties;
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
			class SimObjectPropertiesComponent* m_pSimObjectPropertiesComponent;
			qMatrix44 m_Xform;
		};
		qFixedArray<CloseTarget_t, 100> m_CloseTargetsList;

		void SetFocusMode(eFocusModeEnum p_FocusMode)
		{
			reinterpret_cast<void(__fastcall*)(void*, eFocusModeEnum)>(UFG_RVA(0x54D100))(this, p_FocusMode);
		}
	}; typedef TargetingSystemPedPlayerComponent CTargetingSystemPedPlayerComponent;
}