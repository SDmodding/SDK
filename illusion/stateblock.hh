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
	};


	class StateBlockHandle : public UFG::qTypedResourceHandle<RTypeUID_StateBlock, StateBlock> {};
}