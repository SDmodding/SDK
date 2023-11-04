#pragma once

namespace Illusion
{
	struct BonePallete_t : UFG::ResourceData_t // TypeUID: 0x982456DB || ChunkUID: 0x50A819E3
	{
		uint32_t m_NumPalettes;
		uint32_t m_NumBones;
		int64_t m_BoneNameTableOffset;
		int64_t m_BoneUIDTableOffset;
		int64_t m_BoneFullUIDTableOffset;

		struct Name_t { char m_Str[64]; };

		__inline Name_t* GetBoneNameTable()
		{
			return reinterpret_cast<Name_t*>(reinterpret_cast<uintptr_t>(&m_BoneNameTableOffset) + m_BoneNameTableOffset);
		}

		__inline uint32_t* GetBoneUIDTable()
		{
			return reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(&m_BoneUIDTableOffset) + m_BoneUIDTableOffset);
		}
	};
}