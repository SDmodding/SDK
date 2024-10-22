#pragma once

namespace UFG
{
	class GameStatTracker
	{
	public:
		enum ThresholdType
		{
			ThresholdType_Cop,
			ThresholdType_Triad,
			NUM_THRESHOLD_TYPES
		};

		enum SnapshotType
		{
			Snapshot_Current,
			Snapshot_OpenWorld,
			Snapshot_Mission,
			Snapshot_Replay,
			Snapshot_Save,
			Snapshot_Count,
			Snapshot_Undefined
		};

		FactionInterface mFactionInterface;
		qPropertySet* mpDefaultData;
		qPropertySet* mpRuntimeData;
		qPropertySet* mpFaceLevelPropertySet;
		qPropertyList* mpFaceLevelPropertyList;
		int m_iMaxFaceLevel;
		qPropertySet* mpXPThresholdPropertySet;
		qPropertyList* mpXPThresholdPropertyList[2];
		u32 mMaxXPThresholdLevels[2];
		GameSnapshot* mpSnapshots[5];
		SimpleTimer mSessionTimer;
		bool m_bIsApplyingSnapshotEffects : 1;

		SDK_SINLINE GameStatTracker* Instance() { return reinterpret_cast<GameStatTracker*>(SDK_RVA(0x24084D0)); }

		/* Functions */

		int GetDiscountForFaceLevel(int iFaceLevel) { return reinterpret_cast<int(SDK_CALL*)(void*, int)>(SDK_RVA(0x4A2540))(this, iFaceLevel); }
		int GetExperienceForFaceLevel(int iFaceLevel) { return reinterpret_cast<int(SDK_CALL*)(void*, int)>(SDK_RVA(0x4A26D0))(this, iFaceLevel); }
		int GetFaceLevel() { return reinterpret_cast<int(SDK_CALL*)(void*)>(SDK_RVA(0x4A2740))(this); }
		int GetFaceLevelFromExperience(int standingExperience) { return reinterpret_cast<int(SDK_CALL*)(void*, int)>(SDK_RVA(0x4A2760))(this, standingExperience); }
		bool GetFavoursUnlockedForFaceLevel(int iFaceLevel) { return reinterpret_cast<bool(SDK_CALL*)(void*, int)>(SDK_RVA(0x4A2820))(this, iFaceLevel); }
		int GetHealthLevel() { return reinterpret_cast<int(SDK_CALL*)(void*)>(SDK_RVA(0x4A3440))(this); }
		int GetMaxStanding() { return reinterpret_cast<int(SDK_CALL*)(void*)>(SDK_RVA(0x4A53B0))(this); }
		int GetNumHealthShrinesCollected() { return reinterpret_cast<int(SDK_CALL*)(void*)>(SDK_RVA(0x4A5670))(this); }
		int GetNumSafeHousesUnlockedForFaceLevel(int iFaceLevel) { return reinterpret_cast<int(SDK_CALL*)(void*, int)>(SDK_RVA(0x4A5950))(this, iFaceLevel); }
		int GetPercentageToNextLevel(GameStat::Int32Stat stat) { return reinterpret_cast<int(SDK_CALL*)(void*, GameStat::Int32Stat)>(SDK_RVA(0x4A5C00))(this, stat); }
		int GetPercentageToNextXPLevel(ThresholdType thresholdType, int totalXP) { 
			return reinterpret_cast<int(SDK_CALL*)(void*, ThresholdType, int)>(SDK_RVA(0x4A5CE0))(this, thresholdType, totalXP);
		}
		int GetPercentageToNextFaceLevel() { return GetPercentageToNextLevel(GameStat::Standing); }
		void GetPointsSinceLastLevel(int stat, u32* iExpTowardsNextLevel, u32* iDiffBetweenLevels) { 
			reinterpret_cast<void(SDK_CALL*)(void*, int, u32*, u32*)>(SDK_RVA(0x4A5F10))(this, stat, iExpTowardsNextLevel, iDiffBetweenLevels); 
		}
		int GetRageTimerForFaceLevel(int iFaceLevel) { return reinterpret_cast<int(SDK_CALL*)(void*, int)>(SDK_RVA(0x4A5FE0))(this, iFaceLevel); }
		void GetStandingPointsSinceLastLevel(u32* iExpTowardsNextLevel, u32* iDiffBetweenLevels) { 
			GetPointsSinceLastLevel(GameStat::Standing, iExpTowardsNextLevel, iDiffBetweenLevels);
		}

		void Reset(bool resetOptions) { reinterpret_cast<void(SDK_CALL*)(void*, bool)>(SDK_RVA(0x4B67D0))(this, resetOptions); }

		/* Timers */

