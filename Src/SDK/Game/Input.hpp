#pragma once

namespace UFG
{
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
	CInputSystem* InputSystem = reinterpret_cast<CInputSystem*>(UFG_RVA(0x235FB80));

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
	};

	class CInputActionDef
	{
	public:
		CInputActionData* mDataPerController[5];
	};

	namespace Input
	{
		void EnableGameInput(bool m_bValue)
		{
			static bool m_bLastValue = true;
			if (m_bValue && m_bLastValue) return;
			
			m_bLastValue = m_bValue;
			{
				DxInputSystem->FreezeInputs = !m_bValue;
				InputSystem->ShouldHideCursor = m_bValue;

				InputSystem->SetRestrictCursor(m_bValue);
			}
		}

		unsigned int GetActiveControllerNum()
		{
			return *reinterpret_cast<unsigned int*>(UFG_RVA(0x235FB78));
		}

		namespace Button
		{
			// Keyboard - Q
			CInputActionData* Get_VehicleActionHijack() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4F78))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - M (Cycle objectives)
			CInputActionData* Get_L3() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x249B6C8))->mDataPerController[GetActiveControllerNum()]; }

			// Keyboard - E (Interact / Enter vehicle)
			CInputActionData* Get_Action() { return reinterpret_cast<CInputActionDef*>(UFG_RVA(0x23E4C30))->mDataPerController[GetActiveControllerNum()]; }
		}
	}
}