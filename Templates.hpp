#pragma once

namespace UFG
{
	template<typename T>
	struct qSetBase
	{
		uint32_t mCount;
		uint32_t mBufferSize;
		T** mppArray;
	};

	template<typename T>
	struct qArray
	{
		uint32_t size;
		uint32_t capacity;
		T* p;
	};

	template <typename T, size_t N>
	struct qSafeArray
	{
		T array[N];
	};

	template<typename T, size_t N>
	struct qFixedArray
	{
		uint32_t size;
		T p[N];
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

		void Swap(qNode<T>* p_Node)
		{
			if (this->mPrev == this) // Is Head?
			{
				if (this->mNext)
					this->mNext->mPrev = p_Node;

				this->mNext		= p_Node;
				p_Node->mPrev	= this;
				return;
			}

			// Swap next ptrs
			qNode<T>* m_CurrentNext = this->mNext;
			this->mNext		= p_Node->mNext;
			p_Node->mNext	= m_CurrentNext;

			if (this->mNext)
				this->mNext->mPrev = this;

			if (p_Node->mNext)
				p_Node->mNext->mPrev = p_Node;

			// Swap prev ptrs
			qNode<T>* m_CurrentPrev = this->mPrev;
			this->mPrev		= p_Node->mPrev;
			p_Node->mPrev	= m_CurrentPrev;

			if (this->mPrev)
				this->mPrev->mNext = this;
			
			if (p_Node->mPrev)
				p_Node->mPrev->mNext = p_Node;
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

	template <typename T>
	struct LinearGraph
	{
		int nData;
		float* fDomain;
		T* tRange;
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
		uint32_t m_Changed;
		T* m_BindClass;
		T* m_BindCallback;
		T* m_UnbindClass;
		T* m_UnbindCallback;
	};

	template<typename T>
	struct qSafePointerWithCallbacks : qSafePointerWithCallbacksBase<T>
	{
	};

	template<typename T>
	struct qSafePointerNodeWithCallbacks : qSafePointerNode<T>
	{
		qList<qSafePointerWithCallbacksBase<T>> m_SafePointerWithCallbackList;
	};

	template<typename T>
	struct RebindingComponentHandle : qNode<RebindingComponentHandle<T>>
	{
		uint32_t m_TypeUID;

		UFG_PAD(0x4);

		T* m_pSimComponent;
		void* m_pSimObject;
		uint32_t m_Changed;

		UFG_PAD(0x4);
	};

	template <typename T>
	struct qOffset64
	{
		int64_t mOffset;

		UFG_INLINE bool IsValid() 
		{ 
			return mOffset; 
		}

		UFG_INLINE T* Get(uint32_t m_Index, uintptr_t m_Size)
		{
			uintptr_t m_Address = reinterpret_cast<uintptr_t>(this) + mOffset;
			return reinterpret_cast<T*>(m_Address + static_cast<uintptr_t>(m_Index) * m_Size);
		}

		UFG_INLINE T* Get(uint32_t m_Index)
		{
			return Get(m_Index, sizeof(T));
		}

		UFG_INLINE T* GetPointer()
		{
			if (!IsValid()) {
				return nullptr;
			}

			return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + mOffset);
		}

		UFG_INLINE void Set(void* p_Ptr)
		{
			if (p_Ptr) {
				mOffset = static_cast<int64_t>(reinterpret_cast<uintptr_t>(p_Ptr) - reinterpret_cast<uintptr_t>(&mOffset));
				return;
			}

			mOffset = 0;
		}
	};

	// Bin Stuff
	struct BinString
	{
		int64_t mOffset;

		bool IsSet() { return mOffset; }

		const char* Get()
		{
			return reinterpret_cast<const char*>(reinterpret_cast<uintptr_t>(this) + mOffset);
		}
	};

	template <typename T>
	struct BinArray
	{
		int mCount;
		qOffset64<T> mData;
	};


	template <typename T>
	struct BinPtrArray
	{
		int mCount;
		qOffset64<qOffset64<T>> mData;

		uint32_t GetRealCount()
		{
			return (static_cast<uint32_t>(mCount) & 0x7FFFFFFFu);
		}

		T* GetFromIndex(uint32_t p_Index)
		{
			qOffset64<T>* m_OffsetPtr = mData.GetPointer();
			if (m_OffsetPtr)
				return m_OffsetPtr[p_Index].GetPointer();

			return nullptr;
		}
	};

	// Reflect Stuff
	template <typename T>
	struct qReflectArray
	{
		T* mItems;
		uint32_t mNumItems;
		uint32_t mFlags;
	};

	// Havok Stuff
	template <typename T>
	struct HavokArray
	{
		T* m_data;
		int m_size;
		int m_capacityAndFlags;
	};
}
