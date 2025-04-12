#pragma once

namespace UFG
{
	enum eParkourType
	{
		eParkourType_None,
		eParkourType_Reluctant,
		eParkourType_Normal,
		NUM_PARKOUR_TYPES
	};
}

namespace UFG
{
	enum eHeadTrackType
	{
		eHEAD_TRACK_TYPE_TRANSFORM_NODE,
		eHEAD_TRACK_TYPE_POSITION,
		NUM_HEAD_TRACK_TYPES,
		eHEAD_TRACK_TYPE_NONE = -1,
	};

	class HeadTrackTarget
	{
	public:
		eHeadTrackType m_Type;
		qVector3 m_Offset;
		qSafePointer<TransformNodeComponent> m_pTransformNodeComponent;
		qVector3 m_Position;
	};

	class ThreatTarget
	{
	public:
		qSafePointer<SimObject> m_pTarget;
		f32 m_Radius;
	};

	class AIEntityComponent : public SimComponent
	{
	public:
		enum { _TypeUID = 0x46000001 };

		RebindingComponentHandle<TransformNodeComponent> m_pTransformNodeComponent;
		RebindingComponentHandle<ActionTreeComponent> m_pActionTreeComponent;
		RebindingComponentHandle<RigidBodyComponent> m_pRigidBodyComponent;
		RebindingComponentHandle<CharacterAnimationComponent> m_pCharacterAnimationComponent;
		RebindingComponentHandle<SimObjectCharacterPropertiesComponent> m_pSimObjectCharacterPropertiesComponent;
		RebindingComponentHandle<AttackRightsComponent> m_pAttackRightsComponent;
		RebindingComponentHandle<SceneObjectProperties> m_pSceneObjectProperties;
		RebindingComponentHandle<HealthComponent> m_pHealthComponent;
		RebindingComponentHandle<TargetingSystemPedBaseComponent> m_pTargetingSystemBaseComponent;
		RebindingComponentHandle<CharacterOccupantComponent> m_pCharacterOccupantComponent;
		SidewalkWanderData m_WanderData;
		HeadTrackTarget m_HeadTrackingTarget;
		bool m_AIPositionValid;
		bool m_HostilityEnabled;
		NearbyCharacter* m_pNearbyCharacter;
		qSafePointer<GroupComponent> m_pGroupComponent;
		qSafePointer<CombatRegion> m_pCombatRegion;
		qFixedArray<ThreatTarget, 10> m_ThreatTargets;
		qVector3 m_vCombatRegionMoveToVec;
		bool m_bActive;
		bool m_bCanWander;
		bool m_bRefreshWander;
		bool m_bCanUseCrosswalks;

		/* Impl Functions */

		SDK_INLINE void ClearThreatTargets() { m_ThreatTargets.size = 0; }
		SDK_INLINE CharacterOccupantComponent* GetCharacterOccupantComponent() { return m_pCharacterOccupantComponent.GetComponent(); }
		SDK_INLINE HealthComponent* GetHealthComponent() { return m_pHealthComponent.GetComponent(); }
		SDK_INLINE SimObjectCharacterPropertiesComponent* GetSimObjectCharacterPropertiesComponent() { return m_pSimObjectCharacterPropertiesComponent.GetComponent(); }
		SDK_INLINE TargetingSystemPedBaseComponent* GetTargetingSystemBaseComponent() { return m_pTargetingSystemBaseComponent.GetComponent(); }
		SDK_INLINE void StopHeadTracking() { m_HeadTrackingTarget.m_Type = eHEAD_TRACK_TYPE_NONE; }

		/* Functions */

		void AddThreatTarget(SimObject* pTarget, f32 radius) { SDK_CALL_FUNC(void, 0x341190, void*, SimObject*, f32)(this, pTarget, radius); }
		bool CanWalkStraightToPoint(const qVector3& point, eConstrainToSidewalks constrain_to_sidewalks, qVector3* last_valid_point) {
			return SDK_CALL_FUNC(bool, 0x34CBF0, void*, const qVector3&, eConstrainToSidewalks, qVector3*)(this, point, constrain_to_sidewalks, last_valid_point);
		}
		void OnSiblingsChanged() { SDK_CALL_FUNC(void, 0x37BC00, void*)(this); }
		void SetCombatRegion(CombatRegion* pRegion) { SDK_CALL_FUNC(void, 0x3850F0, void*, CombatRegion*)(this, pRegion); }
		void SetGroupComponent(GroupComponent* value) { SDK_CALL_FUNC(void, 0x4166A0, void*, GroupComponent*)(this, value); }
		void SetHeadTrackingPosition(TransformNodeComponent* transform_node_component, const qVector3& offset) { 
			SDK_CALL_FUNC(void, 0x386600, void*, TransformNodeComponent*, const qVector3&)(this, transform_node_component, offset);
		}
		void SetHeadTrackingPosition(const qVector3& position) { SDK_CALL_FUNC(void, 0x3865A0, void*, const qVector3&)(this, position); }
	};
	SDK_ASSERT_SIZEOF(AIEntityComponent, 0x538);

	class ActiveAIEntityComponent : public AIEntityComponent, public qNode<ActiveAIEntityComponent>
	{
	public:
		enum { _TypeUID = 0x46000003 };

