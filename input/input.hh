#pragma once

SDK_VINLINE qGlobalVar<bool, 0x249CDE8> gFreezeInputs;

namespace UFG
{
	SDK_VINLINE qGlobalVar<u32, 0x235FB78> gActiveControllerNum;

	class Controller;

	enum InputMouseButtons
	{
		MOUSE_NONE,
		MOUSE_LBUTTON = 1,
		MOUSE_RBUTTON = 2,
		MOUSE_MBUTTON = 4,
		MOUSE_XBUTTON1 = 8,
		MOUSE_XBUTTON2 = 16
	};

	enum InputMKeys : i32
	{
		MKEY_NONE,
		MKEY_SHIFT,
		MKEY_CONTROL,
		MKEY_CONTROL_SHIFT,
		MKEY_ALT,
		MKEY_ALT_SHIFT,
		MKEY_ALT_CONTROL,
		MKEY_ALT_CONTROL_SHIFT,
		MKEY_WIN,
		MKEY_APPS = 16
	};

	enum eSignalType : i32
	{
		OFF,
		ON,
		RISING_EDGE,
		FALLING_EDGE,
		AXIS,
		HOLD_THEN_FLICK,
		ON_50,
		RISING_50,
		FALLING_45,
		ON_95,
		RISING_95,
		FALLING_90
	};

	class RawPadData
	{
	public:
		u16 mGetXIState_Gamepad_wButtons;
		int mGetState_lRx;
		int mGetState_lRy;
		int mGetState_lRz;
		int mGetState_lX;
		int mGetState_lY;
		int mGetState_lZ;
		s16 mGetXIState_Gamepad_sThumbLX;
		s16 mGetXIState_Gamepad_sThumbLY;
		s16 mGetXIState_Gamepad_sThumbRX;
		s16 mGetXIState_Gamepad_sThumbRY;
		s8 mGetXIState_Gamepad_bLeftTrigger;
		s8 mGetXIState_Gamepad_bRightTrigger;
		u32 mGetState_rgdwPOV0;
	};

	class InputActionData
	{
	public:
		u32 mButton;
		eSignalType mSignalType;
		void(__fastcall* mInputFunc)(Controller*, InputActionData*, float);
		u32 mDebouncer;
		int mData0i;
		int mData1i;
		int mData2i;
		f32 mAxisPositionX;
		f32 mAxisPositionY;
		f32 mAxisRawX[3];
		f32 mAxisRawY[3];
		f32 mOnSeconds;
		f32 mOffSeconds;
		u32 mServicedFlag;
		bool mActionTrue;

		/* Functions */

		SDK_INLINE f32 GetAxisVelX() { return mAxisRawX[0] - mAxisRawX[1]; }
		SDK_INLINE f32 GetAxisVelY() { return mAxisRawY[0] - mAxisRawY[1]; }
	};

	class InputState
	{
	public:
		u64 mLastMouseXYTime;
		i16 mMouseX;
		i16 mMouseY;
		i16 mMouseWheel;
		i16 mPrevMouseX;
		i16 mPrevMouseY;
		i16 mPrevMouseWheel;
		i8 mKeyState[256];

		/* Impl Functions */

		SDK_INLINE short GetMouseDeltaX() { return mMouseX - mPrevMouseX; }
		SDK_INLINE short GetMouseDeltaY() { return mMouseY - mPrevMouseY; }
		SDK_INLINE f32 GetMouseWheelDelta() { return static_cast<float>(mMouseWheel - mPrevMouseWheel) * (1.f / 120.f); }
		SDK_INLINE int GetRepeatCount(int key) { return mKeyState[key] & SCHAR_MAX; }
		SDK_INLINE bool IsMouseVisible() { return mMouseX != -1; }

		/* Functions */

		void Clear() { SDK_CALL_FUNC(void, 0x1B7420, void*)(this); }
		InputMKeys GetModiferKeys() { return SDK_CALL_FUNC(InputMKeys, 0x1B79F0, void*)(this); }
		InputMouseButtons GetMouseButtons() { return SDK_CALL_FUNC(InputMouseButtons, 0x1B7AC0, void*)(this); }
		bool IsPressed(int key) { return SDK_CALL_FUNC(bool, 0xA3CC70, void*, int)(this, key); }
	};

	class InputMessage : public qNode<InputMessage>
	{
	public:
		i8 mMessageID;
		i8 mVKey;
		u16 mMouseX;
		u16 mMouseY;
		u16 mMouseWheelDelta;
		u32 mChar;
	};

