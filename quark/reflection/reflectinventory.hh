#pragma once

namespace UFG
{
	class qReflectInventoryBase : public qTreeNode64<qReflectInventoryBase>
	{
	public:
		struct NameLookup : public qTreeNode64<NameLookup>
		{
			const char* mName;
		};

		struct ObjectLookup : public qTreeNode64<ObjectLookup>
		{
			u64 mNameUID;
		};

		const char* mName;
		qTree64<qReflectObject> mItems;
		qTree64<NameLookup> mNameLookups;
		qTree64<ObjectLookup> mNameObjectLookups;
		qList<qReflectHandleBase> mUnBoundHandles[8];
		qReflectInventoryBase* mBaseClassInventory;
		qArray<qReflectInventoryBase*, 0> mDerivedInventories;
		f32 mAddTime;
		f32 mRemoveTime;
		f32 mUnresolvedTime;
		f32 mInitHandleTime;

		/* Virtual Functions */

		virtual u32 GetClassSize() = 0;
		virtual bool IsBaseClassOfThis(u64 type_uid) = 0;
	};
	SDK_ASSERT_SIZEOF(qReflectInventoryBase, 0x190);

	class qReflectWarehouse
	{
	public:
		qTree64<qReflectInventoryBase> mInventoryTree;

		/* Static Functions */

		SDK_SINLINE qReflectWarehouse* Instance() { return SDK_VAR(qReflectWarehouse*, 0x235BF30); }

		/* Functions */

		qReflectInventoryBase* GetInventory(u64 type) { return SDK_CALL_FUNC(qReflectInventoryBase*, 0x170B40, void*, u64)(this, type); }
	};
	SDK_ASSERT_SIZEOF(qReflectWarehouse, 0x38);
}