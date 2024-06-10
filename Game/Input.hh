#pragma once

namespace UFG
{
	class CController
	{
	public:
		void* vfptr;
		bool mIsInitialized;
		bool mIsRemote;
		uint32_t mControllerIndex;

		UFG_PAD(0x20);

		struct InputState_t
		{
			uint64_t mLastMouseXYTime;
			short mMouseX;
			short mMouseY;
			short mMouseWheel;
			short mPrevMouseX;
			short mPrevMouseY;
			short mPrevMouseWheel;
			char mKeyState[256];

			void ClearKeyStates()
			{
				memset(mKeyState, 0, sizeof(mKeyState));
			}

			void Clear()
			{
				mLastMouseXYTime = 0;
				mMouseX = -1;
				mMouseY = -1;
				mMouseWheel = 0;
				mPrevMouseX = -1;
				mPrevMouseY = -1;
				mPrevMouseWheel = 0;
				ClearKeyStates();
			}
		};
		InputState_t mInputState;
		InputState_t mPreviousInputState;

		UFG_PAD(0x268);

		uint32_t mRightThumbServiceTick;
		void* mInputActionMaps[32];
		void* mMultiInputMaps[32];
		bool mInputActionMapEnable[32];
		bool mMultiInputMapEnable[32];
		float m_fTimeSinceLastInput;
		const uint32_t* m_pRemapArray;
		uint32_t m_ActiveMapSet;
		uint32_t m_SubModes;
		bool m_IsKeyboardController;
		bool m_ControllerInUse;
	};

	class CDxInputSystem
	{
	public:
		bool FreezeInputs;
		bool CheckForNewController;

		static CDxInputSystem* Instance()
		{
			return reinterpret_cast<CDxInputSystem*>(UFG_RVA(0x249CDE8));
		}
	};

	class CInputSystem
	{
	public:
		void* vfptr;
		CController* mControllers[5];
		bool mIsAssigned[5];
		bool mbSentDisconnectMsg;
		bool mbCheckForControllerDisconnect;
		int mKeyboardIndex;

		static UFG_INLINE CInputSystem* Instance()
		{
			return *reinterpret_cast<CInputSystem**>(UFG_RVA(0x235F860));
		}

		UFG_INLINE CController* AcquireController(int p_Index)
		{
			return reinterpret_cast<CController*(__fastcall*)(void*, int)>(UFG_RVA(0x1B6EB0))(this, p_Index);
		}
	};

	/* 
	* This is custom class, it doesn't exist in the main game
	* But those variables are under namespace in original code and in compiled binary they're under themself
	* so it was better to write custom class for this
	*/
	class CInputSystem001
	{
	public:
		bool ApplicationHasFocus;
		bool RelativeMouseMode;
		bool ShouldRestrictCursor;
		bool ShouldHideCursor;
		bool ShouldRestrictCursorGamepad[2];
		bool CursorCurrentlyRestricted;
		bool CursorCurrentlyHidden;
		bool ShouldRestrictCursorKeyboard[2];
		bool ForceSendMouseMsgs;
		bool MouseInputRawAvailable;
		bool ShouldHideCursorGamepad[2];
		bool ShouldHideCursorKeyboard[2];
		int SavedRestrictAndHideStackIndex;
		bool SavedRestrictAndHideSettings[32];
		int PCKeyboardSwapMode;

		static UFG_INLINE CInputSystem001* Instance()
		{
			return reinterpret_cast<CInputSystem001*>(UFG_RVA(0x235FB80));
		}

		UFG_INLINE void SetRestrictCursor(bool p_Value)
		{
			ShouldRestrictCursor = p_Value;
			ShouldRestrictCursorGamepad[0] = p_Value;
			ShouldRestrictCursorGamepad[1] = p_Value;
			ShouldRestrictCursorKeyboard[0] = p_Value;
			ShouldRestrictCursorKeyboard[1] = p_Value;
		}
	};

	class CInputActionData
	{
	public:
		unsigned int mButton;
		unsigned int mSignalType;
		void* mInputFunc;
		unsigned int mDebouncer;
		int mData0i;
		int mData1i;
		int mData2i;
		float mAxisPositionX;
		float mAxisPositionY;
		float mAxisRawX[3];
		float mAxisRawY[3];
		float mOnSeconds;
		float mOffSeconds;
		unsigned int mServicedFlag;
		bool mActionTrue;

