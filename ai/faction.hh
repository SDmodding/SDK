#pragma once

namespace UFG
{
	enum eFactionClassEnum : s32
	{
		FACTION_INVALID,
		FACTION_INDIFFERENT,
		FACTION_PLAYER,
		FACTION_LAW,
		FACTION_TRIAD_WINSTON,
		FACTION_TRIAD_DOGEYES,
		FACTION_TRIAD_SONNY,
		FACTION_TRIAD_JIIANG,
		FACTION_TRIAD_CHEUK,
		FACTION_TRIAD_TWOCHIN,
		FACTION_TRIAD_GENERIC,
		FACTION_TRIAD_WATERSTREET,
		FACTION_TRIAD_18K,
		FACTION_TRIAD_DOGBOYS,
		FACTION_TRIAD_SUNONYEE,
		FACTION_TRIAD_LEE,
		FACTION_BOUNCER,
		FACTION_INNOCENT,
		FACTION_STUDENT,
		FACTION_AMBIENT_AGGRESSIVE,
		FACTION_AMBIENT_GROUP_1,
		FACTION_AMBIENT_GROUP_2,
		FACTION_AMBIENT_GROUP_3,
		FACTION_AMBIENT_GROUP_4,
		FACTION_NETWORK_TEAM_1,
		FACTION_NETWORK_TEAM_2,
		FACTION_NETWORK_TEAM_3,
		FACTION_NETWORK_TEAM_4,
		FACTION_NETWORK_TEAM_5,
		FACTION_NETWORK_TEAM_6,
		FACTION_NETWORK_TEAM_7,
		FACTION_NETWORK_TEAM_8,
		FACTION_HOSTILE_SPECIAL_1,
		FACTION_HOSTILE_SPECIAL_2,
		FACTION_ALLIED_SPECIAL_1,
		FACTION_ALLIED_SPECIAL_2,
		FACTION_LAW_HOSTILE,
		FACTION_ROOSTER1,
		FACTION_ROOSTER2,
		NUM_FACTIONS,
	};

	enum eFactionStandingEnum : s32
	{
		FACTIONSTANDING_ALLIED,
		FACTIONSTANDING_INDIFFERENT,
		FACTIONSTANDING_HOSTILE,
		FACTIONSTANDING_SCARED,
		NUM_FACTIONSTANDINGS
	};

	class FactionInterface
	{
	public:
		eFactionStandingEnum mStandings[NUM_FACTIONS][NUM_FACTIONS];

		SDK_SINLINE FactionInterface* Instance() { return reinterpret_cast<FactionInterface*>(SDK_RVA(0x24084D0)); }

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