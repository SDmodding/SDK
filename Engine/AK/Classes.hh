#pragma once

template <typename T>
struct AkArray
{
	T* m_pItems;
	uint32_t m_uLength;
	uint32_t m_ulReserved;
};

template <typename Key, typename Item>
struct MapStruct
{
	Key key;
	Item item;
};

template <typename A, typename B, size_t N>
struct HashList
{
	int m_MemPoolId;

	struct Item_t
	{
		HashList<A, B, N>::Item_t* pNextItem;
		MapStruct<A, B> Assoc;
	};

	Item_t* m_table[N];
	uint32_t m_uiSize;
};

template <typename T, size_t N>
struct HashListBare
{
	T m_table[N];
	uint32_t m_uiSize;
};

struct AkBankKey
{
	uint32_t bankID;
	const void* pInMemoryPtr;
};

template <typename T>
class CAkIndexItem
{
public:
	CAkLock m_IndexLock;
	HashListBare<T, 193> m_mapIDToPtr;

	T GetPtrAndAddRef(uint32_t p_ID)
	{
		return reinterpret_cast<T(__fastcall*)(void*, uint32_t)>(UFG_RVA(0xA5D770))(this, p_ID);
	}
};

class CAkUsageSlot
{
public:
	AkBankKey key;
	CAkUsageSlot* pNextItem;
	uint32_t m_BankID;
	char* m_pData;
	uint32_t m_uLoadedDataSize;
	int m_memPoolId;
	bool m_bIsInternalPool;
	uint32_t m_uNumLoadedItems;
	uint32_t m_uIndexSize;
	void* m_paLoadedMedia;
	void* m_pfnBankCallback;
	void* m_pCookie;
	AkArray<class CAkIndexable*> m_listLoadedItem;
	int m_iRefCount;
	int m_iPrepareRefCount;
	int8_t m_bWasLoadedAsABank : 1;
	int8_t m_bWasIndexAllocated : 1;
	int8_t m_bIsMediaPrepared : 1;
	int8_t m_bUsageProhibited : 1;
	int m_iWasPreparedAsABankCounter;
};

struct AkMediaInfo
{
	char* pInMemoryData;
	uint32_t uInMemoryDataSize;
};

struct AkMediaEntry
{
	AkMediaInfo m_preparedMediaInfo;
	AkArray<MapStruct<CAkUsageSlot*, AkMediaInfo>> m_BankSlots;
	uint32_t uRefCount;
	uint32_t m_sourceID;
};