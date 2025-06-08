#pragma once

namespace UFG
{
	class qReflectObject;

	class qReflectHandleBase : public qNode<qReflectHandleBase>
	{
	public:
		u64 mTypeUID;
		u64 mNameUID;
		qReflectObject* mData;
	};

	template <typename T>
	class qReflectHandle : public qReflectHandleBase
	{
	public:
	};

	class qReflectObject : public qTreeNode64<qReflectObject>
	{
	public:
		u64 mTypeUID;
		qList<qReflectHandleBase> mHandles;

		virtual ~qReflectObject() = 0;
		virtual const char* GetTypeName() = 0;

		/* Functions */

		const char* GetName() { return SDK_CALL_FUNC(const char*, 0x1713D0, void*)(this); }
	};

	template <typename T, class U = qReflectObject>
	class qReflectObjectType : public U
	{
	public:
	};

}