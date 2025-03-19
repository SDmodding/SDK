#pragma once

namespace UFG
{
	class DataStreamer
	{
	public:
		enum DISK_POS_SORT_MODE
		{
			SORT_BY_PRIORITY,
			SORT_BY_PRIORITY_THEN_DISK_POSITION = 1,
			SORT_BY_DEFAULT = 1,
			SORT_BY_DISK_POSITION = 2
		};

		enum OPENFILES_RESULT
		{
			OPENFILES_OK,
			OPENFILES_FILE_ERROR,
			OPENFILES_NO_MEMORY
		};

		enum PRIORITY
		{
			VERY_LOW_PRIORITY = 0x0,
			LOW_PRIORITY = 0x1000,
			DEFAULT_PRIORITY = 0x2000,
			DEFAULT_ANIM_PRIORITY = 0x2000,
			HIGH_ANIM_PRIORITY = 0x2800,
			HIGH_PRIORITY = 0x3000,
			VERY_HIGH_PRIORITY = 0x4000
		};

		enum STREAM_FLAGS
		{
			MOVEABLE = 0,
			CACHEABLE = 0,
			FIXED = 1,
			UNCACHEABLE = 2,
			DEFAULT = 3,
			MAYNOTEXIST = 4,
			LOCKED = 8,
			HOT_RESOURCE = 16,
			RAW_RESOURCE = 32,
			HI_SFW_PRIORITY = 64,
			SPREAD_UNLOAD = 128,
			ALLOC_FROM_TOP = 256
		};

		enum STREAM_STATE
		{
			STATE_ERROR,
			STATE_EMPTY,
			STATE_LOAD_QUEUED,
			STATE_LOADING,
			STATE_FIXUP_DELAY,
			STATE_RESOURCE_FIXUP,
			STATE_ACTIVE,
			STATE_DEACTIVATING,
			STATE_COUNT
		};

		struct Handle : public qNode<Handle>
		{
			void(__fastcall* mCallback)(Handle*, void*);
			void* mCallbackParam;
			void* mImpl;
			u16 mFlags;
			qEnum<PRIORITY, u16> mPriority;
			qEnum<STREAM_STATE, u16> _mTargetState;

			Handle() : mCallback(0), mCallbackParam(0), mImpl(0), mFlags(DEFAULT), mPriority(DEFAULT_PRIORITY), _mTargetState(STATE_EMPTY) {}
			~Handle() { SDK_CALL_FUNC(void, 0x2271F0, void*)(this); }
		};

		struct StreamInfo : public qNodeRB<StreamInfo>, public qNode<StreamInfo, class StreamOrder>, public qNode<StreamInfo, class Priority>
		{
			STREAM_STATE mStateCurrent;
			STREAM_STATE mStateTarget;
			StreamingMemory::DATA_TYPE mDataType;
			f32 mTimeInState;
			u16 mFilesQueried : 1;
			u16 mDBGResLoaded : 1;
			u16 mbWasCPURAMRestoredFromCache : 1;
			u16 mDBG : 1;
			u16 mHotResource : 1;
			u16 mMainAllocFailed : 1;
			u16 mVRAMAllocFailed : 1;
			u16 mIsTagged : 1;
			u16 mAddedExternalChunks : 1;
			u16 mDeactivationTicks;
			BIGFileSize mFileSizePerm;
			u64 mhBufferPerm;
			void* mhFilePerm;
			BIGFileSize mFileSizeTemp;
			qVRAMemoryHandle mhBufferTemp;
			void* mhFileTemp;
			qString mFileName;
			u32 mTagSymbolUID;
			qList<Handle> mHandles;
			u32 mFlagsAND;
			u32 mFlagsOR;
			u32 mDataLoadedTo;
			u64 mDiskPosSortKey;

			/* Functions */

			void RecacheHandleInfo() { SDK_CALL_FUNC(void, 0x22CB70, void*)(this); }
		};

		/* Static Members */

		SDK_VINLINE qGlobalVar<u32, 0x236FA80> mLoadedBytes;
		SDK_VINLINE qGlobalVar<int, 0x236FE88> gDisableSpreadedUnloadTick;

		/* Impl Static Functions */

		SDK_SINLINE void DisableSpreadedUnload() { gDisableSpreadedUnloadTick = 15; }
		SDK_SINLINE u32 GetLoadedBytes() { return mLoadedBytes; }
		SDK_SINLINE void ResetLoadedBytes() { mLoadedBytes = 0; }

		/* Static Functions */

