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

	class IStateSystem
	{
	public:
	};

	class StateSystem : public IStateSystem
	{
	public:
		StateParamDesc mStateParamDescs[128];
		StateParamLookup mStateParamLookup[128];
		int mCurrentParamIndex;

		/* Static Functions */

		SDK_SINLINE StateSystem* Instance() { return SDK_VAR(StateSystem*, 0x2167B40); }

		/* Functions */

		u32 GetParam(u32 uid) { return SDK_CALL_FUNC(u32, 0x923B0, void*, u32)(this, uid); }
		u32 GetParam(const char* name) { return SDK_CALL_FUNC(u32, 0x92420, void*, const char*)(this, name); }
	};
}