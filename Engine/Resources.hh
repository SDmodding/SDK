#pragma once

namespace UFG
{
	struct qResourceData : qNodeRB
	{
		qList<struct qResourceHandle> mResourceHandles;
		uint32_t mTypeUID;
		char mDebugName[36];
	};

	struct qResourceHandle
	{
		qNode<qResourceHandle> mNode;
		qResourceData* mData;
		uint32_t mNameUID;
		uint32_t mTailPad;

		~qResourceHandle()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x164090))(this);
		}

		qResourceHandle()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x161BB0))(this);
		}

		UFG_INLINE void Init(uint32_t p_TypeUID, uint32_t p_NameUID)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, uint32_t)>(UFG_RVA(0x1734B0))(this, p_TypeUID, p_NameUID);
		}

		UFG_INLINE void Close()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x167FB0))(this);
		}

		template <typename T>
		UFG_INLINE T* GetData()
		{
			return reinterpret_cast<T*>(mData);
		}

		template <typename T, uintptr_t m_Offset>
		UFG_INLINE T* GetData2()
		{
			if (!mData) {
				return nullptr;
			}

			return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(mData) + m_Offset);
		}
	}; 

	struct qGenericResourceHandle : qResourceHandle
	{
		uint32_t mTypeUID;
	};


	struct qResourceFileHandle : qResourceHandle
	{
		void* mCallback;
		void* mCallbackData;

		UFG_INLINE char* GetFileData(int p_Offset)
		{
			return reinterpret_cast<char*(__fastcall*)(void*, int)>(UFG_RVA(0x170510))(this, p_Offset);
		}
	};

	struct qVRAMemoryHandle : qNode<qVRAMemoryHandle>
	{
		char* mData;
		uint16_t mReadOnlyAndPoolID;
		uint16_t mBlockID;
	};
	UFG_ASSERT_STRUCT(qVRAMemoryHandle, 0x20);
	
	class CPhysicsResourceHandle : public qResourceHandle
	{
	public:
		class CBasePhysicsObject* mOwner;
		bool mUnloading;
	};
}