		SDK_SINLINE StreamInfo* AllocateStreamInfo(const char* fileName, u32 streamUID) { return SDK_CALL_FUNC(StreamInfo*, 0x227EB0, const char*, u32)(fileName, streamUID); }
		SDK_SINLINE bool BeginLoading(StreamInfo* streamInfo) { return SDK_CALL_FUNC(bool, 0x227F70, StreamInfo*)(streamInfo); }
		SDK_SINLINE void BeginTagging(StreamingMemory::DATA_TYPE* dataTypes, u32 numDataTypes) { SDK_CALL_FUNC(void, 0x228120, StreamingMemory::DATA_TYPE*, u32)(dataTypes, numDataTypes); }
		SDK_SINLINE void BeginTagging() { SDK_CALL_FUNC(void, 0x2281C0)(); }
		SDK_SINLINE void EndTagging() { SDK_CALL_FUNC(void, 0x228D20)(); }
		SDK_SINLINE void FinishLoadingResources(StreamInfo* streamInfo) { SDK_CALL_FUNC(void, 0x229110, StreamInfo*)(streamInfo); }
		SDK_SINLINE void FireStreamLoadCallback(StreamInfo* streamInfo) { SDK_CALL_FUNC(void, 0x229290, StreamInfo*)(streamInfo); }
		SDK_SINLINE bool GetBufferFromUID(u32 uid, void*& buffer_ptr, u32& buffer_size) { return SDK_CALL_FUNC(bool, 0x229660, u32, void*&, u32&)(uid, buffer_ptr, buffer_size); }
		SDK_SINLINE u64 GetDiskPosSortKey(const char* filename) { return SDK_CALL_FUNC(u64, 0x229820, const char*)(filename); }
		SDK_SINLINE u32 GetQueuedBytes() { return SDK_CALL_FUNC(u32, 0x229C50)(); }
		SDK_SINLINE u32 GetReadBytes(const Handle& handle) { return SDK_CALL_FUNC(u32, 0x229CB0, const Handle&)(handle); }
		SDK_SINLINE STREAM_STATE GetStreamState(const Handle& handle) { return SDK_CALL_FUNC(STREAM_STATE, 0x229CD0, const Handle&)(handle); }
		SDK_SINLINE bool IsBusy(StreamingMemory::DATA_TYPE* dataTypes, u32 numDataTypes) { return SDK_CALL_FUNC(bool, 0x22A550, StreamingMemory::DATA_TYPE*, u32)(dataTypes, numDataTypes); }
		SDK_SINLINE bool IsInLoopCondition(StreamingMemory::DATA_TYPE* dataTypes, u32 numDataTypes) { return SDK_CALL_FUNC(bool, 0x22A5F0, StreamingMemory::DATA_TYPE*, u32)(dataTypes, numDataTypes); }
		SDK_SINLINE bool IsStalled(StreamingMemory::DATA_TYPE* dataTypes, u32 numDataTypes) { return SDK_CALL_FUNC(bool, 0x22A670, StreamingMemory::DATA_TYPE*, u32)(dataTypes, numDataTypes); }
		SDK_SINLINE bool IsTaggedBusy() { return SDK_CALL_FUNC(bool, 0x22A740)(); }
		SDK_SINLINE bool IsTaggedStalled() { return SDK_CALL_FUNC(bool, 0x22A790)(); }
		SDK_SINLINE void LoadStreamResources(StreamInfo* streamInfo) { SDK_CALL_FUNC(void, 0x22AEA0, StreamInfo*)(streamInfo); }

		SDK_SINLINE OPENFILES_RESULT OpenFiles(StreamInfo* streamInfo, u32* CPURAMRestoredSizeBytes, u32* VRAMRestoredSizeBytes) {
			return SDK_CALL_FUNC(OPENFILES_RESULT, 0x22BE00, StreamInfo*, u32*, u32*)(streamInfo, CPURAMRestoredSizeBytes, VRAMRestoredSizeBytes);
		}

		SDK_SINLINE bool QueueStream(Handle& handle, const char* filename, StreamingMemory::DATA_TYPE data_type, PRIORITY priority, u32 flags = DEFAULT, void(__fastcall* callback)(Handle*, void*) = 0, void* callbackParam = 0) {
			return SDK_CALL_FUNC(bool, 0x22C580, Handle&, const char*, int, int, int, void*, void*)(handle, filename, data_type, priority, flags, callback, callbackParam);
		}

		SDK_SINLINE bool QueueStream(Handle& handle, const char* filename, u32 mem_tag_qsymbol_uid, StreamingMemory::DATA_TYPE data_type, PRIORITY priority, u32 flags = DEFAULT, void(__fastcall* callback)(Handle*, void*) = 0, void* callbackParam = 0) {
			return SDK_CALL_FUNC(bool, 0x22C360, Handle&, const char*, u32, int, int, u32, void*, void*)(handle, filename, mem_tag_qsymbol_uid, data_type, priority, flags, callback, callbackParam);
		}

		SDK_SINLINE bool ReleaseStream(Handle& handle) { return SDK_CALL_FUNC(char, 0x22CBE0, Handle&)(handle); }
		SDK_SINLINE void ResetLoopConditionDetection() { SDK_CALL_FUNC(void, 0x22CE70)(); }
		SDK_SINLINE void Service(f32 dT) { SDK_CALL_FUNC(void, 0x22D270, f32)(dT); }
		SDK_SINLINE bool UnloadStreamResources(StreamInfo* streamInfo) { return SDK_CALL_FUNC(bool, 0x22ED00, StreamInfo*)(streamInfo); }
	};
}