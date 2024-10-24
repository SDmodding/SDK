#pragma once

namespace Illusion
{
	class TargetPlat
	{
	public:
		s8 mResolveDepthSurface;
		s8 mHasDepthSurface;
		s8 mNumSurfaces;
		s8 mInvertedDepth;
		u16 mNumMips;
		D3D11_VIEWPORT mViewport;
		ID3D11RenderTargetView* mRenderTargetView[32][4];
		ID3D11DepthStencilView* mDepthStencilView;
		ID3D11DepthStencilView* mDepthStencilViewRO;
		Texture* mMSAATargetTexture[4];
		Texture* mMSAADepthTexture;
	};
	SDK_ASSERT_SIZEOF(TargetPlat, 0x458);
}