#pragma once

namespace Illusion
{
	class CTexture;

	struct TextureLockInfo_t
	{
		char* mData;
		int mLinePitch;
		int mDepthPitch;
	};

	class ITexturePlat
	{
	public:
		enum eLockType : int
		{
			LOCK_NONE = -1,
			LOCK_READ,
			LOCK_OVERWRITE,
			LOCK_MODIFY
		};

		__inline bool Lock(eLockType p_Type, TextureLockInfo_t* p_Info, int p_MipLevel, int p_FaceIndex)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, eLockType, TextureLockInfo_t*, int, int)>(UFG_RVA(0xA1C560))(this, p_Type, p_Info, p_MipLevel, p_FaceIndex);
		}
		
		__inline void Unlock()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xA22A70))(this);
		}
	};

	class CTextureUser
	{
	public:
		UFG::qResourceHandle mAlphaStateHandle;
		UFG::qResourceHandle mRasterStateHandle;

		void OnLoad(CTexture* p_Texture)
		{
			reinterpret_cast<void(_fastcall*)(void*, CTexture*)>(UFG_RVA(0x95F70))(this, p_Texture);
		}
	};

	class CTexture : public ITexturePlat, public UFG::qResourceData
	{
	public:
		enum eFormat : uint32_t
		{
			FORMAT_A8R8G8B8 = 0x0,
			FORMAT_DXT1 = 0x1,
			FORMAT_DXT3 = 0x2,
			FORMAT_DXT5 = 0x3,
			FORMAT_R5G6B5 = 0x4,
			FORMAT_A1R5G5B5 = 0x5,
			FORMAT_X8 = 0x6,
			FORMAT_X16 = 0x7,
			FORMAT_CXT1 = 0x8,
			FORMAT_DXN = 0x9,
			FORMAT_BC6H_UF16 = 0xA,
			FORMAT_BC6H_SF16 = 0xB,
			FORMAT_BC7_UNORM = 0xC,
			FORMAT_BC7_UNORM_SRGB = 0xD,
			FORMAT_R32F = 0xE,
			FORMAT_X16FY16FZ16FW16F = 0xF,
			FORMAT_D24S8 = 0x10,
			FORMAT_D24FS8 = 0x11,
			FORMAT_SHADOW = 0x12,
			FORMAT_DEPTHCOPY = 0x13,
			FORMAT_A2R10G10B10 = 0x14,
			FORMAT_A2R10G10B10F = 0x15,
			FORMAT_A16B16G16R16 = 0x16,
			NUM_TEX_FORMATS = 0x17,
		};

		enum eFlags : uint32_t
		{
			FLAG_CLAMPU = 0x1,
			FLAG_CLAMPV = 0x2,
			FLAG_MIRRORU = 0x4,
			FLAG_MIRRORV = 0x8,
			FLAG_SAMPLER_ADDRESS_MASK = 0xF,
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
			FLAG_RUNTIME_MASK = 0x100A000,
		};

		uint32_t mFlags;
		char mFormat;
		char mType;
		char mAniso;
		char mMipMapBiasPreset;
		uint32_t mMipMapBias;
		uint16_t mWidth;
		uint16_t mHeight;
		char mNumMipMaps;
		char mFilter;
		uint16_t mDepth;
		uint32_t mAlphaStateUID;
		UFG::qOffset64<CTextureUser> mTextureUser;
		uint32_t mImageDataByteSize;
		uint32_t mLastUsedFrameNum;
		uint64_t mImageDataPosition;
		class qVRAMemoryPool* mVRAMPool;
		UFG::CMemoryPool* mMemoryPool;
		UFG::qResourceFileHandle mTextureDataHandle;
	};
}