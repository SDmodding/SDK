#pragma once

namespace UFG
{
	class CGameStatTracker
	{
	public:
		void SetStat(GameStat::BoolStat stat, bool status)
		{
			reinterpret_cast<void(__fastcall*)(void*, GameStat::BoolStat, bool)>(UFG_RVA(0x4BD250))(this, stat, status);
		}

		bool GetStat(GameStat::BoolStat stat)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, GameStat::BoolStat)>(UFG_RVA(0x4A6720))(this, stat);
		}
	};

	namespace GameStatTracker
	{
		CGameStatTracker* Get()
		{
			return *reinterpret_cast<CGameStatTracker**>(UFG_RVA(0x2405488));
		}
	}
}