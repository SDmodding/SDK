#pragma once

namespace UFG
{
	class CSaveLoad
	{
	public:
		qString m_Postfix;
		unsigned int m_iNumSlots;
		qString m_SaveFileTitle;
		unsigned int mStatus;
		unsigned int mOperation;

		UFG_PAD(0x50 * 8);
		//UFG::GameSaveLoad::tsSaveGameHeaderInfo m_GameSlotHeaderInfo[8];

		void* mFileContainer;
		qString mActiveFolderDisplayNamePS;
		unsigned int mActiveGameSlot;
		int m_iCurrentPhotoNum;
		void* m_pCurrentPhoto;
		unsigned int m_iCurrentPhotoSize;
		bool m_bPhotoExists[1];
		bool m_FirstLoad;

		bool LoadGameOptions()
		{ 
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x4AE5A0))(this);
		}

		bool LoadSaveDataFileList()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x4AEE30))(this);
		}
	};

	CSaveLoad* SaveLoad = reinterpret_cast<CSaveLoad*>(UFG_RVA(0x2409D30));
}