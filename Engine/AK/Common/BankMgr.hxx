#pragma once

class CAkBankMgr
{
public:
	CAkBankReader m_BankReader;
	void* m_eventQueue;
	bool m_bStopThread;
	CAkLock m_queueLock;
	CAkLock m_MediaLock;

	UFG_PAD(0x30);
	//CAkList2<CAkBankMgr::AkBankQueueItem, CAkBankMgr::AkBankQueueItem const&, 1, ArrayPoolDefault> m_BankQueue;

	bool m_bIsFirstBusLoaded;
	HashList<unsigned long, AkMediaEntry, 193> m_MediaHashTable;

	UFG_PAD(0x100);
	//CAkBankList m_BankList;

	HashList<unsigned long, char*, 31> m_BankIDToFileName;
	bool m_bFeedbackInBank;

	UFG_PAD(0x58);
	/*CAkBankCallbackMgr m_CallbackMgr;
	AkSortedKeyArray<AkMediaInformation, AkSrcTypeInfo, ArrayPoolDefault, CAkBankMgr::AkSortedPreparationListGetKey, 8> m_PreparationAccumulator;
	bool m_bAccumulating;*/

	static __inline CAkBankMgr* Instance() {
		return *reinterpret_cast<CAkBankMgr**>(UFG_RVA(0x249E950));
	}
};
UFG_ASSERT_CLASS(CAkBankMgr, 2392);