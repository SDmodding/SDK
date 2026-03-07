#pragma once

namespace Illusion
{
	class TextureLockInfo
	{
	public:
		char* mData;
		int mLinePitch;
		int mDepthPitch;
	};

	class ITexturePlat
	{
	public:
		enum LockType
		{
			LOCK_NONE = -1,
			LOCK_READ = 0,
			LOCK_OVERWRITE,
			LOCK_MODIFY
		};

		bool Lock(LockType type, TextureLockInfo* info, int mipLevel = 0, int faceIndex = 0) {
			return SDK_CALL_FUNC(bool, 0xA1C560, void*, LockType, TextureLockInfo*, int, int)(this, type, info, mipLevel, faceIndex);
		}

		void Unlock() { SDK_CALL_FUNC(void, 0xA22A70, void*)(this); }
	};

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