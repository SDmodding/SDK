#pragma once

namespace Illusion
{
	class Texture : public ITexturePlat, public UFG::qResourceData
	{
	public:
		enum Filter
		{
			FILTER_DEFAULT,
			FILTER_LINEAR,
			FILTER_POINT,
			FILTER_ANISOTROPIC,
			FILTER_CONVOLUTION
		};

		enum Flags
		{
			FLAG_CLAMPU = 0x1,
			FLAG_CLAMPV = 0x2,
			FLAG_MIRRORU = 0x4,
			FLAG_MIRRORV = 0x8,
			FLAG_LINEAR = 0x100,
			FLAG_LE = 0x200,
			FLAG_CPU_WRITABLE = 0x400,
			FLAG_TARGET = 0x800,
			FLAG_PS3_TARGET_TILED = 0x1000,
			FLAG_IN_INVENTORY = 0x2000,
			FLAG_CREATED_AT_RUNTIME = 0x4000,
			FLAG_MOVING = 0x8000,
			FLAG_NO_EXPAND_AS_16 = 0x10000,
			FLAG_MOVIE_TEXTURE = 0x20000,
			FLAG_CPU_READABLE = 0x40000,
			FLAG_MIPS_SHADER_SRC = 0x80000,
			FLAG_PRESENT_BUFFER = 0x100000,
			FLAG_ALIASED_TEXTURE = 0x200000,
			FLAG_PC_MAIN_MEM_COPY = 0x400000,
			FLAG_PC_UNORDERED_ACCESS = 0x800000,
			FLAG_REBIND_DATAHANDLE = 0x1000000,
			FLAG_XB1_USE_ESRAM = 0x2000000,
			FLAG_MSAA_2X = 0x4000000,
			FLAG_MSAA_4x = 0x8000000,
			FLAG_SAMPLER_ADDRESS_MASK = 0xF,
			FLAG_RUNTIME_MASK = 0x100A000,
		};

		enum Format
		{
			FORMAT_A8R8G8B8,
			FORMAT_DXT1,
			FORMAT_DXT3,
			FORMAT_DXT5,
			FORMAT_R5G6B5,
			FORMAT_A1R5G5B5,
			FORMAT_X8,
			FORMAT_X16,
			FORMAT_CXT1,
			FORMAT_DXN,
			FORMAT_BC6H_UF16,
			FORMAT_BC6H_SF16,
			FORMAT_BC7_UNORM,
			FORMAT_BC7_UNORM_SRGB,
			FORMAT_R32F,
			FORMAT_X16FY16FZ16FW16F,
			FORMAT_D24S8,
			FORMAT_D24FS8,
			FORMAT_SHADOW,
			FORMAT_DEPTHCOPY,
			FORMAT_A2R10G10B10,
			FORMAT_A2R10G10B10F,
			FORMAT_A16B16G16R16,
			NUM_TEX_FORMATS
		};

		enum Type
		{
			TYPE_2D,
			TYPE_3D,
			TYPE_CUBE,
			TYPE_2D_ARRAY,
			NUM_TEX_TYPES
		};

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

	class TextureHandle : public UFG::qTypedResourceHandle<RTypeUID_Texture, Texture>{};

	/* Static Functions */

	SDK_SINLINE Texture* InternalCreateTexture(const char* name, int width, int height, int depth, Texture::Format format, u32 flags, int num_mips, int type, u32 esram_offset = 0, u32 esram_usage_bytes = 0) {
		return SDK_CALL_FUNC(Texture*, 0x92AF0, const char*, int, int, int, Texture::Format, u32, int, int, u32, u32)(name, width, height, depth, format, flags, num_mips, type, esram_offset, esram_usage_bytes);
	}

	SDK_SINLINE Texture* CreateTexture(const char* name, int width, int height, Texture::Format format, u32 flags, int num_mips = 1, u32 esram_offset = 0, u32 esram_usage_bytes = 0) {
		return SDK_CALL_FUNC(Texture*, 0x8EC20, const char*, int, int, Texture::Format, u32, int, u32, u32)(name, width, height, format, flags, num_mips, esram_offset, esram_usage_bytes);
	}

	SDK_SINLINE Texture* CreateTextureCube(const char* name, int width, int height, Texture::Format format, u32 flags, int num_mips = 1, u32 esram_offset = 0, u32 esram_usage_bytes = 0) {
		return SDK_CALL_FUNC(Texture*, 0x8ED50, const char*, int, int, Texture::Format, u32, int, u32, u32)(name, width, height, format, flags, num_mips, esram_offset, esram_usage_bytes);
	}

	SDK_SINLINE Texture* CreateTexture2DArray(const char* name, int width, int height, int array_size, Texture::Format format, u32 flags, int num_mips = 1, u32 esram_offset = 0, u32 esram_usage_bytes = 0) {
		return SDK_CALL_FUNC(Texture*, 0x8EB80, const char*, int, int, int, Texture::Format, u32, int, u32, u32)(name, width, height, array_size, format, flags, num_mips, esram_offset, esram_usage_bytes);
	}

	SDK_SINLINE Texture* CreateTexture3D(const char* name, int width, int height, int depth, Texture::Format format, u32 flags, int num_mips = 1, u32 esram_offset = 0, u32 esram_usage_bytes = 0) {
		return SDK_CALL_FUNC(Texture*, 0x8EBD0, const char*, int, int, int, Texture::Format, u32, int, u32, u32)(name, width, height, depth, format, flags, num_mips, esram_offset, esram_usage_bytes);
	}
}