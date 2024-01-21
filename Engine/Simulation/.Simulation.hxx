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

#include "SceneObjectProperties.hxx"

//=============================================================================
// SimComponent Classes

// Main
#include "SimComponent.hxx"

// Important...
#include "Components/SimObjectPropertiesComponent.hxx"
#include "Components/SimVehiclePropertiesComponent.hxx"
#include "Components/SimWeaponPropertiesComponent.hxx"

// Others...
#include "Components/ActionTreeComponent.hxx"
#include "Components/VehicleOccupantComponent.hxx"
#include "Components/CharacterOccupantComponent.hxx"
#include "Components/FaceMeterComponent.hxx"
#include "Components/GunComponent.hxx"
#include "Components/HitReactionComponent.hxx"
#include "Components/InventoryItemComponent.hxx"
#include "Components/PhysicsMoverInterface.hxx"
#include "Components/StreamedResourceComponent.hxx"
#include "Components/TargetingSystemComponents.hxx"
#include "Components/.Components.hxx" // TODO: Move them to individual file instead having them in one big file mess...

//=============================================================================
// SimObject Classes

#include "SimObject.hxx"
#include "SimVehicle.hxx"
#include "SimWeapon.hxx"
#include "SimCharacter.hxx"

//=============================================================================
// Camera Components

#include "Components/Camera/BaseCameraComponent.hxx"
#include "Components/Camera/GameCameraComponent.hxx"
#include "Components/Camera/AnimatedCameraComponent.hxx"
#include "Components/Camera/FollowCameraComponent.hxx"
#include "Components/Camera/ChaseCameraComponent.hxx"
#include "Components/Camera/ScriptCameraComponent.hxx"

//=============================================================================
// Utils

#include "SimObjectUtility.hxx"
#include "SimVehicleUtility.hxx"
#include "SpawnInfoInterface.hxx"

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