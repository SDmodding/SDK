#pragma once

namespace UFG
{
	enum eProfileType
	{
		eProfileType_MemoryPool,
		eProfileType_VRAMemoryPool,
		eProfileType_PassedIn,
		eProfileType_Count
	};

	class AllocationProfile : public qNode<AllocationProfile>
	{
	public:
		int mRefCount;
		eProfileType mProfileType;

		union
		{
			struct
			{
				qVRAMemoryPool* mPool;
				u32 mAlignment;
				i8 mFlags;
				i8 mUsage;
				i8 mFreeDelay;
			} mVRAMemoryPool;

			struct
			{
				u64 mAllocationParams;
				qMemoryPool* mPool;
			} mMemoryPool;

			struct
			{
				char* mMemoryLocation;
				u64 mLocationSize;
			} mPassedIn;
		} mMemory;

		/* Static Functions */

		AllocationProfile* CreateAllocationProfile(qMemoryPool* memory_pool, u64 allocation_params) {
			return SDK_CALL_FUNC(AllocationProfile*, 0x16AC80, qMemoryPool*, u64)(memory_pool, allocation_params);
		}

		AllocationProfile* CreateAllocationProfile(u8* memory_location, u64 location_size) {
			return SDK_CALL_FUNC(AllocationProfile*, 0x16AB80, u8*, u64)(memory_location, location_size);
		}
	};

	class LoadTableEntry : public qNode<LoadTableEntry>
	{
	public:
		AllocationProfile* mAllocationProfile;
		char* mScratchBuffer;
		u32 mScratchBufferSize;
		qString* mFilename;
		u32 mFilenameUID;
		ResourceFileContentType mContentType;
	};

	class ResourceMemoryHandle
	{
	public:
		qVRAMemoryHandle mVRAMemoryHandle;
		u64 mAllocationSize;
		void* mAllocateReturned;
		AllocationProfile* mAllocationProfile;

		/* Functions */

		u8* AllocateBuffer(u32 buffer_size, const char* allocation_name, u64 userdata64, u32 userdata32) {
			return SDK_CALL_FUNC(u8*, 0x1675F0, void*, u32, const char*, u64, u32)(this, buffer_size, allocation_name, userdata64, userdata32);
		}

		void FreeBuffer() { SDK_CALL_FUNC(void, 0x16EDF0, void*)(this); }
		u8* GetBuffer() { return SDK_CALL_FUNC(u8*, 0x16F4B0, void*)(this); }
		u64 GetBufferSize() { return SDK_CALL_FUNC(u64, 0x16F4E0, void*)(this); }
	};

	class ResourceLoadTable : public qNode<ResourceLoadTable>, public qNodeRB<ResourceLoadTable>
	{
	public:
		enum State
		{
			STATE_IDLE,
			STATE_LOADING,
			STATE_DELAYED_BUNDLE,
			STATE_UNLOADING,
			STATE_LOADED_CALLBACK,
			STATE_UNLOADED_CALLBACK,
			STATE_DELAYED_CALLBACK,
			STATE_LOADED
		};

		State mState;

		union
		{
			void(__fastcall* mFilename)(const char*, bool, void*);
			void(__fastcall* mFilenameUID)(unsigned int, bool, void*);
			void(__fastcall* mTable)(unsigned int, bool, void*);
		} mCallbacks;

		void* mCallbackParam;
		qList<LoadTableEntry> mTableEntries;
		volatile int mNumPendingLoads;
		u32 mTableUID;
		u32 mSingleFileUID;
		qMemoryPool* mMemoryPool;

		/* Functions */

		void Add(const char* filename, qMemoryPool* memory_pool, u64 allocation_params, u8* scratch_buffer, u32 scratch_buffer_size, ResourceFileContentType content_type) {
			SDK_CALL_FUNC(void, 0x1650D0, void*, const char*, qMemoryPool*, u64, u8*, u32, ResourceFileContentType)(this, filename, memory_pool, allocation_params, scratch_buffer, scratch_buffer_size, content_type);
		}

		bool CopyTableEntries(ResourceLoadTable* load_table) { return SDK_CALL_FUNC(bool, 0x16AA60, void*, ResourceLoadTable*)(this, load_table); }
	};


	class ResourceFile : public qResourceData, public qNode<ResourceFile>
	{
	public:
		enum State
		{
			STATE_IDLE,
			STATE_LOADING,
			STATE_LOADED,
			STATE_CANCELLED
		};

		ResourceMemoryHandle mMemoryHandle;
		i64 mValidDataSize;
		u32 mRefs;
		u32 mFileOperations;
		ResourceFile::State mState;
		qList<qValueNode<ResourceLoadTable*>> mWaitingLoadTables;
		void* mUserData;

		/* Functions */

		bool AddWaitingTable(ResourceLoadTable* load_table) { return SDK_CALL_FUNC(bool, 0x1669C0, void*, ResourceLoadTable*)(this, load_table); }
		bool NotifyWaitingTables() { return SDK_CALL_FUNC(bool, 0x1781F0, void*)(this); }
		void WarehouseLoad() { SDK_CALL_FUNC(void, 0x17FC80, void*)(this); }
		void WarehouseUnload() { SDK_CALL_FUNC(void, 0x17FD90, void*)(this); }
	};

	class qResourceFileInventory : public qResourceInventory
	{
	public:
		qList<ResourceFile> mZeroRefResourceFiles;

		/* Static Functions */

		SDK_SINLINE qResourceFileInventory* Instance() { return SDK_VAR_GET(qResourceFileInventory*, 0x235B000); }
	};

	class ExternallyLoadedChunk : public ResourceFile
	{
	public:
		/* Static Members */

		SDK_VINLINE qGlobalVar<int, 0x225A630> sLoadedChunkCount;
		SDK_VINLINE qGlobalVar<int, 0x225A634> sLoadedChunkTotal;

		/* Static Functions */

		SDK_SINLINE void AddNewChunk(u32 filename_uid, qVRAMemoryHandle& handle, void* user_data) {
			SDK_CALL_FUNC(void, 0x166490, u32, qVRAMemoryHandle&, void*)(filename_uid, handle, user_data);
		}

		SDK_SINLINE void AddNewChunk(u32 filename_uid, void* memory_location, u64 location_size, void* user_data) {
			SDK_CALL_FUNC(void, 0x166560, u32, void*, u64, void*)(filename_uid, memory_location, location_size, user_data);
		}

		SDK_SINLINE ExternallyLoadedChunk* FindExistingChunk(u32 filename_uid, u8* memory_location) {
			return SDK_CALL_FUNC(ExternallyLoadedChunk*, 0x16DDF0, u32, u8*)(filename_uid, memory_location);
		}

		SDK_SINLINE void RemoveExistingChunk(u32 filename_uid, qVRAMemoryHandle& handle) {
			SDK_CALL_FUNC(void, 0x17A830, u32, qVRAMemoryHandle&)(filename_uid, handle);
		}
	};
}