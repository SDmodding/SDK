#pragma once

namespace UFG
{
	class BaseAnimationComponent : public SimComponent, public qNode<BaseAnimationComponent>
	{
	public:
		enum { _TypeUID = 0xC6000001 };

		RigHandle mRigHandle;
		RigInstance* mRigInstance;
		Creature* mCreature;
		bool mUpdatedWithResources;
		bool mUpdatedFromNIS;
		bool mTransformsUpdated;
		AnimationGroupHandleContainer mRequiredAnimationBanks;
		bool mDestroyAttachedCharacters;
		bool mTemporaryRig;
		u32 mCurrentRigUID;

		/* Functions */

		bool AreResourcesAvailable() { return SDK_CALL_FUNC(bool, 0x57F310, void*)(this); }
		void InitPropertySetInfo(SceneObjectProperties* pSceneObj, component_BaseAnimation* dataPtr) { 
			SDK_CALL_FUNC(void, 0x583870, void*, SceneObjectProperties*, component_BaseAnimation*)(this, pSceneObj, dataPtr); 
		}
		AnimationNode* PlayAnimation(const qSymbolUC& animName, f32 startTime) { return SDK_CALL_FUNC(AnimationNode*, 0x588630, void*, const qSymbolUC&, f32)(this, animName, startTime); }
		void RebindRequiredAnimationBanks() { SDK_CALL_FUNC(void, 0x58AF10, void*)(this); }
		void RebindResources() { SDK_CALL_FUNC(void, 0x58AF60, void*)(this); }
		void Reset() { SDK_CALL_FUNC(void, 0x58B220, void*)(this); }
		void SetAnimationBankPriority(const qSymbolUC& theAnimationGroupSymbol, eAnimationPriorityEnum eAnimationPriority) {
			SDK_CALL_FUNC(void, 0x58B790, void*, const qSymbolUC&, eAnimationPriorityEnum)(this, theAnimationGroupSymbol, eAnimationPriority);
		}
		void UnbindRequiredAnimationBanks() { SDK_CALL_FUNC(void, 0x58D300, void*)(this); }
		void bindRequiredAnimBanks(SceneObjectProperties* pSceneObj, component_BaseAnimation* dataPtr) { 
			SDK_CALL_FUNC(void, 0x591CA0, void*, SceneObjectProperties*, component_BaseAnimation*)(this, pSceneObj, dataPtr); 
		}
		void checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature() { SDK_CALL_FUNC(void, 0x591D70, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(BaseAnimationComponent, 0xC8);
}