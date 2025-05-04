#pragma once

namespace UFG
{
	class HasAttackRequestNode : public qSafePointerNode<HasAttackRequestNode>, public qNode<HasAttackRequestNode>, public qNode<HasAttackRequestNode, struct AttackRightsList>, public qNode<HasAttackRequestNode, struct FollowerAttackRightsList>
	{
	public:
		eAttackType m_AttackType;
		eAttackerType m_AttackerType;
		eTargetTypeEnum m_TargetType;
		eInCoverType m_InCoverType;
		eTargetTypeEnum m_CopySecondaryCharacterToTargetType;
		f32 m_LastTimePolled;
		u32 m_LastFramePolled;
		bool m_CurrentlyAttacking;
		f32 m_TimeFinishedAttacking;
		f32 m_Score;
		ActionContext* m_pActionContextCopy;
		qSafePointer<CanAttackConditionGroup> m_pCanAttackConditions;
		qSafePointer<SimComponent, AttackRightsComponent> m_pAttackeeRequest;
		qSafePointer<HasAttackRequestNode> m_pSecondaryCharacterRequest;
		f32 m_AttackeeRequestTime;
		qSafePointer<SimComponent, HasAttackRequestComponent> m_pOwner;
		const char* m_Registrator;

		/* Functions */

		void ClearAttackRequest() { SDK_CALL_FUNC(void, 0x34EEB0, void*)(this); }
		void FinishedAttacking() { SDK_CALL_FUNC(void, 0x3582C0, void*)(this); }
		AttackRightsComponent* GetAttackTarget() { return SDK_CALL_FUNC(AttackRightsComponent*, 0x359D80, void*)(this); }
		SimObject* GetSimObject() { return SDK_CALL_FUNC(SimObject*, 0x362600, void*)(this); }

		void ReInit(ActionContext* action_context, HasAttackRequestCondition* has_attack_request_condition) {
			SDK_CALL_FUNC(void, 0x37F5A0, void*, ActionContext*, HasAttackRequestCondition*)(this, action_context, has_attack_request_condition);
		}

		void RequestAttack(AttackRightsComponent* attackee, HasAttackRequestNode* secondary_character) {
			SDK_CALL_FUNC(void, 0x3821A0, void*, AttackRightsComponent*, HasAttackRequestNode*)(this, attackee, secondary_character);
		}
	};

	class HasAttackRequestComponent : public SimComponent, public qNode<HasAttackRequestComponent>
	{
	public:
		enum { _TypeUID = 0x60000001 };

		qList<HasAttackRequestNode> m_NodeList;
		qList<AttackRightsScoreBonusTask> m_AttackRightsScoreBonusTaskList;
		f32 m_AttackCanceledUntilTime[3];
		RebindingComponentHandle<TargetingSystemBaseComponent> m_pTargetingSystemBaseComponent;
		RebindingComponentHandle<AIScriptInterfaceComponent> m_pAIScriptInterfaceComponent;
		RebindingComponentHandle<TransformNodeComponent> m_pTransformNodeComponent;
		RebindingComponentHandle<HealthComponent> m_pHealthComponent;
		RebindingComponentHandle<ActionTreeComponent> m_pActionTreeComponent;
		u32 m_DebugStringTimestamp;

		/* Static Functions */

		SDK_SINLINE HasAttackRequestComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(HasAttackRequestComponent*, 0x37EFF0, SceneObjectProperties*, bool)(pSceneObj, required);
		}

		/* Functions */

		void DrawDebugString(Render::View* view) { SDK_CALL_FUNC(void, 0x354650, void*, Render::View*)(this, view); }

		HasAttackRequestNode* MakeNewNode(ActionContext* action_context, HasAttackRequestCondition* has_attack_request_condition) {
			return SDK_CALL_FUNC(HasAttackRequestNode*, 0x36D860, void*, ActionContext*, HasAttackRequestCondition*)(this, action_context, has_attack_request_condition);
		}

		void Reset() { SDK_CALL_FUNC(void, 0x382BE0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(HasAttackRequestComponent, 0x178);
}