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
		SDK_INLINE T* GetComponent() { return reinterpret_cast<T*>(m_pSimComponent); }

		template <typename T>
		SDK_INLINE T* GetObject() { return reinterpret_cast<T*>(m_pSimObject); }
	};
}