		UFG_INLINE float GetAxisVelX() 
		{
			return mAxisRawX[0] - mAxisRawX[1]; }

		UFG_INLINE float GetAxisVelY() 
		{ 
			return mAxisRawY[0] - mAxisRawY[1];
		}
	};

	class CInputActionDef
	{
	public:
		CInputActionData* mDataPerController[5];
	};

	namespace Input
	{
		UFG_INLINE int GetActiveControllerNum()
		{
			return *reinterpret_cast<int*>(UFG_RVA(0x235FB78));
		}

		UFG_INLINE void EnableGameInput(bool p_Enable, bool* p_PrevEnable)
		{
			if (p_Enable && *p_PrevEnable) {
				return;
			}

			*p_PrevEnable = p_Enable;
			
			CDxInputSystem::Instance()->FreezeInputs = !p_Enable;
			CInputSystem001* _InputSystem001 = CInputSystem001::Instance();
			{
				_InputSystem001->ShouldHideCursor = p_Enable;
				_InputSystem001->SetRestrictCursor(p_Enable);
			}
		}

		UFG_INLINE CInputActionData* Get_Move()
		{ 
			return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4988))->mDataPerController[GetActiveControllerNum()]; 
		}

		UFG_INLINE CInputActionData* Get_Mouse()
		{
			return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x235FD50))->mDataPerController[GetActiveControllerNum()];
		}

		namespace Gamepad
		{
			UFG_INLINE bool IsActive()
			{
				CInputSystem* pInputSystem = CInputSystem::Instance();
				if (!pInputSystem) {
					return false;
				}

				CController* pController = pInputSystem->AcquireController(GetActiveControllerNum());
				if (pController && pController->m_IsKeyboardController) {
					return false;
				}

				return true;
			}

			UFG_INLINE CInputActionData* Get_CamMove() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E43C8))->mDataPerController[GetActiveControllerNum()];
			}
		}

		namespace Button
		{
			UFG_INLINE CInputActionData* Get_Left() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B0B0))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Left_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B0D8))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Right() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B128))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Right_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B150))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Up() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B1A0))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Up_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B1C8))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Down() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B218))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Down_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B240))->mDataPerController[GetActiveControllerNum()];
			}

			// Keyboard - Up Arrow
			UFG_INLINE CInputActionData* Get_EquipUp() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4E10))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_Fire() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4D20))->mDataPerController[GetActiveControllerNum()];
			}

			// Keyboard - H
			UFG_INLINE CInputActionData* Get_VehicleHorn_Start() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E47D0))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_VehicleHorn_Stop() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E47F8))->mDataPerController[GetActiveControllerNum()];
			}

			// Keyboard - Q
			UFG_INLINE CInputActionData* Get_VehicleActionHijack() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4F78))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_L1() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B5D8))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_L1_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B600))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_R1() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B740))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_R1_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B768))->mDataPerController[GetActiveControllerNum()];
			}

			// Keyboard - CTRL
			UFG_INLINE CInputActionData* Get_L2() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B650))->mDataPerController[GetActiveControllerNum()]; 
			}

			UFG_INLINE CInputActionData* Get_L2_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B678))->mDataPerController[GetActiveControllerNum()];
			}

			// Keyboard - SHIFT
			UFG_INLINE CInputActionData* Get_R2() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B7B8))->mDataPerController[GetActiveControllerNum()];
			}

			UFG_INLINE CInputActionData* Get_R2_Repeat() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B7E0))->mDataPerController[GetActiveControllerNum()];
			}

			// Keyboard - M (Cycle objectives)
			UFG_INLINE CInputActionData* Get_L3() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B6C8))->mDataPerController[GetActiveControllerNum()];
			}

			// Keyboard - E (Interact / Enter vehicle)
			UFG_INLINE CInputActionData* Get_Action() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4C30))->mDataPerController[GetActiveControllerNum()]; 
			}

			UFG_INLINE CInputActionData* Get_UIAccept() 
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B290))->mDataPerController[GetActiveControllerNum()]; 
			}

			UFG_INLINE CInputActionData* Get_UIBack()
			{ 
				return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B308))->mDataPerController[GetActiveControllerNum()]; 
			}
		}
	}
}