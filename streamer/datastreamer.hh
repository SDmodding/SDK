#pragma once

namespace UFG::DataStreamer
{
	class Handle;

	enum DISK_POS_SORT_MODE : s32
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

	enum PRIORITY : s32
	{
		VERY_LOW_PRIORITY = 0x0,
		LOW_PRIORITY = 0x1000,
		DEFAULT_PRIORITY = 0x2000,
		DEFAULT_ANIM_PRIORITY = 0x2000,
		HIGH_ANIM_PRIORITY = 0x2800,
		HIGH_PRIORITY = 0x3000,
		VERY_HIGH_PRIORITY = 0x4000,
	};

	enum STREAM_FLAGS : s32
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
		ALLOC_FROM_TOP = 256,
	};

	enum STREAM_STATE : s32
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

	/* Functions */

	SDK_SINLINE bool QueueStream(Handle& handle, const char* filename, int data_type, PRIORITY priority, STREAM_FLAGS flags, void* callback, void* callbackParam) {
		return SDK_CALL_FUNC(bool, 0x22C580, Handle&, const char*, int, PRIORITY, STREAM_FLAGS, void*, void*)(handle, filename, data_type, priority, flags, callback, callbackParam);
	}

	SDK_SINLINE bool QueueStream(Handle* handle, const char* filename, u32 mem_tag_qsymbol_uid, int data_type, PRIORITY priority, u32 flags, void* callback, void* callbackParam) {
		return SDK_CALL_FUNC(bool, 0x22C360, Handle*, const char*, u32, int, PRIORITY, u32, void*, void*)(handle, filename, mem_tag_qsymbol_uid, data_type, priority, flags, callback, callbackParam);
	}

	SDK_SINLINE bool ReleaseStream(Handle* handle) { return SDK_CALL_FUNC(char, 0x22CBE0, Handle*)(handle); }

	//----------------------------------------------------------------------
	//	Handle
	//----------------------------------------------------------------------

	class Handle : public qNode<Handle>
	{
	public:
		void(__fastcall* mCallback)(Handle*, void*);
		void* mCallbackParam;
		void* mImpl;
		u16 mFlags;
		qEnum<PRIORITY, u16> mPriority;
		qEnum<STREAM_STATE, u16> _mTargetState;

		Handle() : mCallback(0), mCallbackParam(0), mImpl(0), mFlags(DEFAULT), mPriority(DEFAULT_PRIORITY), _mTargetState(STATE_EMPTY) {}
		~Handle() { SDK_CALL_FUNC(void, 0x2271F0, void*)(this); }
	};
}