#pragma once

namespace UFG
{
	struct D3DGlobals_t
	{
		ID3D11Device* m_Device;
		ID3D11DeviceContext* m_DeviceCtx;
		IDXGIFactory1* m_DXGIFactory;
		IDXGIAdapter1* m_DXGIAdapter;
		IDXGIOutput* m_DXGIOutput;
		IDXGIDevice1* m_DXGIDevice;
		IDXGISwapChain* m_DXGISwapChain;

		static D3DGlobals_t* Get()
		{
			return reinterpret_cast<D3DGlobals_t*>(UFG_RVA(0x2439AE0));
		}
	};
}