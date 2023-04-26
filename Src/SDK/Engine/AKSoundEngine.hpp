#pragma once

namespace AKSoundEngine
{
	enum AKRESULT
	{
		AK_NotImplemented = 0x0,
		AK_Success = 0x1,
		AK_Fail = 0x2,
		AK_PartialSuccess = 0x3,
		AK_NotCompatible = 0x4,
		AK_AlreadyConnected = 0x5,
		AK_NameNotSet = 0x6,
		AK_InvalidFile = 0x7,
		AK_AudioFileHeaderTooLarge = 0x8,
		AK_MaxReached = 0x9,
		AK_InputsInUsed = 0xA,
		AK_OutputsInUsed = 0xB,
		AK_InvalidName = 0xC,
		AK_NameAlreadyInUse = 0xD,
		AK_InvalidID = 0xE,
		AK_IDNotFound = 0xF,
		AK_InvalidInstanceID = 0x10,
		AK_NoMoreData = 0x11,
		AK_NoSourceAvailable = 0x12,
		AK_StateGroupAlreadyExists = 0x13,
		AK_InvalidStateGroup = 0x14,
		AK_ChildAlreadyHasAParent = 0x15,
		AK_InvalidLanguage = 0x16,
		AK_CannotAddItseflAsAChild = 0x17,
		AK_TransitionNotFound = 0x18,
		AK_TransitionNotStartable = 0x19,
		AK_TransitionNotRemovable = 0x1A,
		AK_UsersListFull = 0x1B,
		AK_UserAlreadyInList = 0x1C,
		AK_UserNotInList = 0x1D,
		AK_NoTransitionPoint = 0x1E,
		AK_InvalidParameter = 0x1F,
		AK_ParameterAdjusted = 0x20,
		AK_IsA3DSound = 0x21,
		AK_NotA3DSound = 0x22,
		AK_ElementAlreadyInList = 0x23,
		AK_PathNotFound = 0x24,
		AK_PathNoVertices = 0x25,
		AK_PathNotRunning = 0x26,
		AK_PathNotPaused = 0x27,
		AK_PathNodeAlreadyInList = 0x28,
		AK_PathNodeNotInList = 0x29,
		AK_VoiceNotFound = 0x2A,
		AK_DataNeeded = 0x2B,
		AK_NoDataNeeded = 0x2C,
		AK_DataReady = 0x2D,
		AK_NoDataReady = 0x2E,
		AK_NoMoreSlotAvailable = 0x2F,
		AK_SlotNotFound = 0x30,
		AK_ProcessingOnly = 0x31,
		AK_MemoryLeak = 0x32,
		AK_CorruptedBlockList = 0x33,
		AK_InsufficientMemory = 0x34,
		AK_Cancelled = 0x35,
		AK_UnknownBankID = 0x36,
		AK_IsProcessing = 0x37,
		AK_BankReadError = 0x38,
		AK_InvalidSwitchType = 0x39,
		AK_VoiceDone = 0x3A,
		AK_UnknownEnvironment = 0x3B,
		AK_EnvironmentInUse = 0x3C,
		AK_UnknownObject = 0x3D,
		AK_NoConversionNeeded = 0x3E,
		AK_FormatNotReady = 0x3F,
		AK_WrongBankVersion = 0x40,
		AK_DataReadyNoProcess = 0x41,
		AK_FileNotFound = 0x42,
		AK_DeviceNotReady = 0x43,
		AK_CouldNotCreateSecBuffer = 0x44,
		AK_BankAlreadyLoaded = 0x45,
		AK_RenderedFX = 0x47,
		AK_ProcessNeeded = 0x48,
		AK_ProcessDone = 0x49,
		AK_MemManagerNotInitialized = 0x4A,
		AK_StreamMgrNotInitialized = 0x4B,
		AK_SSEInstructionsNotSupported = 0x4C,
		AK_Busy = 0x4D,
		AK_UnsupportedChannelConfig = 0x4E,
		AK_PluginMediaNotAvailable = 0x4F,
		AK_MustBeVirtualized = 0x50,
		AK_CommandTooLarge = 0x51,
	};

	typedef _RTL_CRITICAL_SECTION CAkLock;

