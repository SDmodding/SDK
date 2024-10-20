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

		UFG_INLINE SimObject* SpawnObject(qSymbol p_ObjNameUID, qPropertySet* p_PropertySet, SpawnPriority p_Priority = None, void* p_OwnerLayer = nullptr, SceneObjectProperties* m_SpawnerSceneObj = nullptr, SimObject* p_Owner = nullptr)
		{
			UFG::CObjectResourceManager* pObjResourceMgr = UFG::CObjectResourceManager::Instance();
			if (!pObjResourceMgr) {
				return nullptr;
			}

			if (!pObjResourceMgr->IsLoaded(p_PropertySet)) {
				pObjResourceMgr->PreLoadCriticalResource(p_PropertySet);
			}

			UFG::SimObject* pSimObject = reinterpret_cast<SimObject*(__fastcall*)(qSymbol*, qPropertySet*, SpawnPriority, void*, SceneObjectProperties*, SimObject*)>(UFG_RVA(0x5B7410))(&p_ObjNameUID, p_PropertySet, p_Priority, p_OwnerLayer, m_SpawnerSceneObj, p_Owner);
			pObjResourceMgr->ReleaseCriticalResource(p_PropertySet);

			return pSimObject;
		}

		UFG_INLINE SimObject* SpawnObject(qSymbol p_ObjNameUID, qSymbol p_PropertyNameUID, SpawnPriority p_Priority = None, void* p_OwnerLayer = nullptr, SceneObjectProperties* p_SpawnerSceneObj = nullptr, SimObject* p_Owner = nullptr)
		{
			qPropertySet* pPropertySet = PropertySetManager::GetPropertySet(p_PropertyNameUID);
			if (pPropertySet) {
				return SpawnObject(p_ObjNameUID, pPropertySet, p_Priority, p_OwnerLayer, p_SpawnerSceneObj, p_Owner);
			}
			return nullptr;
		}

		UFG_INLINE SimObject* SpawnObject(qSymbol p_ObjNameUID, qPropertySet* p_PropertySet, qMatrix44* p_Matrix, SpawnPriority p_Priority = None, void* m_OwnerLayer = nullptr, SceneObjectProperties* p_SpawnerSceneObj = nullptr)
		{
			UFG::CObjectResourceManager* pObjResourceMgr = UFG::CObjectResourceManager::Instance();
			if (!pObjResourceMgr) {
				return nullptr;
			}

			if (!pObjResourceMgr->IsLoaded(p_PropertySet)) {
				pObjResourceMgr->PreLoadCriticalResource(p_PropertySet);
			}

			UFG::SimObject* pSimObject = reinterpret_cast<SimObject*(__fastcall*)(qSymbol*, qPropertySet*, qMatrix44*, SpawnPriority, void*, SceneObjectProperties*)>(UFG_RVA(0x5B7350))(&p_ObjNameUID, p_PropertySet, p_Matrix, p_Priority, m_OwnerLayer, p_SpawnerSceneObj);
			pObjResourceMgr->ReleaseCriticalResource(p_PropertySet);

			return pSimObject;
		}

		UFG_INLINE SimObject* SpawnObject(qSymbol p_ObjNameUID, qSymbol p_PropertyNameUID, qMatrix44* p_Matrix, SpawnPriority p_Priority = None, void* p_OwnerLayer = nullptr, SceneObjectProperties* p_SpawnerSceneObj = nullptr)
		{
			qPropertySet* pPropertySet = PropertySetManager::GetPropertySet(p_PropertyNameUID);
			if (pPropertySet) {
				return SpawnObject(p_ObjNameUID, pPropertySet, p_Matrix, p_Priority, p_OwnerLayer, p_SpawnerSceneObj);
			}
			return nullptr;
		}
	}
}