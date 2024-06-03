//=============================================================================
// 
// Description:		Everything related to Simulation ie. SimObject, 
//					SimComponent, etc...
// 
//=============================================================================
#pragma once

namespace UFG
{
	class CSimObject;
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
	class CSimulation
	{
	public:
		qTreeRB mSimObjects;
		qTreeRB mSimObjectsToBeDeleted;
		qTreeRB mSimObjectsToBeDeletedRecursively;
		qSafePointer<CSimObject> mpLocalPlayer;
		qArray<CSimObject> m_aCurrentDestructingObjects;

		static UFG_INLINE CSimulation* Instance()
		{
			return reinterpret_cast<CSimulation*>(UFG_RVA(0x235C3A0));
		}

		UFG_INLINE qSymbol GenerateUniqueName(const char* p_Root)
		{
			qSymbol m_Symbol;
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, const char*)>(UFG_RVA(0x190A50))(this, &m_Symbol, p_Root);
			return m_Symbol;
		}

		UFG_INLINE CSimObject* GetSimObject(qSymbol p_ObjectNameUID)
		{
			return reinterpret_cast<CSimObject * (__fastcall*)(void*, qSymbol)>(UFG_RVA(0x190C40))(this, p_ObjectNameUID);
		}

		CSimObject* GetSimObjectHead()
		{
			qBaseNodeRB* m_Node = mSimObjects.GetHead();
			if (!m_Node)
				return nullptr;

			return m_Node->GetPointer<CSimObject, offsetof(CSimObject, m_Node)>();
		}

		CSimObject* GetSimObjectNext(CSimObject* p_SimObject)
		{
			qBaseNodeRB* m_NextNode = mSimObjects.GetNext(&p_SimObject->m_Node);
			if (!m_NextNode || m_NextNode == reinterpret_cast<qBaseNodeRB*>(this))
				return nullptr;

			return m_NextNode->GetPointer<CSimObject, offsetof(CSimObject, m_Node)>();
		}
	};
}