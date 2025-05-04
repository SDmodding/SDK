#pragma once

namespace UFG
{
	class GetInPedFormationComponent : public SimComponent, public qNode<GetInPedFormationComponent>
	{
	public:
		enum { _TypeUID = 0x5E000001 };

		qList<GetInPedFormationNode> m_NodeList;
		RebindingComponentHandle<ActiveAIEntityComponent> m_pAIEntityComponent;
		RebindingComponentHandle<ActionTreeComponent> m_pActionTreeComponent;
		RebindingComponentHandle<HealthComponent> m_pHealthComponent;

		/* Static Functions */

		SDK_SINLINE GetInPedFormationComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(GetInPedFormationComponent*, 0x37EF10, SceneObjectProperties*, bool)(pSceneObj, required);
		}

		/* Functions */

		GetInPedFormationNode* MakeNewNode() { return SDK_CALL_FUNC(GetInPedFormationNode*, 0x36D7E0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(GetInPedFormationComponent, 0xF0);
}