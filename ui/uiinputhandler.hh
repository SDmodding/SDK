#pragma once

namespace UFG
{
	enum eUIInputHandlerState : u32
	{
		UIINPUT_IDLE,
		UIINPUT_FIRST_REPEAT,
		UIINPUT_REPEATED_INPUT,
		UIINPUT_NUM_STATES
	};

	class UIInputHandler
	{
	public:
		f32 mAnalogDeadZone;
		f32 mFirstDelay;
		f32 mMaxRepeatDelay;
		f32 mMinRepeatDelay;
		f32 mRepeatSpeed;
		f32 mRepeatDelay[5];
		f32 mCurrentDelay[5][2];
		eUIInputHandlerState mState[5][2];
		u32 mLastAnalogValue[5];
		qVector2 mLeftAnalogStick[5];
		qVector2 mRightAnalogStick[5];
	};
}