#pragma once

namespace UFG
{
	namespace DataStreamer
	{
		struct Handle_t
		{
			Handle_t* mPrev;
			Handle_t* mNext;
			void* mCallback;
			void* mCallbackParam;
			void* mImpl;
			uint16_t mFlags;
			uint16_t mPriority;
			STREAM_STATE mTargetState;

			void Initialize()
			{
				mPrev = reinterpret_cast<Handle_t*>(&mPrev);
				mNext = reinterpret_cast<Handle_t*>(&mPrev);
				mCallback = nullptr;
				mCallbackParam = nullptr;
				mImpl = nullptr;
				mFlags = static_cast<uint16_t>(0x20000003);
				mTargetState = STATE_EMPTY;
			}

			~Handle_t()
			{

			}

			Handle_t()
			{
				Initialize();
			}

			void Free()
			{
				MemoryPool::GetMainPool()->Free(this);
			}
		};

		struct StreamInfo_t
		{
			qNodeRB mNode;
			qNode<StreamInfo_t> mOrderNode;
			qNode<StreamInfo_t> mPriorityNode;
			STREAM_STATE mStateCurrent;
			STREAM_STATE mStateTarget;
			StreamingMemory::DATA_TYPE mDataType;
			float mTimeInState;
			uint16_t mFilesQueried : 1;
			uint16_t mDBGResLoaded : 1;
			uint16_t mbWasCPURAMRestoredFromCache : 1;
			uint16_t mDBG : 1;
			uint16_t mHotResource : 1;
			uint16_t mMainAllocFailed : 1;
			uint16_t mVRAMAllocFailed : 1;
			uint16_t mIsTagged : 1;
			uint16_t mAddedExternalChunks : 1;
			uint16_t mDeactivationTicks;
			BIGFileSize mFileSizePerm;
			uint64_t mhBufferPerm;
			void* mhFilePerm;
			BIGFileSize mFileSizeTemp;
			qResourceHandle mhBufferTemp;
			void* mhFileTemp;
			qString mFileName;
			uint32_t mTagSymbolUID;
			qList<Handle_t> mHandles;
			uint32_t mFlagsAND;
			uint32_t mFlagsOR;
			uint32_t mDataLoadedTo;
			uint64_t mDiskPosSortKey;
		};
		UFG_ASSERT_STRUCT(StreamInfo_t, 0x108);

		namespace Handle
		{
			Handle_t* New(const char* p_Name)
			{
				Handle_t* m_Handle = reinterpret_cast<Handle_t*>(Malloc(sizeof(Handle_t), p_Name, 0));
				if (m_Handle)
					m_Handle->Initialize();

				return m_Handle;
			}
		}

		bool QueueStream(Handle_t* p_Handle, const char* p_FileName, uint32_t p_DataType, PRIORITY p_Priority, uint32_t p_Flags, void* p_Callback, void* p_CallbackParam)
		{
			return reinterpret_cast<bool(__fastcall*)(Handle_t*, const char*, uint32_t, PRIORITY, uint32_t, void*, void*)>(UFG_RVA(0x22C580))(p_Handle, p_FileName, p_DataType, p_Priority, p_Flags, p_Callback, p_CallbackParam);
		}

		bool UnloadStreamResources(Handle_t* p_Handle)
		{
			return reinterpret_cast<bool(__fastcall*)(Handle_t*)>(UFG_RVA(0x22ED00))(p_Handle);
		}

		bool ReleaseStream(Handle_t* p_Handle)
		{
			return reinterpret_cast<bool(__fastcall*)(Handle_t*)>(UFG_RVA(0x22CBE0))(p_Handle);
		}
	}
}