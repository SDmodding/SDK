#pragma once

namespace UFG
{
	//------------------------------------------------------------------------------
	//	Component Enums
	//------------------------------------------------------------------------------

	/* Prop */
	enum
	{
		Prop_UELComponent,
		Prop_SceneObjectProperties,
		Prop_TransformNodeComponent,
		Prop_TSActorComponent,
		Prop_SimObjectPropertiesComponent,
		Prop_PhantomVolumeComponent,
		Prop_ActionTreeComponent,
		Prop_StreamedResourceComponent,
		Prop_BaseAnimationComponent,
		Prop_CompositeDrawableComponent,
		Prop_InterestPoint,
		Prop_InventoryItemComponent,
		Prop_InterestPointUserComponent,
		Prop_PropInteractComponent
	};

	/* CVBase */
	enum
	{
		CVBase_UELComponent,
		CVBase_SceneObjectProperties,
		CVBase_TransformNodeComponent,
		CVBase_SimObjectPropertiesComponent,
		CVBase_TSActorComponent,
		CVBase_AIScriptInterfaceComponent,
		CVBase_HealthComponent,
		CVBase_ActionTreeComponent,
		CVBase_MissionFailConditionComponent,
		CVBase_BaseAnimationComponent,
		CVBase_StreamedResourceComponent,
		CVBase_StimulusReceiverComponent,
		CVBase_InteractableComponent,
		CVBase_AnimationLODComponent,
		CVBase_CompositeDrawableComponent,
		CVBase_HitReactionComponent,
		CVBase_EncounterUnitComponent,
		CVBase_CopUnitComponent,
		CVBase_PhantomVolumeComponent,
		CVBase_AIActionTreeComponent,
		CVBase_TargetingSystemBaseComponent,
		CVBase_CharacterControllerInterface,
		CVBase_AIEntityComponent,
		CVBase_VehicleDriverInterface,
		CVBase_RoadSpaceComponent,
		CVBase_InterestPoint,
		CVBase_SensorComponent,
		CVBase_COUNT
	};

	/* Character */
	enum
	{
		Character_BEGIN = (CVBase_COUNT - 1),
		Character_CharacterPhysicsComponent,
		Character_WorldContextComponent,
		Character_InteractorComponent,
		Character_ActionTreeResourcesComponent,
		Character_FacialActionTreeComponent,
		Character_GetInFormationComponent,
		Character_PedFormationManagerComponent,
		Character_GetInPedFormationComponent,
		Character_HasAttackRequestComponent,
		Character_NavComponent,
		Character_CameraSubject,
		Character_CharacterEffectsComponent,
		Character_InventoryComponent,
		Character_HkAudioEntityComponent,
		Character_DialogueAnimationComponent,
		Character_RagdollComponent,
		Character_InterestPointUserComponent,
		Character_CharacterOccupantComponent,
		Character_FaceActionComponent,
		Character_AttackRightsComponent,
		Character_AimingBaseComponent,
		Character_PedSpawningInfo
	};

	/* Vehicle */
	enum
	{
		VEHICLE_BEGIN = (CVBase_COUNT - 1),
		Vehicle_AIOutlineComponent,
		Vehicle_HkAudioEntityComponent,
		Vehicle_VehiclesBlipComponent,
		Vehicle_VehicleOccupantComponent,
		Vehicle_CameraSubject,
		Vehicle_VehicleEffectsComponent,
		Vehicle_PropInteractComponent,
		Vehicle_PhysicsMoverInterface,
		Vehicle_WaterFloatingTrackerComponent
	};

	//------------------------------------------------------------------------------

	class ComponentTypeEntry
	{
	public:
		u32 uid;
	};

	//------------------------------------------------------------------------------
	//	SimObject (Game)
	//------------------------------------------------------------------------------

	class SimObjectGame : public SimObject
	{
	public:
		u32 mComponentTableEntryCount;
		ComponentTypeEntry* mComponentTableEntries;

		/* Functions */

		// Use this function if you're trying to get component that's outside of the type table ID (look enums above).
		template <typename T = SimComponent>
		T* GetComponentOfTypeHK(u32 type_uid) { return SDK_CALL_FUNC(T*, 0x52BBC0, void*, u32)(this, type_uid); }

		SimComponent* GetComponent(u32 type_uid, u32 index)
		{
			auto component = m_Components.p[index].m_pComponent;
			if (!component || ((component->m_TypeUID ^ type_uid) & 0xFE000000) || (type_uid & ~component->m_TypeUID & ~0xFE000000)) {
				return nullptr;
			}

			return component;
		}

		template <typename T, u32 index>
		SDK_INLINE T* GetComponent() { return reinterpret_cast<T*>(GetComponent(T::_TypeUID, index)); }
	};
	SDK_ASSERT_SIZEOF(SimObjectGame, 0x90);

