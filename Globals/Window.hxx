#pragma once

namespace UFG
{
	namespace Global
	{
		HWND GetWindowHandle()
		{
			return *reinterpret_cast<HWND*>(UFG_RVA(0x249CDF0));
		}
	}
}