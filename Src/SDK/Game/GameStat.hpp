#pragma once

namespace UFG
{
	class CGameStatTracker
	{
	public:
		CFactionInterface mFactionInterface;
		qPropertySet* mpDefaultData;
		qPropertySet* mpRuntimeData;
		qPropertySet* mpFaceLevelPropertySet;
		qPropertyList* mpFaceLevelPropertyList;
		int m_iMaxFaceLevel;
		qPropertySet* mpXPThresholdPropertySet;
		qPropertyList* mpXPThresholdPropertyList[2];
		uint32_t mMaxXPThresholdLevels[2];

		struct GameSnapshot_t
		{
			struct Time_t
			{
				uint64_t mTimestamp;
				float mElapsedTime;
				bool mIsStarted;
			};
			Time_t mTimes[30];

			qSymbol mIDs[44];
			bool mBools[58];
			int mInts[163];
			uint64_t mUInt64s[1];
			float mFloats[139];

			struct IntRanged_t
			{
				int mValue;
				int mRange;
			};
			IntRanged_t mIntsRanged[7];

			struct FloatRanged_t
			{
				float mValue;
				float mRange;
			};
			FloatRanged_t mFloatsRanged[1];

			qString mStrings[25];

			struct Binary_t
			{
				void* mpBuffer;
				unsigned int mSize;
			};
			Binary_t mBinaries[3];

			struct MapKeyValue_t
			{
				qSymbol mKey;

				union
				{
					float mFloatValue;
					int mIntValue;
					bool mBoolValue;
				};
			};

			struct MapBool_t
			{
				int mKeepType;
				qArray<MapKeyValue_t> mValues;
				qArray<qSymbol> mNames;
				int mPersistentDataType;
			};
			MapBool_t* mpMapBools[93];

			struct MapInt_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapInt_t* mpMapInts[47];

			struct MapUInt64_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapUInt64_t* mpMapUInt64s[1];

			struct MapFloat_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapFloat_t* mpMapFloats[18];

			struct MapBinary_t
			{
				qArray<MapKeyValue_t> mValues;
				int mPersistentDataType;
			};
			MapBinary_t* mpMapBinaries[2];

			struct List_t
			{
				int mType;
				union
				{
					qArray<long>* mIntList;
					qArray<int64_t>* mInt64List;
					qArray<bool>* mBoolList;
					qArray<float>* mFloatList;
					void* mListInternal;
				};
			};
			List_t* mpList[1];
		};
		GameSnapshot_t* mpSnapshots[5];
		GameSnapshot_t::Time_t mSessionTimer;
		bool m_bIsApplyingSnapshotEffects : 1;

		void SetStat(GameStat::MapBoolStat m_Stat, qSymbol m_Name, bool m_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, GameStat::MapBoolStat, qSymbol*, bool)>(UFG_RVA(0x4BD3E0))(this, m_Stat, &m_Name, m_Value);
		}

		__forceinline void SetStat(GameStat::BoolStat m_Stat, bool m_Value)
		{
			mpSnapshots[0]->mBools[m_Stat] = m_Value;
		}

		__forceinline void SetStat(GameStat::FloatStat m_Stat, float m_Value)
		{
			mpSnapshots[0]->mFloats[m_Stat] = m_Value;
		}

		__forceinline void SetStat(GameStat::IDStat m_Stat, qSymbol m_Value)
		{
			mpSnapshots[0]->mIDs[m_Stat] = m_Value;
		}

		__forceinline void SetStat(GameStat::Int32Stat m_Stat, int m_Value)
		{
			mpSnapshots[0]->mInts[m_Stat] = m_Value;
		}

		__forceinline bool GetStat(GameStat::BoolStat m_Stat)
		{
			return mpSnapshots[0]->mBools[m_Stat];
		}

		__forceinline float GetStat(GameStat::FloatStat m_Stat)
		{
			return mpSnapshots[0]->mFloats[m_Stat];
		}

		__forceinline qSymbol GetStat(GameStat::IDStat m_Stat)
		{
			return mpSnapshots[0]->mIDs[m_Stat];
		}

		__forceinline int GetStat(GameStat::Int32Stat m_Stat)
		{
			return mpSnapshots[0]->mInts[m_Stat];
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