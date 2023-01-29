#pragma once

namespace UFG
{
	class CController
	{
	public:
		UFG_PAD(0x728);

		bool m_IsKeyboardController;
		bool m_ControllerInUse;
	};

	class CDxInputSystem
	{
	public:
		bool FreezeInputs;
		bool CheckForNewController;
	};
	CDxInputSystem* DxInputSystem = reinterpret_cast<CDxInputSystem*>(UFG_RVA(0x249CDE8));

	class CInputSystem
	{
	public:
		void* vfptr;
		CController* mControllers[5];
		bool mIsAssigned[5];
		bool mbSentDisconnectMsg;
		bool mbCheckForControllerDisconnect;
		int mKeyboardIndex;

		CController* AcquireController(int index)
		{
			return reinterpret_cast<CController*(__fastcall*)(void*, int)>(UFG_RVA(0x1B6EB0))(this, index);
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

		void SetRestrictCursor(bool m_bValue)
		{
			ShouldRestrictCursor = m_bValue;
			ShouldRestrictCursorGamepad[0] = m_bValue;
			ShouldRestrictCursorGamepad[1] = m_bValue;
			ShouldRestrictCursorKeyboard[0] = m_bValue;
			ShouldRestrictCursorKeyboard[1] = m_bValue;
		}
	};
	CInputSystem001* InputSystem001 = reinterpret_cast<CInputSystem001*>(UFG_RVA(0x235FB80));

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

		float GetAxisVelX() { return mAxisRawX[0] - mAxisRawX[1]; }

		float GetAxisVelY() { return mAxisRawY[0] - mAxisRawY[1]; }
	};

	class CInputActionDef
	{
	public:
		CInputActionData* mDataPerController[5];
	};

	namespace Input
	{
		CInputSystem* Get()
		{
			return *reinterpret_cast<CInputSystem**>(UFG_RVA(0x235F860));
		}

		void EnableGameInput(bool m_bValue)
		{
			static bool m_bLastValue = true;
			if (m_bValue && m_bLastValue) return;
			
			m_bLastValue = m_bValue;
			{
				DxInputSystem->FreezeInputs = !m_bValue;
				InputSystem001->ShouldHideCursor = m_bValue;

				InputSystem001->SetRestrictCursor(m_bValue);
			}
		}

		int GetActiveControllerNum()
		{
			return *reinterpret_cast<int*>(UFG_RVA(0x235FB78));
		}

		CInputActionData* Get_Move() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4988))->mDataPerController[GetActiveControllerNum()]; }

		CInputActionData* Get_Mouse() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x235FD50))->mDataPerController[GetActiveControllerNum()]; }

		namespace Gamepad
		{
			bool IsActive()
			{
				CController* m_Controller = Get()->AcquireController(GetActiveControllerNum());
				if (m_Controller && m_Controller->m_IsKeyboardController)
					return false;

				return true;
			}

			CInputActionData* Get_CamMove() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E43C8))->mDataPerController[GetActiveControllerNum()]; }
		}

		namespace Button
		{
			CInputActionData* Get_Left() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B0B0))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_Left_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B0D8))->mDataPerController[GetActiveControllerNum()]; }

			CInputActionData* Get_Right() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B128))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_Right_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B150))->mDataPerController[GetActiveControllerNum()]; }

			CInputActionData* Get_Up() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B1A0))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_Up_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B1C8))->mDataPerController[GetActiveControllerNum()]; }

			CInputActionData* Get_Down() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B218))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_Down_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B240))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - Up Arrow
			CInputActionData* Get_EquipUp() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4E10))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - H
			CInputActionData* Get_VehicleHorn_Start() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E47D0))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_VehicleHorn_Stop() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E47F8))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - Q
			CInputActionData* Get_VehicleActionHijack() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4F78))->mDataPerController[GetActiveControllerNum()]; }

			CInputActionData* Get_L1() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B5D8))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_L1_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B600))->mDataPerController[GetActiveControllerNum()]; }

			CInputActionData* Get_R1() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B740))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_R1_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B768))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - CTRL
			CInputActionData* Get_L2() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B650))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_L2_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B678))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard SHIFT
			CInputActionData* Get_R2() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B7B8))->mDataPerController[GetActiveControllerNum()]; }
			CInputActionData* Get_R2_Repeat() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B7E0))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - M (Cycle objectives)
			CInputActionData* Get_L3() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B6C8))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - E (Interact / Enter vehicle)
			CInputActionData* Get_Action() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4C30))->mDataPerController[GetActiveControllerNum()]; }


			CInputActionData* Get_UIAccept() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B290))->mDataPerController[GetActiveControllerNum()]; }

			CInputActionData* Get_UIBack() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B308))->mDataPerController[GetActiveControllerNum()]; }
		}
	}
}