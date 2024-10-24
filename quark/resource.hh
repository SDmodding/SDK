#pragma once

namespace UFG
{
	class qResourceData;

	//-------------------------------------------------------------------
	// Handle
	//-------------------------------------------------------------------

	class qResourceHandle : public qNode<qResourceHandle>
	{
	public:
		qResourceData* mData;
		u32 mNameUID;
		u32 mTailPad;

		qResourceHandle() : mData(0) {}
		~qResourceHandle() { SDK_CALL_FUNC(void, 0x164090, void*)(this); }

		/* Functions */

		void Init(u32 type_uid, u32 name_uid) { SDK_CALL_FUNC(void, 0x1734B0, void*, u32, u32)(this, type_uid, name_uid); }
		bool IsDefault() { return SDK_CALL_FUNC(bool, 0x1754B0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(qResourceHandle, 0x20);

	class qResourceFileHandle : public qResourceHandle
	{
	public:
		void(__fastcall* mCallback)(qResourceFileHandle*, bool, void*);
		void* mCallbackData;
	};

	class qGenericResourceHandle : public qResourceHandle
	{
	public:
		u32 mTypeUID;

		~qGenericResourceHandle() { SDK_CALL_FUNC(void, 0x2910, void*)(this); }
	};

	template <u32 type_uid, typename T>
	class qTypedResourceHandle : public qResourceHandle
	{
	public:
		SDK_INLINE T* GetData() { return reinterpret_cast<T*>(mData); }
	};

	//-------------------------------------------------------------------
	// Data
	//-------------------------------------------------------------------

	class qResourceData : public qNodeRB<qResourceData>
	{
	public:
		qList<qResourceHandle> mResourceHandles;
		u32 mTypeUID;
		char mDebugName[36];
	};
	SDK_ASSERT_SIZEOF(qResourceData, 0x58);
}