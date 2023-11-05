#pragma once

namespace Illusion
{
	enum eTextureFlags : uint32_t
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

	enum eTextureFormat : uint8_t
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

	enum eTextureType : uint8_t
	{
		TYPE_2D = 0x0,
		TYPE_3D = 0x1,
		TYPE_CUBE = 0x2,
		TYPE_2D_ARRAY = 0x3,
		NUM_TEX_TYPES = 0x4,
	};

	enum eTextureAniso : uint8_t
	{
		ANISO_X1 = 0x0,
		ANISO_X2 = 0x1,
		ANISO_X4 = 0x2,
		ANISO_X6 = 0x3,
		ANISO_X8 = 0x4,
		ANISO_X10 = 0x5,
		ANISO_X12 = 0x6,
		ANISO_X16 = 0x7,
	};

	enum eTextureMipmapPreset : uint8_t
	{
		MIPMAP_BIAS_PRESET_UNSPECIFIED = 0x0,
		MIPMAP_BIAS_PRESET_EAGLE_EYE = 0x9,
		MIPMAP_BIAS_PRESET_SLIDER0 = 0xA,
		MIPMAP_BIAS_PRESET_SLIDER1 = 0xB,
		MIPMAP_BIAS_PRESET_SLIDER2 = 0xC,
		MIPMAP_BIAS_PRESET_SLIDER3 = 0xD,
		MIPMAP_BIAS_PRESET_SLIDER4 = 0xE,
		MIPMAP_BIAS_PRESET_CUSTOM = 0xF,
	};

	enum eTextureFilter : uint8_t
	{
		FILTER_DEFAULT = 0x0,
		FILTER_LINEAR = 0x1,
		FILTER_POINT = 0x2,
		FILTER_ANISOTROPIC = 0x3,
		FILTER_CONVOLUTION = 0x4,
	};

	struct Texture_t : UFG::ResourceData_t // TypeUID: 0xCDBFA090 || ChunkUID: 0x8B43FABF
	{
		eTextureFlags m_Flags;
		eTextureFormat m_Format;
		eTextureType m_Type;
		eTextureAniso m_Aniso;
		eTextureMipmapPreset m_MipMapBiasPreset;
		uint32_t m_MipMapBias;
		uint16_t m_Width;
		uint16_t m_Height;
		uint8_t m_NumMipMaps;
		eTextureFilter m_Filter;
		uint16_t m_Depth;
		uint32_t m_AlphaStateUID;
		uint64_t m_TextureUserOffset;
		uint32_t m_ImageDataByteSize;
		uint32_t m_LastUsedFrameNum;
		uint64_t m_ImageDataPosition;
		void* m_VRAMPool;
		void* m_MemoryPool;

		UFG_PAD(0x18);

		uint32_t m_ResourceUID; // This used (Path + Filename) hash with prev hash set. // TODO: Add option to generate that crap with function...

		UFG_PAD(0x118);
	};
}