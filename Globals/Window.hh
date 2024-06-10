#pragma once

namespace UFG
{
	namespace Global
	{
		UFG_INLINE HWND GetWindowHandle()
		{
			return *reinterpret_cast<HWND*>(UFG_RVA(0x249CDF0));
		}
	}
}