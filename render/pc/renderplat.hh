#pragma once

namespace Render
{
	SDK_INLINE Illusion::Target* GetBackBufferTarget() { return SDK_VAR_GET(Illusion::Target*, 0x2439A50); }
	SDK_INLINE Illusion::Target* GetPresentBufferTarget() { return SDK_VAR_GET(Illusion::Target*, 0x2439A68); }

	/* Custom Wrappers */

	SDK_INLINE bool IsFullscreen() { return SDK_VAR_GET(bool, 0x2439A42); }
	SDK_INLINE int GetScreenWidth() { return SDK_VAR_GET(int, 0x2439A94); }
	SDK_INLINE int GetScreenHeight() { return SDK_VAR_GET(int, 0x2439A98); }

	SDK_INLINE ID3D11Device* GetD3DDevice() { return SDK_VAR_GET(ID3D11Device*, 0x2439AE0); }
	SDK_INLINE ID3D11DeviceContext* GetD3DContext() { return SDK_VAR_GET(ID3D11DeviceContext*, 0x2439AE8); }
	SDK_INLINE IDXGISwapChain* GetDXGISwapChain() { return SDK_VAR_GET(IDXGISwapChain*, 0x2439B10); }
	SDK_INLINE ID3D11RenderTargetView* GetPresentRenderTargetView() { return SDK_VAR_GET(ID3D11RenderTargetView*, 0x2439B18); }
}