		PedKnowledgeBase m_KnowledgeBase;
		RebindingComponentHandle<AIActionTreeComponent> m_pAIActionTreeComponent;
		RebindingComponentHandle<CharacterControllerInterface> m_pCharacterController;
		RebindingComponentHandle<AICharacterControllerBaseComponent> m_pAICharacterControllerBaseComponent;
		qSafePointer<SimComponent, FormationManagerComponent> m_pCurrentFormationManagerComponent;
		qSafePointer<SimComponent, PedFormationManagerComponent> m_pCurrentPedFormationManagerComponent;
		RebindingComponentHandle<CharacterPhysicsComponent> m_pCharacterPhysicsComponent;
		RebindingComponentHandle<HitReactionComponent> m_pHitReactionComponent;
		RebindingComponentHandle<AIScriptInterfaceComponent> m_pAIScriptInterfaceComponent;
		RebindingComponentHandle<InterestPointUserComponent> m_pInterestPointUserComponent;
		bool m_CompletedNavigationTask[2];
		qSafePointer<SimComponent, AttackRightsComponent> m_pCurrentAttackTarget;
		f32 m_MinTimeBetweenUpdateTarget;
		f32 m_MaxTimeBetweenUpdateTarget;
		f32 m_NextTimeToUpdateAttackTarget;
		f32 m_TimeAllowedToKeepAttackingDeadTarget;
		qSafePointer<SimObject> m_pDesiredTarget[91];
		qList<SupplementaryAttackTarget> m_SupplementaryAttackTargets;
		f32 m_MaxEngagementDistanceXY;
		f32 m_MaxEngagementDistanceZ;
		bool m_EngagementOverrideEnabled;
		eAIEmotion m_CurrentEmotion;
		eAIEmotion m_FacialEmotion;
		eAIObjective m_CurrentObjective;
		bool m_PrevObjectiveWasHostile;
		eTargetTypeEnum m_TargetToStayNear;
		f32 m_MaxDistanceFromTargetToStayNear;
		f32 m_MaxDistanceFromTargetToStayNearHysteresis;
		f32 m_ChanceOfCleanVault;
		eParkourType m_ScriptedParkourTypeNearGoal;
		eParkourType m_ScriptedParkourTypeFarGoal;
		bool m_ScriptOverrideFreerunning;
		bool m_CleanNextVault;
		bool m_IsSpawning;
		bool m_InPOIDynamicBranch;
		bool m_InPropInteractBranch;

		/* Virtual Functions */

		virtual void _UnkVFunc14() = 0;
		virtual void Update(f32 delta_sec) = 0;
		virtual void EndFrame() = 0;

		/* Static Functions */

		SDK_SINLINE ActiveAIEntityComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(ActiveAIEntityComponent*, 0x37EA60, SceneObjectProperties*, bool)(pSceneObj, required);
		}

		/* Impl Functions */

		SDK_INLINE AIActionTreeComponent* GetAIActionTreeComponent() { return m_pAIActionTreeComponent.GetComponent(); }

		/* Functions */

		void AddSupplementaryAttackTarget(SimObject* attack_target) { SDK_CALL_FUNC(void, 0x340E10, void*, SimObject*)(this, attack_target); }
		bool CanBeEngagedMelee(AttackRightsComponent* potential_attack_target) { return SDK_CALL_FUNC(bool, 0x34BCA0, void*, AttackRightsComponent*)(this, potential_attack_target); }
		bool CanBeEngagedShared(AttackRightsComponent* potential_attack_target) { return SDK_CALL_FUNC(bool, 0x34BEE0, void*, AttackRightsComponent*)(this, potential_attack_target); }
		f32 GetAttackabilityScoreMelee(AttackRightsComponent* potential_attack_target) { return SDK_CALL_FUNC(f32, 0x35A340, void*, AttackRightsComponent*)(this, potential_attack_target); }
		f32 GetAttackabilityScoreRanged(AttackRightsComponent* potential_attack_target) { return SDK_CALL_FUNC(f32, 0x35A660, void*, AttackRightsComponent*)(this, potential_attack_target); }
		f32 GetEncounterFocusTargetScore(SimObject* pMyself) { return SDK_CALL_FUNC(f32, 0x35F310, void*, SimObject*)(this, pMyself); }
		bool IsEnemyOfMine(AttackRightsComponent* potential_attack_target) { return SDK_CALL_FUNC(bool, 0x36A690, void*, AttackRightsComponent*)(this, potential_attack_target); }
		bool IsEnemyOfMine(SimObject* pSimObject) { return SDK_CALL_FUNC(bool, 0x36A740, void*, SimObject*)(this, pSimObject); }
		bool IsSupplementaryAttackTarget(AttackRightsComponent* potential_attack_target) { return SDK_CALL_FUNC(bool, 0x36BBB0, void*, AttackRightsComponent*)(this, potential_attack_target); }
		void RemoveSupplementaryAttackTarget(SimObjectGame* attack_target) { SDK_CALL_FUNC(void, 0x3814A0, void*, SimObjectGame*)(this, attack_target); }
		void Reset() { SDK_CALL_FUNC(void, 0x382840, void*)(this); }
		void ResetAndLoadProperties() { SDK_CALL_FUNC(void, 0x382F00, void*)(this); }
		void RestartPoiCooldown() { SDK_CALL_FUNC(void, 0x383DB0, void*)(this); }
		void SetBehaviourTree(const char* behaviour_tree_name) { SDK_CALL_FUNC(void, 0x385000, void*, const char*)(this, behaviour_tree_name); }

		void SetCurrentObjective(eAIObjective objective, const char* caller_debug_name = 0) {
			SDK_CALL_FUNC(void, 0x3852B0, void*, eAIObjective, const char*)(this, objective, caller_debug_name);
		}

		void SetParkourSuccessRate(f32 val) { SDK_CALL_FUNC(void, 0x387A00, void*, f32)(this, val); }
		void UpdateCurrentAttackTarget() { SDK_CALL_FUNC(void, 0x3948E0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(ActiveAIEntityComponent, 0x1070);
}