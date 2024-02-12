#pragma once

namespace UFG
{
	template <typename T>
	class qReflectHandle
	{
	public:
		qNode<qReflectHandle<T>> mNode;
		uint64_t mTypeUID;
		uint64_t mNameUID;
		T* mData;

		qReflectHandle()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x161910))(this);
		}

		~qReflectHandle()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x163F80))(this);
		}

		void Init(uint64_t p_TypeUID, uint64_t p_NameUID)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint64_t, uint64_t)>(UFG_RVA(0x173420))(this, p_TypeUID, p_NameUID);
		}
	};

	class qReflectObject
	{
	public:
		void* vfptr;
		qTreeNode64 mNode;
		uint64_t mTypeUID;
		qList<qReflectHandle<qReflectObject>> mHandles;

		char* GetName()
		{
			return reinterpret_cast<char*(__fastcall*)(void*)>(UFG_RVA(0x1713D0))(this);
		}
	};

	struct qReflectString
	{
		qReflectArray<char> mText;
	};

}