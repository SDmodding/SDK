#pragma once

namespace UFG
{
	class GameSaveLoad
	{
	public:
		enum Operation : i32
		{
			GSLS_OP_NONE,
			GSLS_OP_LOAD_HEADERS,
			GSLS_OP_LOAD,
			GSLS_OP_SAVE,
			GSLS_OP_DELETE,
			GSLS_OP_FILE_LIST
		};

		enum SaveGameHeaderState : i32
		{
			SAVE_GAME_HEADER_STATE_UNKNOWN,
			SAVE_GAME_HEADER_STATE_LOADING,
			SAVE_GAME_HEADER_STATE_INVALID_DEVICE,
			SAVE_GAME_HEADER_STATE_CORRUPT,
			SAVE_GAME_HEADER_STATE_EMPTY,
			SAVE_GAME_HEADER_STATE_VALID
		};

		enum Status : i32
		{
			GSLS_NONE,
			GSLS_WAITING,
			GSLS_SUCCESS,
			GSLS_FAIL
		};

		enum eGameSlotNum : i32
		{
			GAMESLOT_INVALID = -1,
			GAMESLOT_1,
			GAMESLOT_2,
			GAMESLOT_3,
			GAMESLOT_4,
			GAMESLOT_AUTOSAVE,
			NUM_GAMESAVES,

			GAMESLOT_OPTIONS = NUM_GAMESAVES,
			GAMESLOT_PHOTO_FIRST,
			GAMESLOT_PHOTO_LAS7,
			NUM_GAMESLOTS
		};

		enum eSaveDataType
		{
			DATATYPE_INVALID,
			DATATYPE_GAMESLOT_HEADER,
			DATATYPE_GAME,
			DATATYPE_OPTIONS,
			DATATYPE_PHOTO,
			NUM_DATATYPES
		};

		struct tsFlowSettings
		{
			qString m_Postfix;
			u32 m_iNumSlots;
			qString m_SaveFileTitle;
		};

		struct tsSaveGameHeaderInfo
		{
			SaveGameHeaderState m_State;
			u32 m_iGameDataSize;
			u64 m_iTimeDateStamp;
			char m_szLastMissionStringID[64];
		};

		tsFlowSettings mFlowSettings;
		Status mStatus;
		Operation mOperation;
		tsSaveGameHeaderInfo m_GameSlotHeaderInfo[8];
		HddFileContainer* mFileContainer;
		qString mActiveFolderDisplayNamePS;
		eGameSlotNum mActiveGameSlot;
		int m_iCurrentPhotoNum;
		void* m_pCurrentPhoto;
		u32 m_iCurrentPhotoSize;
		bool m_bPhotoExists[1];
		bool m_FirstLoad;

		/* Static Functions */

		SDK_SINLINE GameSaveLoad* Instance() { return SDK_VAR(GameSaveLoad*, 0x2409D30); }

		/* Functions */

		bool AbortCurrentOperation() { return SDK_CALL_FUNC(bool, 0x491D10, void*)(this); }
		void ApplyOptions() { SDK_CALL_FUNC(void, 0x4946E0, void*)(this); }
		void ApplyRumble() { SDK_CALL_FUNC(void, 0x494B20, void*)(this); }
		u32 CheckVersion(const char* data, u32 version) { return SDK_CALL_FUNC(u32, 0x496C70, void*, const char*, u32)(this, data, version); }
		void ClearGameSlotHeaderInfo() { SDK_CALL_FUNC(void, 0x497B50, void*)(this); }
		qString GetGameOptionsFullFilename() { return SDK_CALL_FUNC(qString, 0x4A3360, void*)(this); }
		qString GetGameSlotFullFilename(eGameSlotNum GameSlotNum) { return SDK_CALL_FUNC(qString, 0x4A33C0, void*, eGameSlotNum)(this, GameSlotNum); }
		qString GetSlotFullFilename(eGameSlotNum slot_num) { return SDK_CALL_FUNC(qString, 0x4A6280, void*, eGameSlotNum)(this, slot_num); }
		bool LoadGameOptions() { return SDK_CALL_FUNC(bool, 0x4AE5A0, void*)(this); }
		bool LoadSaveDataFileList() { return SDK_CALL_FUNC(bool, 0x4AEE30, void*)(this); }
		bool SaveAutoGameSlot() { return SDK_CALL_FUNC(bool, 0x4B8260, void*)(this); }
		bool SaveGameOptions() { return SDK_CALL_FUNC(bool, 0x4B8BE0, void*)(this); }
		bool SaveGameSlot(eGameSlotNum GameSlotNum) { return SDK_CALL_FUNC(bool, 0x4B8C20, void*, eGameSlotNum)(this, GameSlotNum); }
		void SetActiveFlow(const qSymbol& flowId) { SDK_CALL_FUNC(void, 0x4BB700, void*, const qSymbol&)(this, flowId); }
	};
	SDK_ASSERT_SIZEOF(GameSaveLoad, 0x328);
}