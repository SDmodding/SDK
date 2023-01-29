#pragma once

namespace UFG
{
	class CGameStatTracker
	{
	public:
		void SetStat(GameStat::MapBoolStat stat, UFG::qSymbol* name, bool state)
		{
			reinterpret_cast<void(__fastcall*)(void*, GameStat::MapBoolStat, UFG::qSymbol*, bool)>(UFG_RVA(0x4BD3E0))(this, stat, name, state);
		}

		void SetStat(GameStat::BoolStat stat, bool status)
		{
			reinterpret_cast<void(__fastcall*)(void*, GameStat::BoolStat, bool)>(UFG_RVA(0x4BD250))(this, stat, status);
		}

		void SetStat(GameStat::Int32Stat stat, int number)
		{
			reinterpret_cast<void(__fastcall*)(void*, GameStat::Int32Stat, int)>(UFG_RVA(0x4BD390))(this, stat, number);
		}

		bool GetStat(GameStat::BoolStat stat)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, GameStat::BoolStat)>(UFG_RVA(0x4A6720))(this, stat);
		}

		int GetStat(GameStat::Int32Stat stat)
		{
			return reinterpret_cast<int(__fastcall*)(void*, GameStat::Int32Stat)>(UFG_RVA(0x4A65D0))(this, stat);
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