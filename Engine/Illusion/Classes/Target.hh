#pragma once

namespace Illusion
{
	class TargetPlat
	{
	public:
		char mResolveDepthSurface;
		char mHasDepthSurface;
		char mNumSurfaces;
		char mInvertedDepth;
		uint16_t mNumMips;
		D3D11_VIEWPORT mViewport;
		ID3D11RenderTargetView* mRenderTargetView[32][4];
		ID3D11DepthStencilView* mDepthStencilView;
		ID3D11DepthStencilView* mDepthStencilViewRO;
		void* mMSAATargetTexture[4];
		void* mMSAADepthTexture;
	}; typedef TargetPlat CTargetPlat;

	class ITargetPlat
	{
	public:

	};

	class Target : public ITargetPlat
	{
	public:
		int mWidth;
		int mHeight;
		TargetPlat* mTargetPlat;
		unsigned int mNumTargetTextures;
		class Texture* mTargetTexture[4];
		char mOwnsTargetTexture[4];
		class Texture* mDepthTexture;
		class Texture* mDepthTextureCopy;
		char mOwnsDepthTexture;
		char mDescription[32];
	}; typedef Target CTarget;

	struct CreateTargetParams
	{
		UFG::qString m_Name;
		int m_Width;
		int m_Height;
		int m_Depth;
		int m_ArraySize;
		uint8_t m_TextureFormats[4];
		uint32_t m_NumTextures;
		uint32_t m_TextureType;
		uint32_t m_TargetFlags;
		int m_NumMips;
		class Texture* m_Textures[4];
		class Texture* m_DepthTexture;
		uint32_t m_ESRAM_Offset[4];
		uint32_t m_ESRAM_UsageBytes[4];
		uint32_t m_ESRAM_OffsetDepth;
		uint32_t m_ESRAM_UsageBytesDepth;
		bool m_UseESRAM[4];
		bool m_UseESRAM_Depth;

		CreateTargetParams(const char* p_Name, int p_Width, int p_Height)
		{
			m_Name.Set(p_Name);
			m_Width = p_Width;
			m_Height = p_Height;
			m_Depth = 1;
			m_ArraySize = 1;
			m_TextureFormats[0] = 0x0;
			m_TextureFormats[1] = m_TextureFormats[2] = m_TextureFormats[3] = 0xFF;
			m_NumTextures = 1;
			memset(m_Textures, 0, sizeof(m_Textures));
			m_TextureType = 0;
			m_TargetFlags = 0;
			m_NumMips = 1;
			m_DepthTexture = nullptr;
			memset(m_ESRAM_Offset, 0, sizeof(m_ESRAM_Offset));
			memset(m_ESRAM_UsageBytes, 0, sizeof(m_ESRAM_UsageBytes));
			m_ESRAM_OffsetDepth = 0;
			m_ESRAM_UsageBytesDepth = 0;
			memset(m_UseESRAM, 0, sizeof(m_UseESRAM));
			m_UseESRAM_Depth = false;
		}
	};
}