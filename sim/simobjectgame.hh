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
		T* GetComponentOfTypeHK(u32 type_uid) { return reinterpret_cast<T*(SDK_CALL*)(void*, u32)>(SDK_RVA(0x52BBC0))(this, type_uid); }

		template <typename T, u32 index>
		SDK_INLINE T* GetComponent()
		{
			auto component = m_Components.p[index].m_pComponent;
			if (!component || ((T::_TypeUID ^ component->m_TypeUID) & 0xFE000000) || (component->m_TypeUID & ~T::_TypeUID & ~0xFE000000)) {
				return nullptr;
			}

			return reinterpret_cast<T*>(component);
		}
	};
	SDK_ASSERT_SIZEOF(SimObjectGame, 0x90);

	//------------------------------------------------------------------------------
	//	SimObject (Prop)
	//------------------------------------------------------------------------------

	class SimObjectProp : public SimObjectGame
	{
	public:
	};

	//------------------------------------------------------------------------------
	//	SimObject (CVBase)
	//------------------------------------------------------------------------------

	class SimObjectCVBase : public SimObjectGame
	{
	public:
	};

	//------------------------------------------------------------------------------
	//	SimObject (Character)
	//------------------------------------------------------------------------------

	class SimObjectCharacter : public SimObjectCVBase
	{
	public:
		SDK_INLINE CharacterOccupantComponent* GetCharacterOccupant() {
			return GetComponent<CharacterOccupantComponent, Character_CharacterOccupantComponent>();
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
	};
}