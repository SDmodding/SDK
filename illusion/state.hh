#pragma once

namespace Illusion
{
	class StateValues
	{
	public:
		UFG::BitFlags128 mSetValueMask;
		void* mParamValues[128];
	};

	class StateParam
	{
	public:
		u32 mNameUID;
		u32 mTypeUID;
		s16 mParamIndex;
		s16 pad0;
	};

	class StateParamDesc : public StateParam
	{
	public:
		s8 mName[63];
		s8 mIsResourceData;
	};

	class StateParamLookup
	{
	public:
		u32 mNameUID;
		u32 mParamIndex;
	};
}