#pragma once

namespace Illusion
{
	struct MaterialParam_t
	{
		struct StateParam_t
		{
			uint32_t m_NameUID;
			uint32_t m_TypeUID;
			uint16_t m_ParamIndex;

			UFG_PAD(0x2);
		};

		StateParam_t m_StateParam;

		UFG_PAD(0x1C);

		uint32_t m_NameUID;

		UFG_PAD(0x4);

		uint32_t m_TypeUID;

		UFG_PAD(0x4);
	};

	struct MaterialUser_t
	{
		uint16_t m_VisibilityFlags = 0x1F;
		uint16_t mShadowFlags = 0x0;
		uint8_t m_Align[12] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	};

	struct Material_t : UFG::ResourceData_t // TypeUID: 0xF5F8516F || ChunkUID: 0xB4C26312
	{
		UFG_PAD(0x8);

		uint64_t m_StateBlockMask[2] = { 0x0, 0x0 };
		uint32_t m_NumParams;

		UFG_PAD(0x4);

		int64_t m_MaterialUserOffset = 0;

		__inline MaterialParam_t* GetTable()
		{
			return reinterpret_cast<MaterialParam_t*>(reinterpret_cast<uintptr_t>(this) + sizeof(Material_t));
		}

		MaterialParam_t* GetParam(uint32_t p_NameUID)
		{
			MaterialParam_t* m_ParamTable = GetTable();
			for (uint32_t i = 0; m_NumParams > i; ++i)
			{
				MaterialParam_t* m_Param = &m_ParamTable[i];
				if (m_Param->m_StateParam.m_NameUID == p_NameUID)
					return m_Param;
			}

			return nullptr;
		}
		
		__inline MaterialUser_t* GetUser()
		{
			return reinterpret_cast<MaterialUser_t*>(reinterpret_cast<uintptr_t>(&m_MaterialUserOffset) + m_MaterialUserOffset);
		}
	};
}