	class JoyInputHistory : public qNode<JoyInputHistory>
	{
	public:
		struct OctantData
		{
			int mOctant;
			f32 mDuration;
		};

		int mEndTrim;
		int mStartTrim;
		bool mLocked;
		f32 mR[64];
		f32 mTheta[64];
		int mIndex;
		int mValidHistorySize;
		OctantData mOctantHistory[8];
		int mOctantIndex;
	};

	class InputActionDef
	{
	public:
		InputActionData* mDataPerController[5];

		SDK_INLINE InputActionData* GetData(int controller = gActiveControllerNum) { return mDataPerController[controller]; }
	};

	class ActionRemapInfo : public qNode<ActionRemapInfo>
	{
	public:
		InputActionDef* pActionDef[3];
		u32 mEntryId;
		int mDefaultButton;
		int mButton;
	};

	class InputActionMapInfo
	{
	public:
		InputActionDef* pActionDef;
		u32 mButtonDef;
		eSignalType mSignalType;
		void(__fastcall* mInputFunc)(Controller*, InputActionData*, float);
	};

	class InputActionMap
	{
	public:
		InputActionMapInfo* mActionMapInfoArray;
		u32 mNumEntries;
		bool mUpdateWhenSimPaused;
	};

	class MultiInputNode
	{
	public:
		int mNumActionsCombined;
		InputActionDef* mActions[3];
		f32 mMinHoldTime;
		f32 mMaxHoldTime;
		f32 mStartTime;
		f32 mEndTime;
	};

	class CompoundAction
	{
	public:
		InputActionDef* mActionDefName;
		int mNumNodes;
		int mShouldDebounce;
		MultiInputNode mActionNodes[6];
	};

	class MultiInputMap
	{
	public:
		CompoundAction* mCompoundDefinitions;
		int mNumEntries;
	};

	//-----------------------------------------------
	//	Controller
	//-----------------------------------------------

	class Controller
	{
	public:
		bool mIsInitialized;
		bool mIsRemote;
		u32 mControllerIndex;
		qList<InputMessage> mInputMessages;
		qList<ActionRemapInfo> mRemappableActions;
		InputState mInputState;
		InputState mPreviousInputState;
		JoyInputHistory mJoyInputHistory;
		u32 mRightThumbServiceTick;
		InputActionMap* mInputActionMaps[32];
		MultiInputMap* mMultiInputMaps[32];
		bool mInputActionMapEnable[32];
		bool mMultiInputMapEnable[32];
		f32 m_fTimeSinceLastInput;
		const u32* m_pRemapArray;
		u32 m_ActiveMapSet;
		u32 m_SubModes;
		bool m_IsKeyboardController;
		bool m_ControllerInUse;

		/* Virtual Functions */

		virtual u16 RawPadDataSize() = 0;
		virtual RawPadData* ReadRawPadData() = 0;
		virtual void SetRawPadData(const void* prpd) = 0;
		virtual ~Controller() = 0;
		virtual void Update(float elapsedTime, const float simTime) = 0;
		virtual bool IsConnected() = 0;
		virtual bool HasRumbleSupport() = 0;

		/* Functions */

		void AddActionToRemappableList(InputActionDef* actionDef, u32 id, InputActionDef* actionDef_2, InputActionDef* actionDef_3) { 
			SDK_CALL_FUNC(void, 0x1B6F10, void*, InputActionDef*, u32, InputActionDef*, InputActionDef*)(this, actionDef, id, actionDef_2, actionDef_3); 
		}

