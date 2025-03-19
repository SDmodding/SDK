#pragma once

namespace UFG
{
	class FactionInterface
	{
	public:
		eFactionStandingEnum mStandings[NUM_FACTIONS][NUM_FACTIONS];

		SDK_SINLINE FactionInterface* Instance() { return SDK_VAR(FactionInterface*, 0x24084D0); }

		/* Functions */

		void SetStanding(eFactionClassEnum source, eFactionClassEnum target, eFactionStandingEnum standing) { 
			reinterpret_cast<void(SDK_CALL*)(void*, eFactionClassEnum, eFactionClassEnum, eFactionStandingEnum)>(SDK_RVA(0x387BE0))(this, source, target, standing); 
		}

		void SetFaction(SimObject* pObject, qSymbol* newFactionSymbol) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*, qSymbol*)>(SDK_RVA(0x3862D0))(this, pObject, newFactionSymbol); }

		void Reset() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x382A00))(this); }

		eFactionStandingEnum GetStanding(eFactionClassEnum source, eFactionClassEnum target) { return mStandings[source][target]; }

		eFactionStandingEnum GetStanding(SimObject* pSource, SimObject* pTarget) { 
			return reinterpret_cast<eFactionStandingEnum(SDK_CALL*)(void*, SimObject*, SimObject*)>(SDK_RVA(0x362650))(this, pSource, pTarget); 
		}

		eFactionClassEnum GetFaction(SimObject* pObject) { return reinterpret_cast<eFactionClassEnum(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x35F580))(this, pObject); }
	};
	SDK_ASSERT_SIZEOF(FactionInterface, 0x17C4);
}