#pragma once

namespace UFG
{
	class qReflectObject;

	class qReflectHandleBase
	{
	public:
		qNode<qReflectHandleBase> mNode;
		uint64_t mTypeUID;
		uint64_t mNameUID;
		qReflectObject* mData;

		UFG_INLINE qReflectHandleBase()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x161910))(this);
		}

		UFG_INLINE ~qReflectHandleBase()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x163F80))(this);
		}

		UFG_INLINE void Init(uint64_t p_TypeUID, uint64_t p_NameUID)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint64_t, uint64_t)>(UFG_RVA(0x173420))(this, p_TypeUID, p_NameUID);
		}
	};

	template <typename T>
	class qReflectHandle : public qReflectHandleBase
	{
	public:
		UFG_INLINE T* GetData()
		{
			return reinterpret_cast<T*>(mData);
		}
	};

	class qReflectObject
	{
	public:
		void* vfptr;
		qTreeNode64<qReflectObject> mNode;
		uint64_t mTypeUID;
		qList<qReflectHandle<qReflectObject>> mHandles;

		UFG_INLINE char* GetName()
		{
			return reinterpret_cast<char*(__fastcall*)(void*)>(UFG_RVA(0x1713D0))(this);
		}
	};

	template <typename T>
	class qReflectObjectType : public qReflectObject
	{
	public:
	};

	struct qReflectString
	{
		qReflectArray<char> mText;
	};

	//==================================================================

	class qReflectInventoryBase
	{
	public:
		void* vfptr;
		qTreeNode64<qReflectInventoryBase> mNode;
		const char* mName;
		qTree64<qReflectObject> mItems;
		// TODO: Do the rest of the members when needed.

		UFG_INLINE qReflectObject* FindObjectByName(const char* p_Name)
		{
			return reinterpret_cast<qReflectObject*(__fastcall*)(void*, const char*)>(UFG_RVA(0x16E110))(this, p_Name);
		}
	};

	class qReflectWarehouse
	{
	public:
		qTree64<qReflectInventoryBase> mInventoryTree;

		UFG_STATIC_INLINE qReflectWarehouse* Instance()
		{
			return reinterpret_cast<qReflectWarehouse*>(UFG_RVA(0x235BF30));
		}

		UFG_INLINE qReflectInventoryBase* GetInventory(uint64_t p_Type)
		{
			return reinterpret_cast<qReflectInventoryBase*(__fastcall*)(void*, uint64_t)>(UFG_RVA(0x170B40))(this, p_Type);
		}
	};
	UFG_ASSERT_CLASS(qReflectWarehouse, 0x38);
}