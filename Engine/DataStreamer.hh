#pragma once

namespace UFG
{
	namespace DataStreamer
	{
		enum STREAM_FLAGS
		{
			FIXED = 0x1,
			UNCACHEABLE = 0x2,
			MAYNOTEXIST = 0x4,
			LOCKED = 0x8,
			HOT_RESOURCE = 0x10,
			RAW_RESOURCE = 0x20,
			HI_SFW_PRIORITY = 0x40,
			SPREAD_UNLOAD = 0x80,
			ALLOC_FROM_TOP = 0x100,
			MOVEABLE = 0x0,
			CACHEABLE = 0x0,
			DEFAULT = 0x3,
		};

		enum STREAM_STATE
		{
			STATE_ERROR = 0x0,
			STATE_EMPTY = 0x1,
			STATE_LOAD_QUEUED = 0x2,
			STATE_LOADING = 0x3,
			STATE_FIXUP_DELAY = 0x4,
			STATE_RESOURCE_FIXUP = 0x5,
			STATE_ACTIVE = 0x6,
			STATE_DEACTIVATING = 0x7,
			STATE_COUNT = 0x8,
		};

		enum PRIORITY
		{
			VERY_HIGH_PRIORITY = 0x4000,
			HIGH_PRIORITY = 0x3000,
			HIGH_ANIM_PRIORITY = 0x2800,
			DEFAULT_PRIORITY = 0x2000,
			DEFAULT_ANIM_PRIORITY = 0x2000,
			LOW_PRIORITY = 0x1000,
			VERY_LOW_PRIORITY = 0x0,
		};

		struct Handle
		{
			Handle* mPrev;
			Handle* mNext;
			void* mCallback;
			void* mCallbackParam;
			void* mImpl;
			uint16_t mFlags;
			uint16_t mPriority;
			STREAM_STATE mTargetState;

			UFG_INLINE Handle()
			{
				mPrev = reinterpret_cast<Handle*>(&mPrev);
				mNext = reinterpret_cast<Handle*>(&mPrev);
				mCallback = nullptr;
				mCallbackParam = nullptr;
				mImpl = nullptr;
				mFlags = static_cast<uint16_t>(0x20000003);
				mTargetState = STATE_EMPTY;
			}

			UFG_INLINE ~Handle()
			{
				reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x2271F0))(this);
			}
		}; 
		typedef Handle Handle_t;

		struct StreamInfo
		{
			qNodeRB mNode;
			qNode<StreamInfo> mOrderNode;
			qNode<StreamInfo> mPriorityNode;
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
			qList<Handle> mHandles;
			uint32_t mFlagsAND;
			uint32_t mFlagsOR;
			uint32_t mDataLoadedTo;
			uint64_t mDiskPosSortKey;
		}; typedef StreamInfo StreamInfo_t;
		UFG_ASSERT_STRUCT(StreamInfo, 0x108);

		UFG_INLINE bool QueueStream(Handle* p_Handle, const char* p_FileName, uint32_t p_DataType, PRIORITY p_Priority, uint32_t p_Flags, void* p_Callback, void* p_CallbackParam)
		{
			return reinterpret_cast<bool(__fastcall*)(Handle*, const char*, uint32_t, PRIORITY, uint32_t, void*, void*)>(UFG_RVA(0x22C580))(p_Handle, p_FileName, p_DataType, p_Priority, p_Flags, p_Callback, p_CallbackParam);
		}

		UFG_INLINE bool UnloadStreamResources(Handle* p_Handle)
		{
			return reinterpret_cast<bool(__fastcall*)(Handle*)>(UFG_RVA(0x22ED00))(p_Handle);
		}

		UFG_INLINE bool ReleaseStream(Handle* p_Handle)
		{
			return reinterpret_cast<bool(__fastcall*)(Handle*)>(UFG_RVA(0x22CBE0))(p_Handle);
		}
	}
}