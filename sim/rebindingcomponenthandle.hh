#pragma once

namespace UFG
{
	class RebindingComponentHandleBase : public qNode<RebindingComponentHandleBase>
	{
	public:
		u32 m_TypeUID;
		SimComponent* m_pSimComponent;
		SimObject* m_pSimObject;
		u32 m_Changed;
	};

	template <typename T>
	class RebindingComponentHandle : public RebindingComponentHandleBase
	{
	public:
	};
}