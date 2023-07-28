#pragma once

namespace UFG
{
	// Accessed by: GameStatTracker
	class CFactionInterface
	{
	public:
		eFactionStandingEnum mStandings[39][39];

		void InternalReset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3694F0))(this);
		}

		void Reset()
		{
			InternalReset();
		}

		// RVA: 0x3626A0
		eFactionStandingEnum GetStanding(eFactionClassEnum m_Class, eFactionClassEnum m_TargetClass)
		{
			return mStandings[m_Class][m_TargetClass];
		}

		eFactionStandingEnum GetStanding(CSimCharacter* m_Character, CSimCharacter* m_TargetCharacter)
		{
			return reinterpret_cast<eFactionStandingEnum(__fastcall*)(void*, CSimCharacter*, CSimCharacter*)>(UFG_RVA(0x362650))(this, m_Character, m_TargetCharacter);
		}

		// RVA: 0x387BE0
		void SetStanding(eFactionClassEnum m_Class, eFactionClassEnum m_TargetClass, eFactionStandingEnum m_Standing)
		{
			mStandings[m_Class][m_TargetClass] = m_Standing;
		}
	};
}