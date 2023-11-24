#pragma once

namespace UFG
{
	struct D3DGlobals_t
	{
		void* m_Device;
		void* m_DeviceCtx;
		void* m_DXGIFactory;
		void* m_DXGIAdapter;
		void* m_DXGIOutput;
		void* m_DXGIDevice;
		void* m_DXGISwapChain;

		static D3DGlobals_t* Get()
		{
			return reinterpret_cast<D3DGlobals_t*>(UFG_RVA(0x2439AE0));
		}
	};
}