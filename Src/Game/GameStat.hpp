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
		uint8_t g_ScrambleKey[] = { 0x37, 0x0C, 0x43, 0xB9, 0x91, 0xC9, 0x8C, 0x6C, 0xE5, 0x6F, 0x9D, 0x69, 0xB4, 0xC7, 0x20, 0xD0, 0x81, 0xAE, 0x0D, 0x93, 0xE9, 0xB5, 0x65, 0x6E, 0xB2, 0xF2, 0x11, 0x7C, 0x74, 0xE8, 0x36, 0xD8 };

		CGameStatTracker* Get()
		{
			return *reinterpret_cast<CGameStatTracker**>(UFG_RVA(0x2405488));
		}

		uint32_t GetBufferHash(uint32_t p_HeaderSize, char* p_Buffer, uint32_t p_BufferSize)
		{
			uint32_t m_TotalSize = (p_BufferSize - p_HeaderSize - 4);
			if (0 > m_TotalSize)
				return -1;

			char* p_RawBuffer = &p_Buffer[p_HeaderSize];

			uint32_t m_Hash = -1;
			uint32_t m_CrcTable32DupFromChecksumCPP[256] = 
			{ 
				0u, 79764919u, 159529838u, 222504665u, 319059676u, 398814059u, 445009330u, 507990021u, 638119352u, 583659535u, 797628118u, 726387553u, 890018660u, 835552979u, 1015980042u, 
				944750013u, 1276238704u, 1221641927u, 1167319070u, 1095957929u, 1595256236u, 1540665371u, 1452775106u, 1381403509u, 1780037320u, 1859660671u, 1671105958u, 1733955601u, 2031960084u, 
				2111593891u, 1889500026u, 1952343757u, 2552477408u, 2632100695u, 2443283854u, 2506133561u, 2334638140u, 2414271883u, 2191915858u, 2254759653u, 3190512472u, 3135915759u, 3081330742u, 
				3009969537u, 2905550212u, 2850959411u, 2762807018u, 2691435357u, 3560074640u, 3505614887u, 3719321342u, 3648080713u, 3342211916u, 3287746299u, 3467911202u, 3396681109u, 4063920168u,
				4143685023u, 4223187782u, 4286162673u, 3779000052u, 3858754371u, 3904687514u, 3967668269u, 881225847u, 809987520u, 1023691545u, 969234094u, 662832811u, 591600412u, 771767749u, 717299826u, 
				311336399u, 374308984u, 453813921u, 533576470u, 25881363u, 88864420u, 134795389u, 214552010u, 2023205639u, 2086057648u, 1897238633u, 1976864222u, 1804852699u, 1867694188u, 1645340341u, 
				1724971778u, 1587496639u, 1516133128u, 1461550545u, 1406951526u, 1302016099u, 1230646740u, 1142491917u, 1087903418u, 2896545431u, 2825181984u, 2770861561u, 2716262478u, 3215044683u, 
				3143675388u, 3055782693u, 3001194130u, 2326604591u, 2389456536u, 2200899649u, 2280525302u, 2578013683u, 2640855108u, 2418763421u, 2498394922u, 3769900519u, 3832873040u, 3912640137u, 
				3992402750u, 4088425275u, 4151408268u, 4197601365u, 4277358050u, 3334271071u, 3263032808u, 3476998961u, 3422541446u, 3585640067u, 3514407732u, 3694837229u, 3640369242u, 1762451694u, 
				1842216281u, 1619975040u, 1682949687u, 2047383090u, 2127137669u, 1938468188u, 2001449195u, 1325665622u, 1271206113u, 1183200824u, 1111960463u, 1543535498u, 1489069629u, 1434599652u, 
				1363369299u, 622672798u, 568075817u, 748617968u, 677256519u, 907627842u, 853037301u, 1067152940u, 995781531u, 51762726u, 131386257u, 177728840u, 240578815u, 269590778u, 349224269u, 
				429104020u, 491947555u, 4046411278u, 4126034873u, 4172115296u, 4234965207u, 3794477266u, 3874110821u, 3953728444u, 4016571915u, 3609705398u, 3555108353u, 3735388376u, 3664026991u, 
				3290680682u, 3236090077u, 3449943556u, 3378572211u, 3174993278u, 3120533705u, 3032266256u, 2961025959u, 2923101090u, 2868635157u, 2813903052u, 2742672763u, 2604032198u, 2683796849u, 
				2461293480u, 2524268063u, 2284983834u, 2364738477u, 2175806836u, 2238787779u, 1569362073u, 1498123566u, 1409854455u, 1355396672u, 1317987909u, 1246755826u, 1192025387u, 1137557660u, 
				2072149281u, 2135122070u, 1912620623u, 1992383480u, 1753615357u, 1816598090u, 1627664531u, 1707420964u, 295390185u, 358241886u, 404320391u, 483945776u, 43990325u, 106832002u, 
				186451547u, 266083308u, 932423249u, 861060070u, 1041341759u, 986742920u, 613929101u, 542559546u, 756411363u, 701822548u, 3316196985u, 3244833742u, 3425377559u, 3370778784u, 
				3601682597u, 3530312978u, 3744426955u, 3689838204u, 3819031489u, 3881883254u, 3928223919u, 4007849240u, 4037393693u, 4100235434u, 4180117107u, 4259748804u, 2310601993u, 2373574846u, 
				2151335527u, 2231098320u, 2596047829u, 2659030626u, 2470359227u, 2550115596u, 2947551409u, 2876312838u, 2788305887u, 2733848168u, 3165939309u, 3094707162u, 3040238851u, 2985771188u 
			};

			for (uint32_t i = 0; m_TotalSize > i; ++i)
				m_Hash = (m_Hash << 8) ^ m_CrcTable32DupFromChecksumCPP[static_cast<uint8_t>(p_RawBuffer[i] ^ m_Hash)];

			return m_Hash;
		}

		void Descramble(uint64_t p_Timestamp, uint32_t p_HeaderSize, char* p_Buffer, uint32_t p_BufferSize)
		{
			uint32_t m_TotalSize = (p_BufferSize - p_HeaderSize);
			if (0 > m_TotalSize)
				return;

			char p_TimestampKey = 0;
			for (; p_Timestamp; p_Timestamp &= p_Timestamp - 1)
				++p_TimestampKey;

			char* p_XoredBuffer = &p_Buffer[p_HeaderSize];
			char m_UnXorIndex = 0;
			for (uint32_t i = 0; m_TotalSize > i; ++i)
			{
				char c_XorKey = static_cast<char>(i);
				c_XorKey += g_ScrambleKey[m_UnXorIndex % sizeof(g_ScrambleKey)];
				c_XorKey += g_ScrambleKey[(p_TimestampKey + static_cast<char>(i)) % sizeof(g_ScrambleKey)];

				p_XoredBuffer[i] = (p_XoredBuffer[i] ^ c_XorKey);
				m_UnXorIndex += p_XoredBuffer[i];
			}
		}
	}
}