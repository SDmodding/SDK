#pragma once

namespace UFG
{
	class ActionTreeResourcesComponent : public SimComponent, public qNode<ActionTreeResourcesComponent>, public qNode<ActionTreeResourcesComponent, struct ActionTreeResourcesComponent_UpdateList>
	{
	public:
		enum { _TypeUID = 0x42000001 };

		class AnimationBankRequest : public PowerManagedResource, public qNode<AnimationBankRequest>
		{
		public:
			AnimationGroupHandle mAnimationGroupHandle;
			ActionPath mActionPath;
			ActionNode* mOwnerNode;
			bool mKeepAlive;
		};

		qList<AnimationBankRequest> mAnimationBankRequests;
		qSafePointer<SimComponent, ActionTreeComponent> m_pActionTreeComponent;

		/* Static Functions */

		SDK_SINLINE ActionTreeResourcesComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(ActionTreeResourcesComponent*, 0x297430, SceneObjectProperties*, bool)(pSceneObj, required);
		}

		/* Functions */

		AnimationBankRequest* FindRequest(const ActionPath& actionPath, const qSymbolUC& symAnimBank) {
			return SDK_CALL_FUNC(AnimationBankRequest*, 0x297160, void*, const ActionPath&, const qSymbolUC&)(this, actionPath, symAnimBank);
		}

		bool RequestAnimationBank(const ActionPath& actionPath, ActionNode* ownerNode, bool doTheRequest, const qSymbolUC& symAnimBank, eAnimationPriorityEnum priority) {
			return SDK_CALL_FUNC(bool, 0x297650, void*, const ActionPath&, ActionNode*, bool, const qSymbolUC&, eAnimationPriorityEnum)(this, actionPath, ownerNode, doTheRequest, symAnimBank, priority);
		}

		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x297DA0, void*, f32)(this, delta_sec); }
	};
	SDK_ASSERT_SIZEOF(ActionTreeResourcesComponent, 0x88);
}