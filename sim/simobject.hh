#pragma once

namespace UFG
{
	class SimObject;

	class SimComponent : public qSafePointerNode<SimComponent>
	{
	public:
		u32 m_TypeUID;
		u32 m_NameUID;
		u16 m_Flags;
		s16 m_SimObjIndex;
		SimObject* m_pSimObject;
		qList<RebindingComponentHandleBase> m_BoundComponentHandles;
	};
	SDK_ASSERT_SIZEOF(SimComponent, 0x40);
}