	template <typename T>
	struct Array
	{
		T* m_pItems;
		unsigned int m_uLength;
		unsigned int m_ulReserved;
	};

	template <typename A, typename B>
	struct MapStruct
	{
		A key;
		B item;
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

		Item_t m_table[N];
		unsigned int m_uiSize;
	};

	struct BankKey_t
	{
		unsigned int bankID;
		const void* pInMemoryPtr;
	};

	struct UsageSlot_t
	{
		BankKey_t key;
		UsageSlot_t* pNextItem;
		unsigned int m_BankID;
		char* m_pData;
		unsigned int m_uLoadedDataSize;
		int m_memPoolId;
		bool m_bIsInternalPool;
		unsigned int m_uNumLoadedItems;
		unsigned int m_uIndexSize;
		void* m_paLoadedMedia;
		void* m_pfnBankCallback;
		void* m_pCookie;
		Array<void*> m_listLoadedItem;
		int m_iRefCount;
		int m_iPrepareRefCount;
		__int8 m_bWasLoadedAsABank : 1;
		__int8 m_bWasIndexAllocated : 1;
		__int8 m_bIsMediaPrepared : 1;
		__int8 m_bUsageProhibited : 1;
		int m_iWasPreparedAsABankCounter;
	};

	struct MediaInfo_t
	{
		char* pInMemoryData;
		unsigned int uInMemoryDataSize;
	};

	struct MediaEntry_t
	{
		MediaInfo_t m_preparedMediaInfo;
		Array<MapStruct<UsageSlot_t*, MediaInfo_t>> m_BankSlots;
		unsigned int uRefCount;
		unsigned int m_sourceID;
	};


	class CBankReader
	{
	public:
		char* m_pBuffer;
		char* m_pReadBufferPtr;
		unsigned int m_ulRemainingBytes;
		unsigned int m_ulBufferSize;
		unsigned int m_ulDeviceBlockSize;
		void* m_pUserReadBuffer;
		const char* m_pInMemoryBankReaderPtr;
		void* m_pStream;
		float m_fThroughput;
		char m_priority;
		bool m_bIsInitDone;
	};

	class CBankMgr
	{
	public:
		CBankReader m_BankReader;
		void* m_eventQueue;
		bool m_bStopThread;
		CAkLock m_queueLock;
		CAkLock m_MediaLock;

		UFG_PAD(0x30);
		//CAkList2<CAkBankMgr::AkBankQueueItem, CAkBankMgr::AkBankQueueItem const&, 1, ArrayPoolDefault> m_BankQueue;

		bool m_bIsFirstBusLoaded;
		HashList<unsigned long, MediaEntry_t, 193> m_MediaHashTable;

		UFG_PAD(0x100);
		//CAkBankList m_BankList;

		HashList<unsigned long, char*, 31> m_BankIDToFileName;
		bool m_bFeedbackInBank;

		/*CAkBankCallbackMgr m_CallbackMgr;
		AkSortedKeyArray<AkMediaInformation, AkSrcTypeInfo, ArrayPoolDefault, CAkBankMgr::AkSortedPreparationListGetKey, 8> m_PreparationAccumulator;
		bool m_bAccumulating;*/


	};

	namespace BankMgr
	{
		CBankMgr* Get()
		{
			return *reinterpret_cast<CBankMgr**>(UFG_RVA(0x249E950));
		}
	}

	// Rewritten from scratch from (.text:0000000140A41FD0)
	int GetIDFromString(const char* m_String)
	{
		size_t m_Size = strlen(m_String);

		int m_ID = 0x811C9DC5;
		for (size_t i = 0; m_Size > i; ++i)
		{
			char m_Char = m_String[i];

			if (m_Char >= 'A' && m_Char <= 'Z')
				m_Char += 0x20;

			m_ID = static_cast<int>(m_Char ^ (0x1000193 * m_ID));
		}

		return m_ID;
	}

	AKRESULT LoadBank(uint32_t m_ID, void* m_Callback, void* m_Cookie, int m_MemoryPoolID)
	{
		return reinterpret_cast<AKRESULT(__fastcall*)(uint32_t, void*, void*, int)>(UFG_RVA(0xA424A0))(m_ID, m_Callback, m_Cookie, m_MemoryPoolID);
	}
}