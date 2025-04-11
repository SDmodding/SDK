#pragma once

namespace UFG
{
	class PedKnowledgeRecord
	{
	public:
		qSafePointer<SimObject> pSimObject;
		u64 m_uLastTimeSeen;
		u64 m_uLastLOSTest;
		u64 m_uLastPathTest;
		bool m_bCanSee : 1;
		bool m_bHasEverSeen : 1;
		bool m_bCanPathTo : 1;

		PedKnowledgeRecord() : m_uLastTimeSeen(0), m_uLastLOSTest(0), m_uLastPathTest(0), m_bCanSee(0), m_bHasEverSeen(0), m_bCanPathTo(1) {}
	};

	class PedKnowledgeBase
	{
	public:
		qSafePointer<SimObject> m_pParentSimObject;
		bool m_bEnabled;
		qArray<PedKnowledgeRecord, 15> m_aHostilePedRecords;
		Ticket m_ticketRefreshHostiles;
		Ticket m_ticketUpdate;

		/* Functions */

		void AddRecordForHostile(SimObject* pNewHostile) { SDK_CALL_FUNC(void, 0x340B90, void*, SimObject*)(this, pNewHostile); }

		f32 GetLineOfSightPriority(const qVector3& vMyPos, PedKnowledgeRecord& pedKnowledgeRecord) {
			return SDK_CALL_FUNC(f32, 0x360AD0, void*, const qVector3&, PedKnowledgeRecord&)(this, vMyPos, pedKnowledgeRecord);
		}

		void OnAttach(SimObject* pParentSimObj) { SDK_CALL_FUNC(void, 0x379160, void*, SimObject*)(this, pParentSimObj); }
		void OnDetach() { SDK_CALL_FUNC(void, 0x37B000, void*)(this); }
		void RefreshHostileList(f32 fDeltaTime) { SDK_CALL_FUNC(void, 0x380350, void*, f32)(this, fDeltaTime); }
		void Update(f32 fDeltaTime) { SDK_CALL_FUNC(void, 0x391870, void*, f32)(this, fDeltaTime); }
	};
}