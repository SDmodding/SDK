#pragma once

namespace UFG
{
	class qResourceData;
	class qResourceInventory;

	class qChunk
	{
	public:
		u32 mUID;
		u32 mChunkSize;
		u32 mDataSize;
		u32 mDataOffset;
	};

	//------------------------
	//	Handle
	//------------------------

	class qResourceHandle : public qNode<qResourceHandle>
	{
	public:
		qResourceData* mData;
		u32 mNameUID;
		u32 mTailPad;

		qResourceHandle() : mData(0) {}
		~qResourceHandle() { SDK_CALL_FUNC(void, 0x164090, void*)(this); }

		/* Functions */

		void Close(qResourceInventory* inventory) { SDK_CALL_FUNC(void, 0x167F40, void*, qResourceInventory*)(this, inventory); }
		void Close() { SDK_CALL_FUNC(void, 0x167FB0, void*)(this); }
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

	//------------------------
	//	Data
	//------------------------

	class qResourceData : public qNodeRB<qResourceData>
	{
	public:
		qList<qResourceHandle> mResourceHandles;
		u32 mTypeUID;
		char mDebugName[36];

		/* Functions */

		void SetDebugName(const char* name) { SDK_CALL_FUNC(void, 0x17CD40, void*, const char*)(this, name); }
	};
	SDK_ASSERT_SIZEOF(qResourceData, 0x58);

	//------------------------
	//	Inventory
	//------------------------

	class qResourceInventory : public qNodeRB<qResourceInventory>, public qNode<qResourceInventory>
	{
	public:
		u32 mDefaultResourceNameUID;
		u32 mChunkUID;
		const char* mName;
		qResourceData* mDefaultResourceData;
		qTreeRB<qResourceData> mResourceDatas;
		qList<qResourceHandle> mNullHandles;
		qList<qResourceHandle> mInternalUnresolvedHandles[4];
		qList<qResourceHandle>* mUnresolvedHandleLists;
		u32 mNumUnresolvedHandleLists;
		u32 mNumResourceData;
		u32 mNumResourceBytes;
		u32 mTransactionNum;
		u32 mLastUpdate;
		f32 mAddTime;
		f32 mRemoveTime;
		f32 mUnresolvedTime;
		f32 mLoadTime;
		f32 mUnloadTime;
		f32 mInitHandleTime;

		/* Virtual Functions */

		virtual void InitHandle(qResourceHandle* handle, u32 name_uid) = 0;
		virtual void InitHandle(qResourceHandle* handle, u32 name_uid, qResourceData* data) = 0;
		virtual void OnAttachHandle(qResourceHandle* handle, qResourceData* data) = 0;
		virtual void OnDetachHandle(qResourceHandle* handle, qResourceData* data) = 0;
		virtual void OnPreMove(qResourceData* resourceData) = 0;
		virtual void OnPostMove(qResourceData* resourceData) = 0;
		virtual void Init() = 0;
		virtual void Close() = 0;
		virtual bool IsEmpty() = 0;
		virtual void Add(qResourceData* data) = 0;
		virtual void Remove(qResourceData* data) = 0;
		virtual qResourceData* Get(u32 name_uid) = 0;
		virtual qResourceData* DebugGet(const char* name) = 0;
		virtual bool Load(qChunk* chunk) = 0;
		virtual bool Unload(qChunk* chunk) = 0;
		virtual bool PreMove(qChunk* chunk) = 0;
		virtual bool PostMove(qChunk* chunk) = 0;
		virtual bool Validate() = 0;
		virtual void PrintContents() = 0;
	};
	SDK_ASSERT_SIZEOF(qResourceInventory, 0x120);

	//------------------------
	//	Warehouse
	//------------------------

	class qResourceWarehouse
	{
	public:
		qTreeRB<qResourceInventory> mInventoryTree;
		qList<qResourceInventory> mInventoryList;
		qResourceInventory* mLastInventory;
		u32 mLastTypeUID;
		int mNumInventories;
		f32 mAddTime;
		f32 mRemoveTime;
		f32 mUnresolvedTime;
		f32 mLoadTime;
		f32 mUnloadTime;

		/* Static Functions */

		SDK_SINLINE qResourceWarehouse* Instance() { return SDK_VAR(qResourceWarehouse*, 0x235B2F0); }

		/* Functions */

		void Add(qResourceData* data) { SDK_CALL_FUNC(void, 0x165B60, void*, qResourceData*)(this, data); }
		qResourceData* DebugGet(u32 type_uid, u32 name_uid) { return SDK_CALL_FUNC(qResourceData*, 0x16B980, void*, u32, u32)(this, type_uid, name_uid); }
		qResourceInventory* GetInventory(u32 type_uid) { return SDK_CALL_FUNC(qResourceInventory*, 0x170B80, void*, u32)(this, type_uid); }
		void Load(void* buffer, u32 num_bytes) { SDK_CALL_FUNC(void, 0x176B50, void*, void*, u32)(this, buffer, num_bytes); }
		void Remove(qResourceData* data) { SDK_CALL_FUNC(void, 0x17A530, void*, qResourceData*)(this, data); }
		void Unload(void* buffer, u32 num_bytes) { SDK_CALL_FUNC(void, 0x17F180, void*, void*, u32)(this, buffer, num_bytes); }
	};
	SDK_ASSERT_SIZEOF(qResourceWarehouse, 0x80);
}