	//------------------------------------------------------------------------------
	//	SimObject (Prop)
	//------------------------------------------------------------------------------

	class SimObjectProp : public SimObjectGame
	{
	public:
		SDK_INLINE UELComponent* GetUEL() {
			return GetComponent<UELComponent, Prop_UELComponent>();
		}

		SDK_INLINE SimObjectPropertiesComponent* GetSimObjectProperties() {
			return GetComponent<SimObjectPropertiesComponent, Prop_SimObjectPropertiesComponent>();
		}

		SDK_INLINE TSActorComponent* GetTSActor() {
			return GetComponent<TSActorComponent, Prop_TSActorComponent>();
		}

		SDK_INLINE PhantomVolumeComponent* GetPhantomVolume() {
			return GetComponent<PhantomVolumeComponent, Prop_PhantomVolumeComponent>();
		}

		SDK_INLINE ActionTreeComponent* GetActionTree() {
			return GetComponent<ActionTreeComponent, Prop_ActionTreeComponent>();
		}

		SDK_INLINE StreamedResourceComponent* GetStreamedResource() {
			return GetComponent<StreamedResourceComponent, Prop_StreamedResourceComponent>();
		}

		SDK_INLINE BaseAnimationComponent* GetBaseAnimation() {
			return GetComponent<BaseAnimationComponent, Prop_BaseAnimationComponent>();
		}

		SDK_INLINE CompositeDrawableComponent* GetCompositeDrawable() {
			return GetComponent<CompositeDrawableComponent, Prop_CompositeDrawableComponent>();
		}

		SDK_INLINE InventoryItemComponent* GetInventory() {
			return GetComponent<InventoryItemComponent, Prop_InventoryItemComponent>();
		}
	};

	//------------------------------------------------------------------------------
	//	SimObject (CVBase)
	//------------------------------------------------------------------------------

	class SimObjectCVBase : public SimObjectGame
	{
	public:
		SDK_INLINE UELComponent* GetUEL() {
			return GetComponent<UELComponent, CVBase_UELComponent>();
		}

		SDK_INLINE SimObjectPropertiesComponent* GetSimObjectProperties() {
			return GetComponent<SimObjectPropertiesComponent, CVBase_SimObjectPropertiesComponent>();
		}

		SDK_INLINE TSActorComponent* GetTSActor() {
			return GetComponent<TSActorComponent, CVBase_TSActorComponent>();
		}

		SDK_INLINE AIScriptInterfaceComponent* GetAIScriptInterface() {
			return GetComponent<AIScriptInterfaceComponent, CVBase_AIScriptInterfaceComponent>();
		}

		SDK_INLINE HealthComponent* GetHealth() {
			return GetComponent<HealthComponent, CVBase_HealthComponent>();
		}

		SDK_INLINE ActionTreeComponent* GetActionTree() {
			return GetComponent<ActionTreeComponent, CVBase_ActionTreeComponent>();
		}

		SDK_INLINE MissionFailConditionComponent* GetMissionFailCondition() {
			return GetComponent<MissionFailConditionComponent, CVBase_MissionFailConditionComponent>();
		}

		SDK_INLINE BaseAnimationComponent* GetBaseAnimation() {
			return GetComponent<BaseAnimationComponent, CVBase_BaseAnimationComponent>();
		}

		SDK_INLINE StreamedResourceComponent* GetStreamedResource() {
			return GetComponent<StreamedResourceComponent, CVBase_StreamedResourceComponent>();
		}

		SDK_INLINE StimulusReceiverComponent* GetStimulusReceiver() {
			return GetComponent<StimulusReceiverComponent, CVBase_StimulusReceiverComponent>();
		}

		SDK_INLINE InteractableComponent* GetInteractable() {
			return GetComponent<InteractableComponent, CVBase_InteractableComponent>();
		}

		SDK_INLINE AnimationLODComponent* GetAnimationLOD() {
			return GetComponent<AnimationLODComponent, CVBase_AnimationLODComponent>();
		}

		SDK_INLINE CompositeDrawableComponent* GetCompositeDrawable() {
			return GetComponent<CompositeDrawableComponent, CVBase_CompositeDrawableComponent>();
		}

		SDK_INLINE HitReactionComponent* GetHitReaction() {
			return GetComponent<HitReactionComponent, CVBase_HitReactionComponent>();
		}

		SDK_INLINE EncounterUnitComponent* GetEncounterUnit() {
			return GetComponent<EncounterUnitComponent, CVBase_EncounterUnitComponent>();
		}

		SDK_INLINE CopUnitComponent* GetCopUnit() {
			return GetComponent<CopUnitComponent, CVBase_CopUnitComponent>();
		}

