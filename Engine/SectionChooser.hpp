#pragma once

namespace UFG
{
	namespace SectionChooser
	{
		CBSP* GetBSP()
		{
			return *reinterpret_cast<CBSP**>(UFG_RVA(0x23A8D78));
		}

		void GetFilenameForSectionIndex(uint32_t p_Index, qString* p_FileName, eLODSetting p_LOD)
		{
			reinterpret_cast<void(__fastcall*)(uint32_t, qString*, eLODSetting)>(UFG_RVA(0x2326B0))(p_Index, p_FileName, p_LOD);
		}

		uint32_t GetCellIndexAtPosition(qVector3* p_Position)
		{
			return reinterpret_cast<uint32_t(__fastcall*)(qVector3*, bool)>(UFG_RVA(0x232460))(p_Position, false);
		}
	}
}