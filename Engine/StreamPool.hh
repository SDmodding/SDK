#pragma once

namespace UFG
{
	class CStreamPool
	{
	public:
		qNode<CStreamPool> mNode;
		uint32_t mPoolSize;
		uint32_t mHighWatermark;
		uint32_t mDefragReserve;
		uint32_t mTopAllocSizeThreshold;
		uint32_t mSizeByType[4];
		bool mbAllowDefrag;
		bool mbPotentiallyDefraggable;
		bool mbGPUBlockOnDefag;
		char mPoolName[32];

		UFG_PAD(0x5);

		UFG_PAD(0x58);
		//UFG::BlockHeader mBlockHead;
		qTreeRB mBlockLookup;

		uint32_t mPoolIndex;
		uint32_t mPageSize;
		uint32_t mAlignment;
		void* mOwnedDataBuffer;

		UFG_PAD(0x68);
		//UFG::DefragState mDefragState;
	};

	namespace StreamPool
	{
		UFG_INLINE CStreamPool* Get(uint32_t p_Index)
		{
			return reinterpret_cast<CStreamPool**>(UFG_RVA(0x236FBD0))[p_Index];
		}

		UFG_INLINE bool Create(uint32_t p_Index, uint64_t p_PageSize, uint32_t p_PageCount, uint32_t p_Alignment, bool p_AllowDefrag, const char* p_Name, CMemoryPool* p_MemoryPool)
		{
			return reinterpret_cast<bool(__fastcall*)(uint32_t, uint64_t, uint32_t, uint32_t, bool, const char*, CMemoryPool*)>(UFG_RVA(0x22E5D0))(p_Index, p_PageSize, p_PageCount, p_Alignment, p_AllowDefrag, p_Name, p_MemoryPool);
		}

		UFG_INLINE bool Create(uint32_t p_Index, uint64_t p_PageSize, uint32_t p_Alignment, bool p_AllowDefrag, const char* p_Name, CMemoryPool* p_MemoryPool)
		{
			return reinterpret_cast<bool(__fastcall*)(uint32_t, uint64_t, uint32_t, bool, const char*, CMemoryPool*)>(UFG_RVA(0x22E6A0))(p_Index, p_PageSize, p_Alignment, p_AllowDefrag, p_Name, p_MemoryPool);
		}
	}
}