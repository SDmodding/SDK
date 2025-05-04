#pragma once

namespace UFG
{
	enum eFormationRangePreference
	{
		eRANGE_PREFERENCE_NONE,
		eRANGE_PREFERENCE_INNERMOST,
		eRANGE_PREFERENCE_SECOND_OUTERMOST,
		eRANGE_PREFERENCE_OUTERMOST,
		eRANGE_PREFERENCE_CLOSEST,
		NUM_FORMATION_RANGE_PREFERENCES
	};

	class GetInFormationNode : public qSafePointerNode<GetInFormationNode>, public qNode<GetInFormationNode>
	{
	public:
		int m_RangeIndex;
		int m_SlotIndex;
		eFormationRangePreference m_RangePreference;
		eAttackType m_AttackType;
		eTargetTypeEnum m_TargetType;
		bool m_PrevIsAtRangePreference;
		bool m_JustGotToRangePreference;
		bool m_AllowedToSwitchToRangePreference;
		qSafePointer<SimComponent, FormationManagerComponent> m_pTargetFormationManagerComponent;
		qSafePointer<SimComponent, GetInFormationComponent> m_pOwner;
		const char* m_Registrator;

		/* Functions */

		bool IsAtRangePreference() { return SDK_CALL_FUNC(char, 0x369F20, void*)(this); }

		void ReInit(eFormationRangePreference range_preference, eAttackType attack_type, eTargetTypeEnum target_type) {
			SDK_CALL_FUNC(void, 0x37F530, void*, eFormationRangePreference, eAttackType, eTargetTypeEnum)(this, range_preference, attack_type, target_type);
		}

		void SetTargetFormationManagerComponent(FormationManagerComponent* target_formation_manager_component) {
			SDK_CALL_FUNC(void, 0x387D10, void*, FormationManagerComponent*)(this, target_formation_manager_component);
		}

		void UnregisterFromFormationManager() { SDK_CALL_FUNC(void, 0x38A900, void*)(this); }
	};

	class GetInFormationComponent : public SimComponent, public qNode<GetInFormationComponent>
	{
	public:
		enum { _TypeUID = 0x5C000001 };

		qList<GetInFormationNode> m_NodeList;
		bool m_LockPositionToCurrentPosition;
		RebindingComponentHandle<ActiveAIEntityComponent> m_pAIEntityComponent;
		RebindingComponentHandle<SimObjectCharacterPropertiesComponent> m_pSimObjectCharacterPropertiesComponent;

		/* Static Functions */

		SDK_SINLINE GetInFormationComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(GetInFormationComponent*, 0x37EE30, SceneObjectProperties*, bool)(pSceneObj, required);
		}

		/* Functions */

		GetInFormationNode* MakeNewNode(eFormationRangePreference range_preference, eAttackType attack_type, eTargetTypeEnum target_type) {
			return SDK_CALL_FUNC(GetInFormationNode*, 0x36D730, void*, eFormationRangePreference, eAttackType, eTargetTypeEnum)(this, range_preference, attack_type, target_type);
		}
	};
	SDK_ASSERT_SIZEOF(GetInFormationComponent, 0xC8);
}