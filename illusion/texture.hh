#pragma once

namespace Illusion
{
	class ITexturePlat {};

	class Texture : public ITexturePlat, public UFG::qResourceData
	{
	public:
		u32 mFlags;
		s8 mFormat;
		s8 mType;
		s8 mAniso;
		s8 mMipMapBiasPreset;
		u32 mMipMapBias;
		u16 mWidth;
		u16 mHeight;
		s8 mNumMipMaps;
		s8 mFilter;
		u16 mDepth;
		u32 mAlphaStateUID;
		UFG::qOffset64<TextureUser*> mTextureUser;
		u32 mImageDataByteSize;
		u32 mLastUsedFrameNum;
		u64 mImageDataPosition;
		UFG::qVRAMemoryPool* mVRAMPool;
		UFG::qMemoryPool* mMemoryPool;
		UFG::qResourceFileHandle mTextureDataHandle;
	};
	SDK_ASSERT_SIZEOF(Texture, 0xC8);
}