		void PauseGameStatTimers() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x4B2410))(this); }
		void StartGameStatTimers() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x4BF700))(this); }

		/* Getters */

		PersistentData::MapBinary* GetMapBinary(GameStat::MapBinaryStat stat) { return mpSnapshots[0]->mpMapBinaries[stat]; }
		PersistentData::MapBool* GetMapBool(GameStat::MapBoolStat stat) { return mpSnapshots[0]->mpMapBools[stat]; }
		PersistentData::MapFloat* GetMapFloat(GameStat::MapFloatStat stat) { return mpSnapshots[0]->mpMapFloats[stat]; }
		PersistentData::MapInt* GetMapInt(GameStat::MapInt32Stat stat) { return mpSnapshots[0]->mpMapInts[stat]; }
		PersistentData::Binary* GetStat(GameStat::BinaryStat stat) { return &mpSnapshots[0]->mBinaries[stat]; }
		PersistentData::String* GetStat(GameStat::StringStat stat) { return &mpSnapshots[0]->mStrings[stat]; }
		PersistentData::ID* GetStat(GameStat::IDStat stat) { return &mpSnapshots[0]->mIDs[stat]; }
		int GetStat(GameStat::Int32RangedStat stat) { return mpSnapshots[0]->mIntsRanged[stat].mValue; }
		int GetStat(GameStat::Int32Stat stat) { return mpSnapshots[0]->mInts[stat].mValue; }

		int GetStat(GameStat::MapInt32Stat stat, const qSymbol& name) { 
			return reinterpret_cast<int(SDK_CALL*)(void*, GameStat::MapInt32Stat, const qSymbol&)>(SDK_RVA(0x4A65F0))(this, stat, name); 
		}

		f32 GetStat(GameStat::FloatRangedStat stat) { return mpSnapshots[0]->mFloatsRanged[stat].mValue; }
		f32 GetStat(GameStat::FloatStat stat) { return mpSnapshots[0]->mFloats[stat].mValue; }

		f32 GetStat(GameStat::MapFloatStat stat, const qSymbol& name) {
			return reinterpret_cast<f32(SDK_CALL*)(void*, GameStat::MapFloatStat, const qSymbol&)>(SDK_RVA(0x4A6680))(this, stat, name); 
		}

		u64 GetStat(GameStat::MapUInt64Stat stat, const qSymbol& name) {
			return reinterpret_cast<unsigned __int64(SDK_CALL*)(void*, GameStat::MapUInt64Stat, const qSymbol&)>(SDK_RVA(0x4A66D0))(this, stat, name);
		}

		bool GetStat(GameStat::BoolStat stat) { return mpSnapshots[0]->mBools[stat].mValue; }

		bool GetStat(GameStat::MapBoolStat stat, const qSymbol& name) {
			return reinterpret_cast<bool(SDK_CALL*)(void*, GameStat::MapBoolStat, const qSymbol&)>(SDK_RVA(0x4A6740))(this, stat, name);
		}

		int GetStatRange(GameStat::Int32RangedStat stat) { return mpSnapshots[0]->mIntsRanged[stat].mRange; }
		f32 GetStatRange(GameStat::FloatRangedStat stat) { return mpSnapshots[0]->mFloatsRanged[stat].mRange; }
		SimpleTimer* GetTimeStat(GameStat::TimeStat stat) { return &mpSnapshots[0]->mTimes[stat].mTimer; }

		/* Setters */

		void SetStat(GameStat::BinaryStat stat, const PersistentData::Binary& binary) { 
			reinterpret_cast<void(SDK_CALL*)(void*, GameStat::BinaryStat, const PersistentData::Binary&)>(SDK_RVA(0x4BD1C0))(this, stat, binary); 
		}

		void SetStat(GameStat::BoolStat stat, bool status) { mpSnapshots[0]->mBools[stat].mValue = status; }
		void SetStat(GameStat::FloatRangedStat stat, f32 number) { reinterpret_cast<void(SDK_CALL*)(void*, GameStat::FloatRangedStat, f32)>(SDK_RVA(0x4BD280))(this, stat, number); }
		void SetStat(GameStat::FloatStat stat, f32 number) { mpSnapshots[0]->mFloats[stat].mValue; }
		void SetStat(GameStat::IDStat stat, const qSymbol& id) { mpSnapshots[0]->mIDs[stat].mValue = id; }
		void SetStat(GameStat::Int32RangedStat stat, int number) { reinterpret_cast<void(SDK_CALL*)(void*, GameStat::Int32RangedStat, int)>(SDK_RVA(0x4BD340))(this, stat, number); }
		void SetStat(GameStat::Int32Stat stat, int number) { reinterpret_cast<void(SDK_CALL*)(void*, GameStat::Int32Stat, int)>(SDK_RVA(0x4BD390))(this, stat, number); }
		void SetStat(GameStat::MapBoolStat stat, const qSymbol& name, bool state) { 
			reinterpret_cast<void(SDK_CALL*)(void*, GameStat::MapBoolStat, const qSymbol&, bool)>(SDK_RVA(0x4BD3E0))(this, stat, name, state); 
		}
		void SetStat(GameStat::MapFloatStat stat, const qSymbol& name, f32 state) { 
			reinterpret_cast<void(SDK_CALL*)(void*, GameStat::MapFloatStat, const qSymbol&, f32)>(SDK_RVA(0x4BD450))(this, stat, name, state); 
		}
		void SetStat(GameStat::MapInt32Stat stat, const qSymbol& name, int state) {
			reinterpret_cast<void(SDK_CALL*)(void*, GameStat::MapInt32Stat, const qSymbol&, int)>(SDK_RVA(0x4BD4B0))(this, stat, name, state);
		}
		void SetStat(GameStat::MapUInt64Stat stat, const qSymbol& name, u64 state) {
			reinterpret_cast<void(SDK_CALL*)(void*, GameStat::MapUInt64Stat, const qSymbol&, u64)>(SDK_RVA(0x4BD520))(this, stat, name, state);
		}
		void SetStat(GameStat::StringStat stat, const qString& string) { reinterpret_cast<void(SDK_CALL*)(void*, GameStat::StringStat, const qString&)>(SDK_RVA(0x4BD580))(this, stat, string); }
	};
	SDK_ASSERT_SIZEOF(GameStatTracker, 0x1850);
}