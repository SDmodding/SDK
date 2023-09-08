#pragma once

namespace UFG
{
	class CTransformNodeComponent;
	class CSimComponent;
	class CSimObject;

	class CSimComponentHolder
	{
	public:
		CSimComponent* m_pComponent;
		unsigned int m_TypeUID;
	};

	class CSceneObjectProperties
	{
	public:
		UFG_PAD(0x18);

		uint32_t m_TypeUID;
		uint32_t m_NameUID;
		uint16_t m_Flags;
		int16_t m_SimObjIndex;
		CSimObject* m_pSimObject;

		UFG_PAD(0x58);

		uint32_t mLastTeleportFrame;
		qPropertySet* mpWritableProperties;
		qPropertySet* mpConstProperties;
		uint32_t mPrevNameHash;
		uint32_t mChildIndex;

		qPropertySet* GetPropertySet()
		{
			if (mpWritableProperties)
				return mpWritableProperties;

			return mpConstProperties;
		}

		/* 
		* If 'mpWritableProperties' is nullptr, using this will create New PropertySet and append 'mpConstProperties'.
		* This is useful if we wanna modify some data.
		*/
		qPropertySet* GetWritableProperties()
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*)>(UFG_RVA(0x23E2F0))(this);
		}

		eSimObjectTypeEnum2 GetType()
		{
			qPropertySet* m_PropertySet = GetPropertySet();
			if (!m_PropertySet)
				return eSIM_OBJ_TYPE2_Invalid;

			qSymbol* m_TypeHash = m_PropertySet->GetSymbol(0x510C404C); // ObjectType
			switch (m_TypeHash ? *m_TypeHash : 0x0)
			{
				default: return eSIM_OBJ_TYPE2_Invalid; 
				case 0x7B6A0689: return eSIM_OBJ_TYPE2_AIPathMarker;
				case 0x58DAEF8A: return eSIM_OBJ_TYPE2_AIJumpPoint;
				case 0x7C9CA7E3: return eSIM_OBJ_TYPE2_AIOutlineRegion;
				case 0x38DD7EFE: return eSIM_OBJ_TYPE2_AISeedPoint;
				case 0xA24EA7CA: return eSIM_OBJ_TYPE2_AudioEmitterMarker;
				case 0x278618B: return eSIM_OBJ_TYPE2_AudioTriggerRegion;
				case 0xF92D474D: return eSIM_OBJ_TYPE2_BoostRegion;
				case 0xDB0B6EC5: return eSIM_OBJ_TYPE2_Camera;
				case 0x2F962C69: return eSIM_OBJ_TYPE2_CameraMarker;
				case 0xB825B7BB: return eSIM_OBJ_TYPE2_Character;
				case 0x27691395: return eSIM_OBJ_TYPE2_Collectible;
				case 0xEF69DBBB: return eSIM_OBJ_TYPE2_CombatRegion;
				case 0xD4D7D5DD: return eSIM_OBJ_TYPE2_CopRoadBlock;
				case 0xB0EF2BAB: return eSIM_OBJ_TYPE2_Director;
				case 0x1946D26D: return eSIM_OBJ_TYPE2_Door;
				case 0x25504106: return eSIM_OBJ_TYPE2_DynamicLight;
				case 0x903AE4F8: return eSIM_OBJ_TYPE2_FleeToPoint;
				case 0x861E5147: return eSIM_OBJ_TYPE2_FXSimComponent;
				case 0x868843: return eSIM_OBJ_TYPE2_HidingSpot;
				case 0x1CDBE0A9: return eSIM_OBJ_TYPE2_HijackReturn;
				case 0x81A1E08A: return eSIM_OBJ_TYPE2_InterestPoint;
				case 0xEB604C0A: return eSIM_OBJ_TYPE2_IrradianceVolume;
				case 0x261DF63D: return eSIM_OBJ_TYPE2_Marker;
				case 0xACCF9D70: return eSIM_OBJ_TYPE2_MarkerProgressionTrigger;
				case 0x7AE3B440: return eSIM_OBJ_TYPE2_MarkerRaceStartingGrid;
				case 0xD5131A4E: return eSIM_OBJ_TYPE2_MeleeScriptSystem;
				case 0xA113AB1A: return eSIM_OBJ_TYPE2_ModelAsset;
				case 0x4C183A2: return eSIM_OBJ_TYPE2_NISScriptSystem;
				case 0x67FCE20C: return eSIM_OBJ_TYPE2_ParkingSpot;
				case 0x8C8D9A7B: return eSIM_OBJ_TYPE2_Prefab;
				case 0x8ED03A76: return eSIM_OBJ_TYPE2_Prop;
				case 0x86AA2526: return eSIM_OBJ_TYPE2_ReinforcementPoint;
				case 0x57F90554: return eSIM_OBJ_TYPE2_TrafficRegion;
				case 0xE1A54C5C: return eSIM_OBJ_TYPE2_TriggerRegion;
				case 0xAC9D9F10: return eSIM_OBJ_TYPE2_Turf;
				case 0x9B06086B: return eSIM_OBJ_TYPE2_Vehicle;
				case 0x8A5A95FC: return eSIM_OBJ_TYPE2_Weapon;
				case 0x28B63779: return eSIM_OBJ_TYPE2_WeaponSpawner;
				case 0xEF977909: return eSIM_OBJ_TYPE2_StartRegion;
				case 0xF9D450A8: return eSIM_OBJ_TYPE2_SpawnPoint;
				case 0x1A4E4099: return eSIM_OBJ_TYPE2_SpawnPointProgressionTrigger;
				case 0xDE552DA6: return eSIM_OBJ_TYPE2_SpawnRegion;
			}
		}
	};

	class CSimObject
	{
	public:
		UFG_PAD(0x20);

		qBaseNodeRB mNode;
		qSymbol m_Name;
		unsigned short m_Flags;
		char m_ReservedComponentSlots;
		char m_ResolveRefCount;
		CSceneObjectProperties* m_pSceneObj;
		CTransformNodeComponent* m_pTransformNodeComponent;
		qArray<CSimComponentHolder> m_Components;
		void* m_UnboundComponentHandles[2];

		virtual ~CSimObject() { }

		virtual void Attach(CSimComponent* p_Component, uint32_t p_Index) { }

		virtual void Detach(CSimComponent* p_Component) { }

		// SkookumScript
		bool IsReferencedByScripts()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x4E22D0))(this);
		}

		// Highlight
		bool IsHighlighted()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x6E680))(this);
		}

		void Highlight(qColour m_Colour, float m_OutlineStrength = 1.5f, float m_XrayStrength = 0.f, bool m_IsDepthEnabled = true)
		{
			struct HighlightParams_t
			{
				UFG::qColour mColour;
				float mOutlineStrength;
				float mXrayStrength;
				bool mIsDepthEnabled = 1;
			};
			HighlightParams_t m_HighlightParams;
			m_HighlightParams.mColour = m_Colour;
			m_HighlightParams.mOutlineStrength = m_OutlineStrength;
			m_HighlightParams.mXrayStrength = m_XrayStrength;
			m_HighlightParams.mIsDepthEnabled = m_IsDepthEnabled;

			reinterpret_cast<void(__fastcall*)(void*, HighlightParams_t*)>(UFG_RVA(0x6E560))(this, &m_HighlightParams);
		}

		void UnHighlight()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x6EE30))(this);
		}

		// Please check SceneObject Properties to get type...
		int GetType()
		{
			uintptr_t m_VFTable = *reinterpret_cast<uintptr_t*>(this);

			if (m_VFTable == UFG_RVA(0x17C3178)) // Character
				return 1;

			if (m_VFTable == UFG_RVA(0x17C3198))  // Vehicle
				return 2;

			if (m_VFTable == UFG_RVA(0x1797E38)) // Prop/Weapon/Door
				return 3;

			return 0;
		}

		CSimComponent* GetComponentOfType(uint32_t m_TypeUID)
		{
			return reinterpret_cast<CSimComponent*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x190AD0))(this, m_TypeUID);
		}

		template <typename T>
		T* GetComponentOfType(uint32_t m_TypeUID)
		{
			return reinterpret_cast<T*>(GetComponentOfType(m_TypeUID));
		}

		CSimComponent* GetComponentOfTypeHK(uint32_t m_TypeUID)
		{
			return reinterpret_cast<CSimComponent*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x52BBC0))(this, m_TypeUID);
		}

		template <typename T>
		T* GetComponentOfTypeHK(uint32_t m_TypeUID)
		{
			return reinterpret_cast<T*>(GetComponentOfTypeHK(m_TypeUID));
		}

		CSimComponent* GetActor()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags & 0x8000u) == 0)
			{
				if ((m_Flags >> 13) & 1)
					m_Component = m_Components.p[3].m_pComponent;
				else if ((m_Flags >> 12) & 1)
					m_Component = m_Components.p[2].m_pComponent;
				else
					m_Component = GetComponentOfType(0x8A000001); // TSActorComponent::_TypeUID
			}
			else
				m_Component = m_Components.p[4].m_pComponent;

			return reinterpret_cast<CSimComponent*(__fastcall*)(void*)>(UFG_RVA(0x4E0C50))(m_Component);
		}

		CSimObjectPropertiesComponent* GetProperties()
		{
			CSimComponent* m_Component = m_Components.p[3].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					m_Component = m_Components.p[4].m_pComponent;
				else if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(SimObjectProperties_TypeUID);
				else
					m_Component = GetComponentOfType(SimObjectProperties_TypeUID);
			}

			return reinterpret_cast<CSimObjectPropertiesComponent*>(m_Component);
		}

		CCompositeDrawableComponent* GetCompositeDrawable()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				m_Component = m_Components.p[14].m_pComponent;
			else if ((m_Flags & 0x8000u) == 0)
			{
				if ((m_Flags >> 13) & 1)
					m_Component = m_Components.p[9].m_pComponent;
				else if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(SimObjectCompositeDrawable_TypeUID);
				else
					m_Component = GetComponentOfType(SimObjectCompositeDrawable_TypeUID);
			}
			else
				m_Component = m_Components.p[14].m_pComponent;

			return reinterpret_cast<CCompositeDrawableComponent*>(m_Component);
		}

		CFXSimComponent* GetFX()
		{
			CSimComponent* m_Component = nullptr;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000u) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(SimObjectFXComponent_TypeUID);
				else
					m_Component = GetComponentOfType(SimObjectFXComponent_TypeUID);
			}
			else
				m_Component = GetComponentOfTypeHK(SimObjectFXComponent_TypeUID);

			return reinterpret_cast<CFXSimComponent*>(m_Component);
		}

		CBaseAnimationComponent* GetBaseAnimation()
		{
			CSimComponent* m_Component = nullptr;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000u) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(SimObjectBaseAnimation_TypeUID);
				else
					m_Component = GetComponentOfType(SimObjectBaseAnimation_TypeUID);
			}
			else
				m_Component = GetComponentOfTypeHK(SimObjectBaseAnimation_TypeUID);

			return reinterpret_cast<CBaseAnimationComponent*>(m_Component);
		}

		CRigidBodyComponent* GetRigidBody()
		{
			return GetComponentOfType<UFG::CRigidBodyComponent>(SimObjectRigidbody_TypeUID);
		}

		bool TargetAttach(eTargetTypeEnum targetType, CSimObject* pOverrideTarget, CSimObject** ppOutSimObjectTarget, qSymbol attachJoint, qSymbol targetAttachJoint, float blendInTime, bool attachRelative, float attachRelativeMaxDistance, bool attachToTarget, bool addToInventory, bool assignTarget, eTargetTypeEnum assignmentTargetType, bool lockTarget, bool positionOnly, bool positionXYOnly, bool* managePowerLevel)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, eTargetTypeEnum, CSimObject*, CSimObject**, qSymbol*, qSymbol*, float, bool, float, bool, bool, bool, eTargetTypeEnum, bool, bool, bool, bool*)>(UFG_RVA(0x553240))(this, targetType, pOverrideTarget, ppOutSimObjectTarget, &attachJoint, &targetAttachJoint, blendInTime, attachRelative, attachRelativeMaxDistance, attachToTarget, addToInventory, assignTarget, assignmentTargetType, lockTarget, positionOnly, positionXYOnly, managePowerLevel);
		}

		bool TargetDetach(eTargetTypeEnum targetType, CSimObject* pOverrideTarget, qSymbol attachJoint, qSymbol targetAttachJoint, float blendOutTime, bool detachFromTarget, bool removeFromInventory, bool deleteOnDetach, bool releaseTarget, bool makeUpright, bool fadeAwayOnDetach, float disableCollisionDelay, float clampVelocity, bool managePowerLevel)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, eTargetTypeEnum, CSimObject*, qSymbol*, qSymbol*, float, bool, bool, bool, bool, bool, bool, float, float, bool)>(UFG_RVA(0x554F50))(this, targetType, pOverrideTarget, &attachJoint, &targetAttachJoint, blendOutTime, detachFromTarget, removeFromInventory, deleteOnDetach, releaseTarget, makeUpright, fadeAwayOnDetach, disableCollisionDelay, clampVelocity, managePowerLevel);
		}

		bool IsAttached()
		{
			CBaseAnimationComponent* m_BaseAnimation = GetBaseAnimation();
			return (m_BaseAnimation && m_BaseAnimation->mCreature && m_BaseAnimation->mCreature->mIsAttached);
		}

		void Restore()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1911F0))(this);
		}

		void Suspend()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1916D0))(this);
		}

		void Destroy()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1905C0))(this);
		}
	};

	class CBasePhysicsObject
	{
	public:
		UFG_PAD(0x8);

		uintptr_t mComponentSafe;
		uintptr_t mComponent;

		UFG_PAD(0x8);

		CSimComponent* GetComponent()
		{
			if (mComponentSafe != mComponent)
				return nullptr;

			return reinterpret_cast<CSimComponent*>(mComponent - 0x8);
		}
	};

	class CSimulation
	{
	public:
		qTreeRB mSimObjects;
		qTreeRB mSimObjectsToBeDeleted;
		qTreeRB mSimObjectsToBeDeletedRecursively;
		qSafePointer<CSimObject> mpLocalPlayer;
		qArray<CSimObject> m_aCurrentDestructingObjects;

		__inline CSimObject* GetSimObjectHead()
		{
			qBaseNodeRB* m_Node = mSimObjects.mTree.GetHead();
			if (!m_Node)
				return nullptr;

			return m_Node->GetPointer<CSimObject, offsetof(CSimObject, mNode)>();
		}

		__inline CSimObject* GetSimObjectNext(CSimObject* p_SimObject)
		{
			qBaseNodeRB* m_NextNode = mSimObjects.mTree.GetNext(&p_SimObject->mNode);
			if (!m_NextNode || m_NextNode == reinterpret_cast<qBaseNodeRB*>(this))
				return nullptr;

			return m_NextNode->GetPointer<CSimObject, offsetof(CSimObject, mNode)>();
		}
	};

	namespace Sim
	{
		CSimulation* Get()
		{
			return reinterpret_cast<CSimulation*>(UFG_RVA(0x235C3A0));
		}

		qSymbol GenerateActorName(const char* name)
		{
			qSymbol m_Symbol;
			reinterpret_cast<void(__fastcall*)(qSymbol*, const char*)>(UFG_RVA(0x180880))(&m_Symbol, name);

			return m_Symbol;
		}

		qSymbol GenerateUniqueName(const char* m_Root)
		{
			qSymbol m_Symbol;
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, const char*)>(UFG_RVA(0x190A50))(Get(), &m_Symbol, m_Root);

			return m_Symbol;
		}

		CSimObject* GetSimObject(qSymbol m_ObjectName)
		{
			return reinterpret_cast<CSimObject*(__fastcall*)(void*, qSymbol)>(UFG_RVA(0x190C40))(Get(), m_ObjectName);
		}

		// Passing nullptr propertyset will crash game!
		CSimObject* SpawnObject(qSymbol m_ObjectName, qPropertySet* m_PropertySet, int m_Priority = 0, void* m_OwnerLayer = nullptr, void* m_SpawnerSceneObject = nullptr, CSimObject* m_Owner = nullptr)
		{
			UFG::CObjectResourceManager* m_ObjectResourceManager = UFG::ObjectResourceManager::Get();
			if (!m_ObjectResourceManager)
				return nullptr;

			if (!m_ObjectResourceManager->IsLoaded(m_PropertySet))
				m_ObjectResourceManager->PreLoadCriticalResource(m_PropertySet);

			UFG::CSimObject* m_NewObject = reinterpret_cast<CSimObject*(__fastcall*)(qSymbol*, qPropertySet*, int, void*, void*, CSimObject*)>(UFG_RVA(0x5B7410))(&m_ObjectName, m_PropertySet, m_Priority, m_OwnerLayer, m_SpawnerSceneObject, m_Owner);
			m_ObjectResourceManager->ReleaseCriticalResource(m_PropertySet);

			return m_NewObject;
		}

		CSimObject* SpawnObject(qSymbol m_ObjectName, qSymbol m_ObjectHash, int m_Priority = 0, void* m_OwnerLayer = nullptr, void* m_SpawnerSceneObject = nullptr, CSimObject* m_Owner = nullptr)
		{
			qPropertySet* m_PropertySet = PropertySet::Get(m_ObjectHash);
			if (m_PropertySet)
				return SpawnObject(m_ObjectName, m_PropertySet, m_Priority, m_OwnerLayer, m_SpawnerSceneObject, m_Owner);

			return nullptr;
		}

		CSimObject* SpawnUniqueObject(qSymbol m_ObjectName, qSymbol m_ObjectHash, int m_Priority = 0, void* m_OwnerLayer = nullptr, void* m_SpawnerSceneObject = nullptr, CSimObject* m_Owner = nullptr)
		{
			CSimObject* m_Object = GetSimObject(m_ObjectName);
			if (m_Object)
				m_Object->Destroy();

			return SpawnObject(m_ObjectName, m_ObjectHash, m_Priority, m_OwnerLayer, m_SpawnerSceneObject, m_Owner);
		}

		// Passing nullptr propertyset will crash game!
		CSimObject* SpawnObject(qSymbol m_ObjectName, qPropertySet* m_PropertySet, qMatrix44& m_Matrix, int m_Priority = 0, void* m_OwnerLayer = nullptr, void* m_SpawnerSceneObject = nullptr)
		{
			UFG::CObjectResourceManager* m_ObjectResourceManager = UFG::ObjectResourceManager::Get();
			if (!m_ObjectResourceManager)
				return nullptr;

			if (!m_ObjectResourceManager->IsLoaded(m_PropertySet))
				m_ObjectResourceManager->PreLoadCriticalResource(m_PropertySet);

			UFG::CSimObject* m_NewObject = reinterpret_cast<CSimObject*(__fastcall*)(qSymbol*, qPropertySet*, qMatrix44&, int, void*, void*)>(UFG_RVA(0x5B7350))(&m_ObjectName, m_PropertySet, m_Matrix, m_Priority, m_OwnerLayer, m_SpawnerSceneObject);
			m_ObjectResourceManager->ReleaseCriticalResource(m_PropertySet);

			return m_NewObject;
		}

		CSimObject* SpawnObject(qSymbol m_ObjectName, qSymbol m_ObjectHash, qMatrix44& m_Matrix, int m_Priority = 0, void* m_OwnerLayer = nullptr, void* m_SpawnerSceneObject = nullptr)
		{
			qPropertySet* m_PropertySet = PropertySet::Get(m_ObjectHash);
			if (m_PropertySet)
				return SpawnObject(m_ObjectName, m_PropertySet, m_Matrix, m_Priority, m_OwnerLayer, m_SpawnerSceneObject);

			return nullptr;
		}

		CSimObject* SpawnUniqueObject(qSymbol m_ObjectName, qSymbol m_ObjectHash, qMatrix44& m_Matrix, int m_Priority = 0, void* m_OwnerLayer = nullptr, void* m_SpawnerSceneObject = nullptr)
		{
			CSimObject* m_Object = GetSimObject(m_ObjectName);
			if (m_Object)
				m_Object->Destroy();

			return SpawnObject(m_ObjectName, m_ObjectHash, m_Matrix, m_Priority, m_OwnerLayer, m_SpawnerSceneObject);
		}

		bool DestroyObject(qSymbol m_ObjectName)
		{
			CSimObject* m_Object = GetSimObject(m_ObjectName);
			if (!m_Object)
				return false;

			m_Object->Destroy();
			return true;
		}
	}
}