#pragma once

namespace UFG
{
	struct qResourceData
	{
		qBaseNodeRB m_Node;

		UFG_PAD(0x10);

		uint32_t mTypeUID;
		char mDebugName[0x24];
	};

	struct qResourceHandle
	{
		qNode<qResourceHandle> mNode;
		qResourceData* mData;
		uint32_t mNameUID;
		uint32_t mTailPad;

		qResourceHandle()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x161BB0))(this);
		}

		void Init(uint32_t p_TypeUID, uint32_t p_NameUID)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, uint32_t)>(UFG_RVA(0x1734B0))(this, p_TypeUID, p_NameUID);
		}

		void Close()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x167FB0))(this);
		}

		template <typename T>
		__inline T* GetData()
		{
			return reinterpret_cast<T*>(mData);
		}

		template <typename T, uintptr_t m_Offset>
		__inline T* GetData2()
		{
			if (!mData)
				return nullptr;

			return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(mData) + m_Offset);
		}
	};
}