		void AddInputActionMap(InputActionMap& actionMap, const u32& pRemapArray) { SDK_CALL_FUNC(void, 0x1B7110, void*, InputActionMap&, const u32&)(this, actionMap, pRemapArray); }
		void AddMultiInputMap(MultiInputMap& multiMap) { SDK_CALL_FUNC(void, 0x1B7290, void*, MultiInputMap&)(this, multiMap); }
		void ApplyRemapList() { SDK_CALL_FUNC(void, 0x1B73C0, void*)(this); }
		void CreateMapDataStructures() { SDK_CALL_FUNC(void, 0x1B7450, void*)(this); }
		void CreateSingleMapStructure(int index) { SDK_CALL_FUNC(void, 0x1B74B0, void*, int)(this, index); }
		void CreateSingleMultiMapStruct(int index) { SDK_CALL_FUNC(void, 0x1B75D0, void*, int)(this, index); }
		void DeleteMapDataStructures() { SDK_CALL_FUNC(void, 0x1B76C0, void*)(this); }
		void DisableAllMaps() { SDK_CALL_FUNC(void, 0x1B77B0, void*)(this); }
		int DisableInputActionMap(InputActionMap& actionMap) { return SDK_CALL_FUNC(int, 0x1B78F0, void*, InputActionMap&)(this, actionMap); }
		int EnableInputActionMap(InputActionMap& actionMap) { return SDK_CALL_FUNC(int, 0x1B7990, void*, InputActionMap&)(this, actionMap); }
		void ResetRemapList() { SDK_CALL_FUNC(void, 0x1B8EA0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(Controller, 0x730);

	//-----------------------------------------------
	//	InputSystem
	//-----------------------------------------------

	class InputSystem
	{
	public:
		Controller* mControllers[5];
		bool mIsAssigned[5];
		bool mbSentDisconnectMsg;
		bool mbCheckForControllerDisconnect;
		int mKeyboardIndex;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x235FB80> msApplicationHasFocus;
		SDK_VINLINE qGlobalVar<bool, 0x235FB81> msRelativeMouseMode;
		SDK_VINLINE qGlobalVar<bool, 0x235FB82> msShouldRestrictCursor;
		SDK_VINLINE qGlobalVar<bool, 0x235FB83> msShouldHideCursor;
		SDK_VINLINE qGlobalArray<bool, 2, 0x235FB84> msShouldRestrictCursorGamepad;
		SDK_VINLINE qGlobalVar<bool, 0x235FB86> msCursorCurrentlyRestricted;
		SDK_VINLINE qGlobalVar<bool, 0x235FB87> msCursorCurrentlyHidden;
		SDK_VINLINE qGlobalArray<bool, 2, 0x235FB88> msShouldRestrictCursorKeyboard;
		SDK_VINLINE qGlobalVar<bool, 0x235FB8A> msForceSendMouseMsgs;
		SDK_VINLINE qGlobalVar<bool, 0x235FB8B> msMouseInputRawAvailable;
		SDK_VINLINE qGlobalArray<bool, 2, 0x235FB8C> msShouldHideCursorGamepad;
		SDK_VINLINE qGlobalArray<bool, 2, 0x235FB90> msShouldHideCursorKeyboard;
		SDK_VINLINE qGlobalVar<int, 0x235FB94> msSavedRestrictAndHideStackIndex;
		SDK_VINLINE qGlobalArray<bool, 32, 0x235FB98> msSavedRestrictAndHideSettings;
		SDK_VINLINE qGlobalVar<int, 0x235FBB8> msPCKeyboardSwapMode;

		/* Virtual Functions */

		virtual ~InputSystem() = 0;
		virtual int CreateNewGamePad(int index) = 0;
		virtual void Update(float elapsedTime, float simTime) = 0;

		/* Static Functions */

		SDK_SINLINE InputSystem* Instance() { return SDK_VAR_GET(InputSystem*, 0x235F860); }
		SDK_SINLINE void PushRestrictAndHideSettings() { SDK_CALL_FUNC(void, 0x1B8DD0)(); }
		SDK_SINLINE void PopRestrictAndHideSettings() { SDK_CALL_FUNC(void, 0x1B8B30)(); }

		SDK_SINLINE void SetShouldHideCursor(bool b_gamepad_window, bool b_keyboard_window, bool b_gamepad_fullscreen, bool b_keyboard_fullscreen) {
			SDK_CALL_FUNC(void, 0x1B9030, bool, bool, bool, bool)(b_gamepad_window, b_keyboard_window, b_gamepad_fullscreen, b_keyboard_fullscreen);
		}

		SDK_SINLINE void SetShouldRestrictCursor(bool b_gamepad_window, bool b_keyboard_window, bool b_gamepad_fullscreen, bool b_keyboard_fullscreen) {
			SDK_CALL_FUNC(void, 0x1B9050, bool, bool, bool, bool)(b_gamepad_window, b_keyboard_window, b_gamepad_fullscreen, b_keyboard_fullscreen);
		}
		/* Functions */

		Controller* AcquireController(int index) { return SDK_CALL_FUNC(Controller*, 0x1B6EB0, void*, int)(this, index); }

	};
	SDK_ASSERT_SIZEOF(InputSystem, 0x40);
}