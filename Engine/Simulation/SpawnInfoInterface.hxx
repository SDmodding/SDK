#pragma once

namespace UFG
{
	namespace SpawnInfoInterface
	{
		enum SpawnPriority : int
		{
			None = 0,
			High,
			Medium,
			Low,
			Critical,
			NumSpawnPriorities
		};

		CSimObject* SpawnObject(qSymbol p_ObjNameUID, qPropertySet* p_PropertySet, SpawnPriority p_Priority = None, void* p_OwnerLayer = nullptr, CSceneObjectProperties* m_SpawnerSceneObj = nullptr, CSimObject* p_Owner = nullptr)
		{
			UFG::CObjectResourceManager* m_ObjResourceManager = UFG::CObjectResourceManager::Instance();
			if (!m_ObjResourceManager)
				return nullptr;

			if (!m_ObjResourceManager->IsLoaded(p_PropertySet))
				m_ObjResourceManager->PreLoadCriticalResource(p_PropertySet);

			UFG::CSimObject* m_SimObject = reinterpret_cast<CSimObject*(__fastcall*)(qSymbol*, qPropertySet*, SpawnPriority, void*, CSceneObjectProperties*, CSimObject*)>(UFG_RVA(0x5B7410))(&p_ObjNameUID, p_PropertySet, p_Priority, p_OwnerLayer, m_SpawnerSceneObj, p_Owner);
			m_ObjResourceManager->ReleaseCriticalResource(p_PropertySet);

			return m_SimObject;
		}

		__inline CSimObject* SpawnObject(qSymbol p_ObjNameUID, qSymbol p_PropertyNameUID, SpawnPriority p_Priority = None, void* p_OwnerLayer = nullptr, CSceneObjectProperties* p_SpawnerSceneObj = nullptr, CSimObject* p_Owner = nullptr)
		{
			qPropertySet* m_PropertySet = PropertySetManager::GetPropertySet(p_PropertyNameUID);
			if (m_PropertySet) {
				return SpawnObject(p_ObjNameUID, m_PropertySet, p_Priority, p_OwnerLayer, p_SpawnerSceneObj, p_Owner);
			}
			return nullptr;
		}

		CSimObject* SpawnObject(qSymbol p_ObjNameUID, qPropertySet* p_PropertySet, qMatrix44* p_Matrix, SpawnPriority p_Priority = None, void* m_OwnerLayer = nullptr, CSceneObjectProperties* p_SpawnerSceneObj = nullptr)
		{
			UFG::CObjectResourceManager* m_ObjResourceManager = UFG::CObjectResourceManager::Instance();
			if (!m_ObjResourceManager)
				return nullptr;

			if (!m_ObjResourceManager->IsLoaded(p_PropertySet))
				m_ObjResourceManager->PreLoadCriticalResource(p_PropertySet);

			UFG::CSimObject* m_SimObject = reinterpret_cast<CSimObject*(__fastcall*)(qSymbol*, qPropertySet*, qMatrix44*, SpawnPriority, void*, CSceneObjectProperties*)>(UFG_RVA(0x5B7350))(&p_ObjNameUID, p_PropertySet, p_Matrix, p_Priority, m_OwnerLayer, p_SpawnerSceneObj);
			m_ObjResourceManager->ReleaseCriticalResource(p_PropertySet);

			return m_SimObject;
		}

		__inline CSimObject* SpawnObject(qSymbol p_ObjNameUID, qSymbol p_PropertyNameUID, qMatrix44* p_Matrix, SpawnPriority p_Priority = None, void* p_OwnerLayer = nullptr, CSceneObjectProperties* p_SpawnerSceneObj = nullptr)
		{
			qPropertySet* m_PropertySet = PropertySetManager::GetPropertySet(p_PropertyNameUID);
			if (m_PropertySet) {
				return SpawnObject(p_ObjNameUID, m_PropertySet, p_Matrix, p_Priority, p_OwnerLayer, p_SpawnerSceneObj);
			}
			return nullptr;
		}
	}
}