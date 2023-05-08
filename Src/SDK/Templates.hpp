#pragma once

namespace UFG
{
	template<typename T>
	struct qSetBase
	{
		unsigned int mCount;
		unsigned int mBufferSize;
		T** mppArray;
	};

	template<typename T>
	struct qArray
	{
		unsigned int size;
		unsigned int capacity;
		T* p;
	};

	template<typename T>
	struct qNode
	{
		qNode<T>* mPrev;
		qNode<T>* mNext;

		T* GetBase() { return reinterpret_cast<T*>(this); }

		template <uintptr_t N = 0>
		T* GetPointer() { return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + N); }

		template <uintptr_t N = 0>
		T* GetPointerSub() { return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) - N); }

		void GetVector(std::vector<T*>& m_Vector)
		{
			for (qNode<T>* i = mNext; i != this; i = i->mNext)
				m_Vector.emplace_back(i->GetPointer());
		}
	};

	template <typename T>
	struct qList
	{
		qNode<T> mNode;
	};

	template<typename T>
	struct HomerCubic
	{
		T mDuration;
		T mParameter;
		T A;
		T B;
		T C;
		T D;
		T p0;
		T p1;
		T v0;
		T v1;
	};

	template<typename T>
	struct qSafePointerBase
	{
		void* mPrev;
		void* mNext;

		T* m_pPointer;
	};

	template<typename T>
	struct qSafePointer : qSafePointerBase<T>
	{ };

	template<typename T>
	struct qSafePointerNode
	{
		qSafePointerNode<T>* vfptr;
		qList<qSafePointerBase<T>> m_SafePointerList;
	};


	template<typename T>
	struct qSafePointerWithCallbacksBase
	{
		qNode<qSafePointerWithCallbacksBase<T>> m_Node;
		T* m_pPointer;
		unsigned int m_Changed;
		T* m_BindClass;
		T* m_BindCallback;
		T* m_UnbindClass;
		T* m_UnbindCallback;
	};


	template<typename T>
	struct qSafePointerNodeWithCallbacks : qSafePointerNode<T>
	{
		qList<qSafePointerWithCallbacksBase<T>> m_SafePointerWithCallbackList;
	};

	template<typename T>
	struct RebindingComponentHandle
	{
		UFG_PAD(0x10);

		unsigned int m_TypeUID;

		UFG_PAD(0x4);

		T* m_pSimComponent;
		void* m_pSimObject;
		unsigned int m_Changed;

		UFG_PAD(0x4);
	};


	template <typename T>
	struct qOffset64
	{
		__int64 mOffset;

		__inline bool IsValid() { return mOffset; }

		T* Get(uint32_t m_Index, uintptr_t m_Size)
		{
			uintptr_t m_Address = reinterpret_cast<uintptr_t>(this) + mOffset;
			return reinterpret_cast<T*>(m_Address + static_cast<uintptr_t>(m_Index) * m_Size);
		}

		T* Get(uint32_t m_Index)
		{
			return Get(m_Index, sizeof(T));
		}

		T* GetPointer()
		{
			if (!IsValid())
				return nullptr;

			return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + mOffset);
		}
	};
}
