#pragma once

namespace UFG
{
	class CSimComponentHolder
	{
	public:
		CSimComponent* m_pComponent;
		uint32_t m_TypeUID;
	};

	class CSimComponent
	{
	public:
		void* vfptr;
		UFG_PAD(0x10);

		uint32_t m_TypeUID;
		uint32_t m_NameUID;
		uint16_t m_Flags;
		int16_t m_SimObjIndex;
		CSimObject* m_pSimObject;
		qList<RebindingComponentHandle<CSimComponent>> m_BoundComponentHandles;

		~CSimComponent() { UFG_VCall<0, void>(this); }
		const char* GetDebugTypeName() { return UFG_VCall<4, const char*>(this); }
		void OnAttach(CSimObject* p_SimObject) { UFG_VCall<6, void, CSimObject*>(this, p_SimObject); }
		void Suspend() { UFG_VCall<8, void>(this); }
		void Restore() { UFG_VCall<9, void>(this); }
		void OnDetach() { UFG_VCall<10, void>(this); }
	};
}