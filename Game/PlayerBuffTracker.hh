#pragma once

namespace UFG
{
	enum ePlayerBuffEnum
	{
		ePLAYER_BUFF_NONE = 0x0,
		ePLAYER_BUFF_BERSERK = 0x1,
		ePLAYER_BUFF_SHARPSHOOTER = 0x2,
		ePLAYER_BUFF_SHARPSHOOTER_LEVEL1 = 0x3,
		ePLAYER_BUFF_SHARPSHOOTER_LEVEL2 = 0x4,
		ePLAYER_BUFF_SHARPSHOOTER_LEVEL3 = 0x5,
		ePLAYER_BUFF_ENERGYDRINK = 0x6,
		ePLAYER_BUFF_TEAHOUSE = 0x7,
		ePLAYER_BUFF_MASSAGEPARLOUR = 0x8,
		ePLAYER_BUFF_HEALTHREGEN = 0x9,
		ePLAYER_BUFF_FACEMETER = 0xA,
		ePLAYER_BUFF_STRIKING = 0xB,
		NUM_PLAYER_BUFF = 0xC,
	};

	//=======================================================

	namespace PlayerBuffTracker
	{
		UFG_INLINE void ActivateBuff(ePlayerBuffEnum p_BuffType)
		{
			reinterpret_cast<void(__fastcall*)(ePlayerBuffEnum)>(UFG_RVA(0x51FEA0))(p_BuffType);
		}

		UFG_INLINE bool IsBuffActive(ePlayerBuffEnum p_BuffType)
		{
			return reinterpret_cast<bool(__fastcall*)(ePlayerBuffEnum)>(UFG_RVA(0x5399E0))(p_BuffType);
		}
	}
}