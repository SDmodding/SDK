#pragma once

namespace UFG
{
	class CopUnitComponent : public SimComponent, public UpdateInterface, public qNode<CopUnitComponent>
	{
	public:
		enum { _TypeUID = 0x8C000001 };

		RebindingComponentHandle<TSActorComponent> mpTSActorComponent;
		RebindingComponentHandle<VehicleAudioComponent> mpVehicleAudioComponent;
		RebindingComponentHandle<VehicleEffectsComponent> mpVehicleRenderComponent;
		RebindingComponentHandle<HealthComponent> mpHealthComponent;
		RebindingComponentHandle<PhysicsMoverInterface> mpMoverComponent;
		RebindingComponentHandle<TransformNodeComponent> mpTransformNodeComponent;
		RebindingComponentHandle<ActiveAIEntityComponent> mpAIEntityComponent;
		RebindingComponentHandle<EncounterUnitComponent> mpEncounterUnitComponent;
		f32 mAutoKillTimer;
		EncounterUnit::UnitType mUnitType;
		bool mIsManaged : 1;
		bool mIsUsableByCopSystem : 1;
		bool mIsAutoKill : 1;
		bool mIsAlive : 1;
		bool mIsVisible : 1;
		bool mIsBlipOn : 1;
		bool mIsOnFoot : 1;
		bool mIsPatrolling : 1;
		bool mIsReducedRadius : 1;
		bool mIsAudioOn : 1;
		bool mScriptedLightsOn : 1;
		bool mDummy : 4;

		/* Static Functions */

		SDK_SINLINE CopUnitComponent* PropertiesOnActivate(SceneObjectProperties* pSceneObj) { return SDK_CALL_FUNC(CopUnitComponent*, 0x544E60, SceneObjectProperties*)(pSceneObj); }

		/* Functions */

		void DisableHandler() { SDK_CALL_FUNC(void, 0x526190, void*)(this); }
		void SetScriptedLightsOn(bool bEnabled) { SDK_CALL_FUNC(void, 0x54E620, void*, bool)(this, bEnabled); }
		void TurnOff() { SDK_CALL_FUNC(void, 0x557160, void*)(this); }
		void TurnOn() { SDK_CALL_FUNC(void, 0x5571E0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(CopUnitComponent, 0x1E8);
}