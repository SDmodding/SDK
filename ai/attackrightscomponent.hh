#pragma once

namespace UFG
{
	enum eAttackSlotList
	{
		eATTACK_SLOT_LIST_ON_SCREEN,
		eATTACK_SLOT_LIST_OFF_SCREEN,
		NUM_ATTACK_SLOT_LISTS,
		eATTACK_SLOT_LIST_NONE = -1,
	};

	class AttackSlotInfo
	{
	public:
		eAttackSlotList m_AttackSlotList;
		int m_AttackSlot;
	};

	class InCombatParams
	{
	public:
		f32 m_CloseDistance;
		f32 m_FarDistance;
		f32 m_NarrowAngle;
		f32 m_WideAngle;
	};

	class AttackRightsComponent : public SimComponent, public qNode<AttackRightsComponent>
	{
	public:
		enum { _TypeUID = 0x4A000001 };

		bool m_DebugDrawEnabled;
		qSafePointer<HasAttackRequestNode> m_pAttackSlot[3][2][64];
		int m_NumAttackSlots[3];
		bool m_AllowedToUseAttackSlotList[3][2];
		bool m_OverrideAllowedToUseAttackSlotListThisFrame[3][2];
		f32 m_NextTimeToUpdateAllowedToUseAttackSlotList[3];
		int m_NextAttackBaton[3][2];
		qSafePointer<HasAttackRequestNode> m_pCachedNextAttacker[3];
		qSafePointer<HasAttackRequestNode> m_pPreviousBestAttacker[3];
		f32 m_NextTimeToUpdatePreviousBestAttacker[3];
		f32 m_TimeUntilNextAttack[3];
		bool m_AttackingEnabled[3];
		bool m_InCombatWithSomeone;
		InCombatParams m_InCombatParams;
		f32 m_MinTimeBetweenAttackerSwitch;
		f32 m_MaxTimeBetweenAttackerSwitch;
		f32 m_NextTimeCanPerformRunningAttack;
		bool m_RunningAttacksEnabled;
		f32 m_NextTimeCanPerformOpportunityAttack[3];
		bool m_IsDowned;
		f32 m_LastTimeHadAttackerRegistered[3];
		bool m_CurrentlyAttacking[3];
		qList<HasAttackRequestNode> m_AttackSlotQueue[3];
		qList<HasAttackRequestNode> m_FollowerAttackSlotQueue[3];
		RebindingComponentHandle<FormationManagerComponent> m_pFormationManagerComponent;
		RebindingComponentHandle<TransformNodeComponent> m_pTransformNodeComponent;
		RebindingComponentHandle<AIEntityComponent> m_pAIEntityComponent;
		RebindingComponentHandle<ActionTreeComponent> m_pActionTreeComponent;
		RebindingComponentHandle<CharacterPhysicsComponent> m_pCharacterPhysicsComponent;
		RebindingComponentHandle<SimObjectCharacterPropertiesComponent> m_pSimObjectCharacterPropertiesComponent;
		RebindingComponentHandle<HitReactionComponent> m_pHitReactionComponent;
		RebindingComponentHandle<HealthComponent> m_pHealthComponent;
		RebindingComponentHandle<AIScriptInterfaceComponent> m_pAIScriptInterfaceComponent;
		RebindingComponentHandle<TargetingSystemBaseComponent> m_pTargetingSystemBaseComponent;
		RebindingComponentHandle<CharacterOccupantComponent> m_pCharacterOccupantComponent;
		qSafePointer<HasAttackRequestNode> m_pNextAttacker;
		qSafePointer<HasAttackRequestNode> m_pLastAttackRequest[3];
		qString m_DebugText;

		/* Virtual Functions */

		virtual void Update(f32 delta_sec) = 0;
		virtual void DrawDebugInfo(Render::View* view) = 0;

		/* Functions */

