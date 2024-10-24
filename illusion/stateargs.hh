#pragma once

namespace Illusion
{
	class StateArg : public UFG::qNode<StateArg>
	{
	public:
		void(__fastcall* mCallback)(StateArg*, StateValues*);
		s16 mStateParamIndex;
		s8 mFlags;
		s8 mIsSet;
	};

	class StateArgs
	{
	public:
		UFG::BitFlags128 mStateArgsCreateMask;
		UFG::BitFlags128 mStateParamModelFreqMask;
		UFG::BitFlags128 mStateParamMeshFreqMask;
		UFG::qList<StateArg> mStateArgs[128];
	};
	SDK_ASSERT_SIZEOF(StateArgs, 0x830);
}