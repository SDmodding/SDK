#pragma once

namespace UFG
{
	namespace SectionChooser
	{
		UFG_INLINE void GetFilenameForSectionIndex(uint32_t p_Index, qString* p_FileName, eLODSetting p_LOD)
		{
			reinterpret_cast<void(__fastcall*)(uint32_t, qString*, eLODSetting)>(UFG_RVA(0x2326B0))(p_Index, p_FileName, p_LOD);
		}

		UFG_INLINE uint32_t GetCellIndexAtPosition(qVector3* p_Position)
		{
			return reinterpret_cast<uint32_t(__fastcall*)(qVector3*, bool)>(UFG_RVA(0x232460))(p_Position, false);
		}

		UFG_INLINE void FlushAltLayer(const char* p_szLayerName, bool p_bEnable)
		{
			reinterpret_cast<void(__fastcall*)(const char*, bool)>(UFG_RVA(0x2316D0))(p_szLayerName, p_bEnable);
		}
	}
}