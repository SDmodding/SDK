#pragma once

namespace Illusion
{
	class TextureD3DResource : public UFG::qResourceData
	{
	public:
		D3D11_TEXTURE2D_DESC mDesc;
		ID3D11Resource* mGpuResource;
		ID3D11Resource* mStagingResource;
		u32 mStagingResourceInitialized;
		Illusion::TextureLockInfo* mDeferredContextTextureAccessBuffer;
		ID3D11ShaderResourceView* mShaderResourceView;
		u32 mNumberMipViews;
		ID3D11ShaderResourceView** mShaderResourceViewMips;
		ID3D11SamplerState* mSamplerState;
		ID3D11Resource* mDelayedReadCopy[5];
		int mRefCount;
		bool mAliased;
	};
	SDK_ASSERT_SIZEOF(TextureD3DResource, 0xF8);
}