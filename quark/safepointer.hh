#pragma once

namespace UFG
{
	template <typename T>
	class qSafePointerBase : public qNode<qSafePointerBase<T>>
	{
	public:
		T* m_pPointer;
	};

	template <typename T>
	class qSafePointer : public qSafePointerBase<T>
	{
	public:
	};

	template <typename T>
	class qSafePointerNode
	{
	public:
		qList<qSafePointerBase<T>> m_SafePointerList;

		virtual ~qSafePointerNode() = 0;
	};

	template <typename T>
	class qSafePointerWithCallbacksBase : public qNode<qSafePointerWithCallbacksBase<T>>
	{
	public:
		T* m_pPointer;
		u32 m_Changed;
		fastdelegate::FastDelegate1<T*> m_BindCallback;
		fastdelegate::FastDelegate1<T*> m_UnbindCallback;
	};

	template <typename T>
	class qSafePointerNodeWithCallbacks : public qSafePointerNode<T>
	{
	public:
		qList<qSafePointerWithCallbacksBase<T>> m_SafePointerWithCallbackList;
	};

}