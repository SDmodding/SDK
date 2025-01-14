#pragma once

namespace UFG
{
	class DxInputSystem : public InputSystem
	{
	public:
		IDirectInput8A* mDirectInput;
		HWND hWnd;

		/* Static Functions */

		SDK_SINLINE DxInputSystem* Instance() { return SDK_VAR_GET(DxInputSystem*, 0x235F860); }
	};
}