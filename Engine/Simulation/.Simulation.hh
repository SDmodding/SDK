//=============================================================================
// 
// Description:		Everything related to Simulation ie. SimObject, 
//					SimComponent, etc...
// 
//=============================================================================
#pragma once

namespace UFG
{
	class SimObject;
}

#include "SceneObjectProperties.hh"
#include "Components/.TypeUID.hh"

//=============================================================================
// SimComponent Classes

// Main
#include "SimComponent.hh"

// Interface
#include "Components/Interface/.Interface.hh"
#include "Components/Interface/VehicleDriverInterface.hh"

// Important...
#include "Components/SimObjectPropertiesComponent.hh"
#include "Components/SimVehiclePropertiesComponent.hh"
#include "Components/SimWeaponPropertiesComponent.hh"

// Others...
#include "Components/ActionTreeComponent.hh"
#include "Components/VehicleOccupantComponent.hh"
#include "Components/VehicleEffectsComponent.hh"
#include "Components/CharacterOccupantComponent.hh"
#include "Components/FaceMeterComponent.hh"
#include "Components/GunComponent.hh"
#include "Components/HitReactionComponent.hh"
#include "Components/HumanDriverComponent.hh"
#include "Components/InventoryItemComponent.hh"
#include "Components/PhysicsMoverInterface.hh"
#include "Components/StreamedResourceComponent.hh"
#include "Components/TargetingSystemComponents.hh"
#include "Components/.Components.hh" // TODO: Move them to individual file instead having them in one big file mess...

//=============================================================================
// SimObject Classes

#include "SimObject.hh"
#include "SimVehicle.hh"
#include "SimWeapon.hh"
#include "SimCharacter.hh"

//=============================================================================
// Camera Components

#include "Components/Camera/BaseCameraComponent.hh"
#include "Components/Camera/GameCameraComponent.hh"
#include "Components/Camera/AnimatedCameraComponent.hh"
#include "Components/Camera/FollowCameraComponent.hh"
#include "Components/Camera/ChaseCameraComponent.hh"
#include "Components/Camera/ScriptCameraComponent.hh"

//=============================================================================
// Utils

#include "SimObjectUtility.hh"
#include "SimVehicleUtility.hh"
#include "SpawnInfoInterface.hh"

namespace UFG
{
	class Simulation
	{
	public:
		qTreeRB mSimObjects;
		qTreeRB mSimObjectsToBeDeleted;
		qTreeRB mSimObjectsToBeDeletedRecursively;
		qSafePointer<SimObject> mpLocalPlayer;
		qArray<SimObject> m_aCurrentDestructingObjects;

		UFG_STATIC_INLINE Simulation* Instance()
		{
			return reinterpret_cast<Simulation*>(UFG_RVA(0x235C3A0));
		}

		UFG_INLINE qSymbol GenerateUniqueName(const char* p_Root)
		{
			qSymbol symbol;
			return *reinterpret_cast<qSymbol*(__fastcall*)(void*, qSymbol*, const char*)>(UFG_RVA(0x190A50))(this, &symbol, p_Root);
		}

		UFG_INLINE SimObject* GetSimObject(qSymbol p_ObjectNameUID)
		{
			return reinterpret_cast<SimObject*(__fastcall*)(void*, qSymbol)>(UFG_RVA(0x190C40))(this, p_ObjectNameUID);
		}

		UFG_INLINE SimObject* GetSimObjectHead()
		{
			auto pNode = mSimObjects.GetHead();
			if (!pNode) {
				return nullptr;
			}

			return pNode->GetPointer<SimObject, offsetof(SimObject, m_Node)>();
		}

		UFG_INLINE SimObject* GetSimObjectNext(SimObject* p_SimObject)
		{
			auto pNextNode = mSimObjects.GetNext(&p_SimObject->m_Node);
			if (!pNextNode || pNextNode == reinterpret_cast<qBaseNodeRB*>(this)) {
				return nullptr;
			}

			return pNextNode->GetPointer<SimObject, offsetof(SimObject, m_Node)>();
		}
	}; typedef Simulation CSimulation;
}