		void AddToFollowerAttackSlotQueue(HasAttackRequestNode* attacker) { SDK_CALL_FUNC(void, 0x3414C0, void*, HasAttackRequestNode*)(this, attacker); }
		bool AttackerIsAvailable(HasAttackRequestNode* attacker) { return SDK_CALL_FUNC(bool, 0x342770, void*, HasAttackRequestNode*)(this, attacker); }
		void ClearAttackSlots() { SDK_CALL_FUNC(void, 0x34EF10, void*)(this); }
		void ClearPreviousBestAttacker(eAttackType attack_type) { SDK_CALL_FUNC(void, 0x34F710, void*, eAttackType)(this, attack_type); }
		int CountNumDistinctAttackers(SimObject* exclude_this_guy) { return SDK_CALL_FUNC(int, 0x350780, void*, SimObject*)(this, exclude_this_guy); }
		HasAttackRequestNode* FindNextAttacker(eAttackType attack_type, AttackSlotInfo& next_attack_baton) {
			return SDK_CALL_FUNC(HasAttackRequestNode*, 0x357720, void*, eAttackType, AttackSlotInfo&)(this, attack_type, next_attack_baton);
		}
		void FinishedAttacking(HasAttackRequestNode* attacker) { SDK_CALL_FUNC(void, 0x3581C0, void*, HasAttackRequestNode*)(this, attacker); }
		bool GetAttackSlotInfo(HasAttackRequestNode* attacker, AttackSlotInfo& attack_slot_info) {
			return SDK_CALL_FUNC(bool, 0x359BC0, void*, HasAttackRequestNode*, AttackSlotInfo&)(this, attacker, attack_slot_info);
		}
		f32 GetAttackerScore(HasAttackRequestNode* attacker, qString* debug_string = 0) {
			return SDK_CALL_FUNC(f32, 0x35AB40, void*, HasAttackRequestNode*, qString*)(this, attacker, debug_string);
		}
		eAttackSlotList GetCorrectAttackSlotList(HasAttackRequestNode* attacker) { return SDK_CALL_FUNC(eAttackSlotList, 0x35B630, void*, HasAttackRequestNode*)(this, attacker); }
		HasAttackRequestNode* GetCurrentAttacker(eAttackType attack_type) { return SDK_CALL_FUNC(HasAttackRequestNode*, 0x35D600, void*, eAttackType)(this, attack_type); }
		void GetDistanceAndAngleAway(HasAttackRequestNode* attacker, f32& distance_away, f32& cosine_of_angle_away) {
			SDK_CALL_FUNC(void, 0x35EC30, void*, HasAttackRequestNode*, f32&, f32&)(this, attacker, distance_away, cosine_of_angle_away);
		}
		HasAttackRequestNode* GetNextAttacker(eAttackType attack_type) { return SDK_CALL_FUNC(HasAttackRequestNode*, 0x360DB0, void*, eAttackType)(this, attack_type); }
		f32 GetTimeUntilInitialAttack(HasAttackRequestNode* attacker) { return SDK_CALL_FUNC(f32, 0x362DB0, void*, HasAttackRequestNode*)(this, attacker); }
		f32 GetTimeUntilNextAttack(HasAttackRequestNode* prev_attacker, HasAttackRequestNode* next_attacker) {
			return SDK_CALL_FUNC(f32, 0x362E60, void*, HasAttackRequestNode*, HasAttackRequestNode*)(this, prev_attacker, next_attacker);
		}
		void InitFromProperties(qPropertySet* property_set) { SDK_CALL_FUNC(void, 0x366D40, void*, qPropertySet*)(this, property_set); }
		void JustPerformedOpportunityAttack(eAttackType attack_type, f32 min_time_until_next_one, f32 max_time_until_next_one) {
			SDK_CALL_FUNC(void, 0x36D220, void*, eAttackType, f32, f32)(this, attack_type, min_time_until_next_one, max_time_until_next_one);
		}
		void MakeAttackRequest(HasAttackRequestNode* attacker, eAttackType attack_type) { SDK_CALL_FUNC(void, 0x36D320, void*, HasAttackRequestNode*, eAttackType)(this, attacker, attack_type); }
		void RemoveAttackSlotGuysFromTheQueue() { SDK_CALL_FUNC(void, 0x381280, void*)(this); }
		void RequestAttackSlot(HasAttackRequestNode* attacker) { SDK_CALL_FUNC(void, 0x382280, void*, HasAttackRequestNode*)(this, attacker); }
		void Reset() { SDK_CALL_FUNC(void, 0x382980, void*)(this); }
		void SetAllowedToUseAttackSlotLists(eAttackType attack_type) { SDK_CALL_FUNC(void, 0x384EC0, void*, eAttackType)(this, attack_type); }
		void SortAttackSlots(eAttackType attack_type) { SDK_CALL_FUNC(void, 0x3883D0, void*, eAttackType)(this, attack_type); }
		void UnregisterUnavailableAttackers() { SDK_CALL_FUNC(void, 0x38AE10, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(AttackRightsComponent, 0x2880);
}