		SDK_INLINE PhantomVolumeComponent* GetPhantomVolume() {
			return GetComponent<PhantomVolumeComponent, CVBase_PhantomVolumeComponent>();
		}

		SDK_INLINE AIActionTreeComponent* GetAIActionTree() {
			return GetComponent<AIActionTreeComponent, CVBase_AIActionTreeComponent>();
		}

		SDK_INLINE TargetingSystemBaseComponent* GetTargetingSystemBase() {
			return GetComponent<TargetingSystemBaseComponent, CVBase_TargetingSystemBaseComponent>();
		}

		SDK_INLINE CharacterControllerInterface* GetCharacterControllerInterface() {
			return GetComponent<CharacterControllerInterface, CVBase_CharacterControllerInterface>();
		}

		SDK_INLINE AIEntityComponent* GetAIEntity() {
			return GetComponent<AIEntityComponent, CVBase_AIEntityComponent>();
		}

		SDK_INLINE VehicleDriverInterface* GetDriverInterface() {
			return GetComponent<VehicleDriverInterface, CVBase_VehicleDriverInterface>();
		}

		SDK_INLINE AiDriverComponent* GetAiDriver() { 
			return GetComponent<AiDriverComponent, CVBase_VehicleDriverInterface>(); 
		}

		SDK_INLINE RoadSpaceComponent* GetRoadSpace() {
			return GetComponent<RoadSpaceComponent, CVBase_RoadSpaceComponent>();
		}
	};

	//------------------------------------------------------------------------------
	//	SimObject (Character)
	//------------------------------------------------------------------------------

	class SimObjectCharacter : public SimObjectCVBase
	{
	public:
		SDK_INLINE CharacterPhysicsComponent* GetCharacterPhysics() {
			return GetComponent<CharacterPhysicsComponent, Character_CharacterPhysicsComponent>();
		}

		SDK_INLINE WorldContextComponent* GetWorldContext() {
			return GetComponent<WorldContextComponent, Character_WorldContextComponent>();
		}

		SDK_INLINE InteractorComponent* GetInteractor() {
			return GetComponent<InteractorComponent, Character_InteractorComponent>();
		}

		SDK_INLINE FacialActionTreeComponent* GetFacialActionTree() {
			return GetComponent<FacialActionTreeComponent, Character_FacialActionTreeComponent>();
		}

		SDK_INLINE CharacterSubjectComponent* GetCharacterSubject() {
			return GetComponent<CharacterSubjectComponent, Character_CameraSubject>();
		}

		SDK_INLINE InventoryComponent* GetInventory() {
			return GetComponent<InventoryComponent, Character_InventoryComponent>();
		}

		SDK_INLINE HkAudioEntityComponent* GetHkAudioEntity() {
			return GetComponent<HkAudioEntityComponent, Character_HkAudioEntityComponent>();
		}

		SDK_INLINE ActorAudioComponent* GetActorAudio() {
			return GetComponent<ActorAudioComponent, Character_HkAudioEntityComponent>();
		}

		SDK_INLINE CharacterOccupantComponent* GetCharacterOccupant() { 
			return GetComponent<CharacterOccupantComponent, Character_CharacterOccupantComponent>();
		}

		SDK_INLINE AttackRightsComponent* GetAttackRights() {
			return GetComponent<AttackRightsComponent, Character_AttackRightsComponent>();
		}

		SDK_INLINE AimingBaseComponent* GetAimingBase() {
			return GetComponent<AimingBaseComponent, Character_AimingBaseComponent>();
		}

		SDK_INLINE AimingNPCComponent* GetAimingNPC() {
			return GetComponent<AimingNPCComponent, Character_AimingBaseComponent>();
		}

		SDK_INLINE AimingPlayerComponent* GetAimingPlayer() {
			return GetComponent<AimingPlayerComponent, Character_AimingBaseComponent>();
		}

		SDK_INLINE PedSpawningInfo* GetPedSpawningInfo() {
			return GetComponent<PedSpawningInfo, Character_PedSpawningInfo>();
		}
	};

	//------------------------------------------------------------------------------
	//	SimObject (Vehicle)
	//------------------------------------------------------------------------------

	class SimObjectVehicle : public SimObjectCVBase
	{
	public:
		SDK_INLINE VehicleOccupantComponent* GetVehicleOccupant() { 
			return GetComponent<VehicleOccupantComponent, Vehicle_VehicleOccupantComponent>();
		}

		SDK_INLINE PhysicsMoverInterface* GetPhysicsMoverInterface() {
			return GetComponent<PhysicsMoverInterface, Vehicle_PhysicsMoverInterface>();
		}
	};
}