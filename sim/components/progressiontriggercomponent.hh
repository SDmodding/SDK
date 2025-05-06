#pragma once

namespace UFG
{
	class ProgressionTriggerComponent : public SimComponent, public qNode<ProgressionTriggerComponent>, qNode<ProgressionTriggerComponent, struct UpdateList>
	{
	public:
		enum { _TypeUID = 0xB0000001 };

		SceneObjectProperties* mpRegionSceneObjects[5];
		TriggerRegion* mpTriggerRegions[5];
		GameSlice* mpGameSlice;
		u64 mCallTimeout;
		u64 mCallFailTimeout;
		bool mInsideActiveRegion;
		bool mEnabled;
		bool mRequiresExitToActivate;
		bool mWaitMenuActive;
		bool mRequiresTODWait;
		bool mRegionsCreated;

		/* Static Functions */

		SDK_SINLINE ProgressionTriggerComponent* PropertiesOnActivate(SceneObjectProperties* pSceneObj) {
			return SDK_CALL_FUNC(ProgressionTriggerComponent*, 0x5453B0, SceneObjectProperties*)(pSceneObj);
		}

		SDK_SINLINE void UpdateAll(f32 deltaTime) { SDK_CALL_FUNC(void, 0x55E330, f32)(deltaTime); }

		/* Virtual Functions */

		virtual void Update(f32 deltaTime) = 0;

		/* Functions */

		void ActiveateOnlyAfterExitFromRegion(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x5207E0, GameSlice*)(pGameSlice); }
		void CreateRegions(TransformNodeComponent* pTransformNode) { SDK_CALL_FUNC(void, 0x5249F0, void*, TransformNodeComponent*)(this, pTransformNode); }
		void Disable(bool turnLayerOn) { SDK_CALL_FUNC(void, 0x526030, void*, bool)(this, turnLayerOn); }
		void DisablePDATrigger(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x526530, GameSlice*)(pGameSlice); }
		void DisableTrigger(GameSlice* pGameSlice, bool turnLayerOn) { SDK_CALL_FUNC(void, 0x5265C0, GameSlice*, bool)(pGameSlice, turnLayerOn); }
		void Enable(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x526790, void*, GameSlice*)(this, pGameSlice); }
		void EnableObjective() { SDK_CALL_FUNC(void, 0x526D50, void*)(this); }
		void EnableTrigger(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x526E60, GameSlice*)(pGameSlice); }
		void ForceOnEnter() { SDK_CALL_FUNC(void, 0x52A2F0, void*)(this); }
		ProgressionTriggerComponent* GetComponent(GameSlice* pGameSlice) { return SDK_CALL_FUNC(ProgressionTriggerComponent*, 0x52B990, GameSlice*)(pGameSlice); }
		void HandleSpawnPointSpawn(bool enable) { SDK_CALL_FUNC(void, 0x534B30, void*, bool)(this, enable); }
		bool IsRestoring(GameSlice* pGameSlice) { return SDK_CALL_FUNC(bool, 0x53C060, GameSlice*)(pGameSlice); }
		void OnActivate(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x53CD20, GameSlice*)(pGameSlice); }
		void OnActivate() { SDK_CALL_FUNC(void, 0x53CBC0, void*)(this); }
		void OnEnterTrigger(TriggerRegion* pTriggerRegion) { SDK_CALL_FUNC(void, 0x5413D0, void*, TriggerRegion*)(this, pTriggerRegion); }
		void OnExitTrigger(TriggerRegion* pTriggerRegion) { SDK_CALL_FUNC(void, 0x541D00, void*, TriggerRegion*)(this, pTriggerRegion); }
		void UnloadScripts() { SDK_CALL_FUNC(void, 0x558650, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(ProgressionTriggerComponent, 0xD0);
}