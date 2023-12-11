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

// SimComponent Classes
#include "SimComponent.hxx"
#include "Components/.Components.hxx" // TODO: Move them to individual file instead having them in one big file mess...

// SimObject Classes
#include "SimObject.hxx"
#include "SimVehicle.hxx"
#include "SimWeapon.hxx"
#include "SimCharacter.hxx"

// Utils
#include "SimObjectUtility.hxx"
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

		__inline static CSimulation* Instance() {
			return reinterpret_cast<CSimulation*>(UFG_RVA(0x235C3A0));
		}

		__inline qSymbol GenerateUniqueName(const char* p_Root)
		{
			qSymbol m_Symbol;
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, const char*)>(UFG_RVA(0x190A50))(this, &m_Symbol, p_Root);
			return m_Symbol;
		}

		__inline CSimObject* GetSimObject(qSymbol p_ObjectNameUID)
		{
			return reinterpret_cast<CSimObject * (__fastcall*)(void*, qSymbol)>(UFG_RVA(0x190C40))(this, p_ObjectNameUID);
		}

		__inline CSimObject* GetSimObjectHead()
		{
			qBaseNodeRB* m_Node = mSimObjects.GetHead();
			if (!m_Node)
				return nullptr;

			return m_Node->GetPointer<CSimObject, offsetof(CSimObject, m_Node)>();
		}

		__inline CSimObject* GetSimObjectNext(CSimObject* p_SimObject)
		{
			qBaseNodeRB* m_NextNode = mSimObjects.GetNext(&p_SimObject->m_Node);
			if (!m_NextNode || m_NextNode == reinterpret_cast<qBaseNodeRB*>(this))
				return nullptr;

			return m_NextNode->GetPointer<CSimObject, offsetof(CSimObject, m_Node)>();
		}
	};
}