#pragma once

namespace UFG
{
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x235FD50> ActionDef_Mouse;

	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E3D60> ActionDef_Right;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E3D88> ActionDef_Up;

	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E43C8> ActionDef_CamMoveHorizVert;		// Right Analog

	// Vehicle Horn (Keyboard: H)
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E47D0> ActionDef_HornStart;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E47F8> ActionDef_HornStop;

	// Move Character (Left Analog, WSAD)
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4988> ActionDef_MoveFwdBack;

	// Perform counter / fast-talk etc. (Keyboard: E)
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4C30> ActionDef_Action;

	// Grapple / Take Hostage / Pickup enemy (Hold)
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4C58> ActionDef_Grab;

	// Reload Weapon / Pickup Weapon
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4C80> ActionDef_Weapon;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4CA8> ActionDef_Attack;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4CD0> ActionDef_MeleeAttack;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4CF8> ActionDef_FirePartial;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4D20> ActionDef_Fire;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4D48> ActionDef_FireFull;

	// Phone Up (Keyboard: Up Arrow)
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4E10> ActionDef_EquipUP;

	// Perform Action HiJack from vehicle (Keyboard: Q)
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x23E4F78> ActionDef_VehicleActionHijack;

	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B0B0> ActionDef_UILeftPressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B0D8> ActionDef_UILeftRepeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B100> ActionDef_UILeftReleased;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B128> ActionDef_UIRightPressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B150> ActionDef_UIRightRepeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B178> ActionDef_UIRightReleased;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B1A0> ActionDef_UIUpPressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B1C8> ActionDef_UIUpRepeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B1F0> ActionDef_UIUpReleased;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B218> ActionDef_UIDownPressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B240> ActionDef_UIDownRepeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B268> ActionDef_UIDownReleased;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B290> ActionDef_UIAcceptPressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B2B8> ActionDef_UIAcceptRepeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B2E0> ActionDef_UIAcceptReleased;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B308> ActionDef_UIBackPressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B330> ActionDef_UIBackRepeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B358> ActionDef_UIBackReleased;

	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B5D8> ActionDef_UIL1Pressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B600> ActionDef_UIL1Repeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B628> ActionDef_UIL1Released;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B650> ActionDef_UIL2Pressed;			// Keyboard: CTRL
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B678> ActionDef_UIL2Repeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B6A0> ActionDef_UIL2Released;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B6C8> ActionDef_UIL3Pressed;			// Keyboard: M
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B6F0> ActionDef_UIL3Repeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B718> ActionDef_UIL3Released;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B740> ActionDef_UIR1Pressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B768> ActionDef_UIR1Repeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B790> ActionDef_UIR1Released;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B7B8> ActionDef_UIR2Pressed;			// Keyboard: Shift
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B7E0> ActionDef_UIR2Repeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B808> ActionDef_UIR2Released;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B830> ActionDef_UIR3Pressed;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B858> ActionDef_UIR3Repeat;
	SDK_VINLINE qGlobalVar<InputActionDef*, 0x249B880> ActionDef_UIR3Released;
}