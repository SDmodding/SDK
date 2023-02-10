#pragma once

namespace UFG
{
	class CTransformNodeComponent;
	class CSimComponent;

	class CSimComponentHolder
	{
	public:
		CSimComponent* m_pComponent;
		unsigned int m_TypeUID;
	};

	class CSimObject
	{
	public:
		UFG_PAD(0x48);

		qSymbol m_Name;
		unsigned short m_Flags;
		char m_ReservedComponentSlots;
		char m_ResolveRefCount;
		void* m_pSceneObj;
		CTransformNodeComponent* m_pTransformNodeComponent;
		qArray<CSimComponentHolder> m_Components;
		void* m_UnboundComponentHandles[2];

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

		CSimComponent* GetComponentOfType(unsigned int type_uid)
		{
			return reinterpret_cast<CSimComponent*(__fastcall*)(void*, unsigned int)>(UFG_RVA(0x190AD0))(this, type_uid);
		}

		CSimComponent* GetComponentOfTypeHK(unsigned int type_uid)
		{
			return reinterpret_cast<CSimComponent*(__fastcall*)(void*, unsigned int)>(UFG_RVA(0x52BBC0))(this, type_uid);
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
			CBaseAnimationComponent* m_BaseAnimation = reinterpret_cast<CBaseAnimationComponent*>(GetComponentOfType(CharacterAnimationComponent_TypeUID));
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

	namespace Sim
	{
		void* Get()
		{
			return reinterpret_cast<void*>(UFG_RVA(0x235C3A0));
		}

		qSymbol GenerateActorName(const char* name)
		{
			qSymbol m_Symbol;
			reinterpret_cast<void(__fastcall*)(qSymbol*, const char*)>(UFG_RVA(0x180880))(&m_Symbol, name);

			return m_Symbol;
		}

		CSimObject* GetSimObject(qSymbol objName)
		{
			return reinterpret_cast<CSimObject*(__fastcall*)(void*, qSymbol)>(UFG_RVA(0x190C40))(Get(), objName);
		}

		CSimObject* SpawnObject(qSymbol objName, qSymbol objHash, int priority = 0, void* pOwnerLayer = nullptr, void* pSpawnerSceneObj = nullptr, CSimObject* pOwner = nullptr)
		{
			return reinterpret_cast<CSimObject*(__fastcall*)(qSymbol*, qSymbol*, int, void*, void*, CSimObject*)>(UFG_RVA(0x5B7310))(&objName, &objHash, priority, pOwnerLayer, pSpawnerSceneObj, pOwner);
		}

		CSimObject* SpawnUniqueObject(qSymbol objName, qSymbol objHash, int priority = 0, void* pOwnerLayer = nullptr, void* pSpawnerSceneObj = nullptr, CSimObject* pOwner = nullptr)
		{
			CSimObject* m_Object = GetSimObject(objName);
			if (m_Object)
				m_Object->Destroy();

			return SpawnObject(objName, objHash, priority, pOwnerLayer, pSpawnerSceneObj, pOwner);
		}
	}
}