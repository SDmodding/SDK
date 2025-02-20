#pragma once

namespace UFG
{
	class Simulation
	{
	public:
		qTreeRB<SimObject> mSimObjects;
		qTreeRB<SimObject> mSimObjectsToBeDeleted;
		qTreeRB<SimObject> mSimObjectsToBeDeletedRecursively;
		qSafePointer<SimObject> mpLocalPlayer;
		qArray<SimObject*> m_aCurrentDestructingObjects;

		SDK_SINLINE Simulation* Instance() { return SDK_VAR(Simulation*, 0x235C3A0); }

		/* Functions */

		SimObject* CreateSimObject(const qSymbol& name) { return SDK_CALL_FUNC(SimObject*, 0x190320, void*, const qSymbol&)(this, name); }
		void DestroyAllSimObjects() { SDK_CALL_FUNC(void, 0x1905D0, void*)(this); }
		void DestroyQueuedSimObjects() { SDK_CALL_FUNC(void, 0x190650, void*)(this); }
		void DestroySimComponent(SimComponent* component) { SDK_CALL_FUNC(void, 0x190720, void*, SimComponent*)(this, component); }
		void DestroySimObject(SimObject* object) { SDK_CALL_FUNC(void, 0x190760, void*, SimObject*)(this, object); }

		qSymbol GenerateUniqueName(const qSymbol& root) 
		{
			qProxy<qSymbol> res;
			SDK_CALL_FUNC(void, 0x1909D0, void*, qSymbol*, const qSymbol&)(this, &res, root);
			return *res;
		}

		qSymbol GenerateUniqueName(const char* root) 
		{
			qProxy<qSymbol> res;
			SDK_CALL_FUNC(void, 0x190A50, void*, qSymbol*, const char*)(this, &res, root);
			return *res;
		}

		SimObject* GetSimObject(const qSymbol& name) { return SDK_CALL_FUNC(SimObject*, 0x190BF0, void*, const qSymbol&)(this, name); }
		SimObject* GetSimObject(u32 name_uid) { return SDK_CALL_FUNC(SimObject*, 0x190C40, void*, u32)(this, name_uid); }
		void QueueSimObjectToBeDestroyed(SimObject* pSimObj) { SDK_CALL_FUNC(void, 0x190F10, void*, SimObject*)(this, pSimObj); }
		void QueueSimObjectToBeDestroyedRecursive(SimObject* pSimObj) { SDK_CALL_FUNC(void, 0x190FA0, void*, SimObject*)(this, pSimObj); }
		void QueueTrackedSimObjectToBeDestroyed(SimObject* pSimObj) { SDK_CALL_FUNC(void, 0x191030, void*, SimObject*)(this, pSimObj); }
		void TrackSimObject(SimObject* pSimObj) { SDK_CALL_FUNC(void, 0x1917A0, void*, SimObject*)(this, pSimObj); }
		bool UntrackSimObject(SimObject* pSimObj) { return SDK_CALL_FUNC(bool, 0x1917C0, void*, SimObject*)(this, pSimObj); }
	};
	SDK_ASSERT_SIZEOF(Simulation, 0x100);
}