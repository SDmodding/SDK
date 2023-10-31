#pragma once

namespace Illusion
{
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

	struct Texture_t : UFG::ResourceData_t // TypeUID: 0xCDBFA090 || ChunkUID: 0x8B43FABF
	{
		uint32_t m_Flags;
		eTextureFormat m_Format;
		uint8_t m_Type;
		uint8_t m_Aniso;
		uint8_t m_MipMapBiasPreset;
		uint32_t m_MipMapBias;
		uint16_t m_Width;
		uint16_t m_Height;
		uint8_t m_NumMipMaps;
		uint8_t m_Filter;
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