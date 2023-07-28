#pragma once

namespace UFG
{
	namespace Global
	{
		uintptr_t WndProc = UFG_RVA(0x6A2770);
		void** D3D11Device = reinterpret_cast<void**>(UFG_RVA(0x2439AE0));
		void** D3D11DeviceContext = reinterpret_cast<void**>(UFG_RVA(0x2439AE8));
		void** DXGIDevice = reinterpret_cast<void**>(UFG_RVA(0x2439B08));
		void** DXGISwapChain = reinterpret_cast<void**>(UFG_RVA(0x2439B10));
		HWND* Window = reinterpret_cast<HWND*>(UFG_RVA(0x249CDF0));
	}
}