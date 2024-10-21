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

		SDK_SINLINE Simulation* Instance() { return reinterpret_cast<Simulation*>(SDK_RVA(0x235C3A0)); }

		/* Functions */

		SimObject* CreateSimObject(const qSymbol& name) { return reinterpret_cast<SimObject*(SDK_CALL*)(void*, const qSymbol&)>(SDK_RVA(0x190320))(this, name); }
		void DestroyAllSimObjects() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x1905D0))(this); }
		void DestroyQueuedSimObjects() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x190650))(this); }
		void DestroySimComponent(SimComponent* component) { reinterpret_cast<void(SDK_CALL*)(void*, SimComponent*)>(SDK_RVA(0x190720))(this, component); }
		void DestroySimObject(SimObject* object) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x190760))(this, object); }
		qSymbol GenerateUniqueName(const qSymbol& root) { return reinterpret_cast<qSymbol(SDK_CALL*)(void*, const qSymbol&)>(SDK_RVA(0x1909D0))(this, root); }
		qSymbol GenerateUniqueName(const char* root) { return reinterpret_cast<qSymbol(SDK_CALL*)(void*, const char*)>(SDK_RVA(0x190A50))(this, root); }
		SimObject* GetSimObject(const qSymbol& name) { return reinterpret_cast<SimObject*(SDK_CALL*)(void*, const qSymbol&)>(SDK_RVA(0x190BF0))(this, name); }
		SimObject* GetSimObject(u32 name_uid) { return reinterpret_cast<SimObject*(SDK_CALL*)(void*, u32)>(SDK_RVA(0x190C40))(this, name_uid); }
		void QueueSimObjectToBeDestroyed(SimObject* pSimObj) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x190F10))(this, pSimObj); }
		void QueueSimObjectToBeDestroyedRecursive(SimObject* pSimObj) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x190FA0))(this, pSimObj); }
		void QueueTrackedSimObjectToBeDestroyed(SimObject* pSimObj) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x191030))(this, pSimObj); }
		void TrackSimObject(SimObject* pSimObj) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x1917A0))(this, pSimObj); }
		bool UntrackSimObject(SimObject* pSimObj) { return reinterpret_cast<bool(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x1917C0))(this, pSimObj); }
	};
	SDK_ASSERT_SIZEOF(Simulation, 0x100);
}