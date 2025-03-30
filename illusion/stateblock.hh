#pragma once

namespace Illusion
{
	class StateBlock : public UFG::qResourceData, public UFG::qNode<StateBlock>
	{
	public:
		u32 mParentUID;
		u32 mDataByteSize;
		u32 mNumValues;
		u32 mNameUID;

		/* Impl Functions */

		// Use this with caution!
		SDK_INLINE char* GetStateData() { return reinterpret_cast<char*>(reinterpret_cast<uptr>(this) + 0x80); } // sizeof(StateBlock) aligned at 0x10 bytes
	};

	class StateBlockHandle : public UFG::qTypedResourceHandle<RTypeUID_StateBlock, StateBlock> {};

	class StateBlockInventory : public UFG::qResourceInventory
	{
	public:
		UFG::qList<StateBlock> mBlockList;

		/* Static Functions */

		SDK_SINLINE StateBlockInventory* Instance() { return SDK_VAR(StateBlockInventory*, 0x2167130); }

		/* Functions */

		StateBlock* GetStateBlock(u32 name_uid, bool return_default_data = 1) { return SDK_CALL_FUNC(StateBlock*, 0x92690, void*, u32, bool)(this, name_uid, return_default_data); }
	};
}