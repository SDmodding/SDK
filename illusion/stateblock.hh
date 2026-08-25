#pragma once

namespace Illusion
{
	class StateBlock : public UFG::qResourceData, public UFG::qNode<StateBlock>
	{
	public:
		struct StateBlockHeader
		{
			u16 dataOffset;
			u16 size;
		};

		u32 mParentUID;
		u32 mDataByteSize;
		u32 mNumValues;
		u32 mNameUID;

		/* Impl Functions */

		SDK_INLINE char* GetBlockData() { return reinterpret_cast<char*>(this) + UFG::qAlignUp<uptr>(sizeof(*this), 16); }
		SDK_INLINE StateBlockHeader* GetBlockHeader() { return reinterpret_cast<StateBlockHeader*>(GetBlockData() + UFG::qAlignUp<u32>(mDataByteSize, 16)); }

		// Legacy alias, use GetBlockData() instead
		SDK_INLINE char* GetStateData() { return GetBlockData(); }
	};

	class StateBlockHandle : public UFG::qTypedResourceHandle<RTypeUID_StateBlock, StateBlock> {};

	class StateBlockCurve
	{
	public:
		struct StateBlockKey
		{
			f32 fTime;
			f32 fValue;
		};

		u32 numKeys;

		// Helpers

		StateBlockKey* keys() { return reinterpret_cast<StateBlockKey*>(this + 1); }
		const StateBlockKey* keys() const { return reinterpret_cast<const StateBlockKey*>(this + 1); }
	};

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