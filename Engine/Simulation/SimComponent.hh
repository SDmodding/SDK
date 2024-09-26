#pragma once

namespace UFG
{
	class SimComponent
	{
	public:
		void* vfptr;
		UFG_PAD(0x10);

		uint32_t m_TypeUID;
		uint32_t m_NameUID;
		uint16_t m_Flags;
		int16_t m_SimObjIndex;
		SimObject* m_pSimObject;
		qList<RebindingComponentHandle<SimComponent>> m_BoundComponentHandles;

		~SimComponent() { UFG_VCall<0, void>(this); }
		const char* GetDebugTypeName() { return UFG_VCall<4, const char*>(this); }
		void OnAttach(SimObject* p_SimObject) { UFG_VCall<6, void, SimObject*>(this, p_SimObject); }
		void Suspend() { UFG_VCall<8, void>(this); }
		void Restore() { UFG_VCall<9, void>(this); }
		void OnDetach() { UFG_VCall<10, void>(this); }
	}; 
	typedef SimComponent CSimComponent;

	class SimComponentHolder
	{
	public:
		SimComponent* m_pComponent;
		uint32_t m_TypeUID;
	}; typedef SimComponentHolder CSimComponentHolder;
}