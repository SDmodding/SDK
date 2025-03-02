#pragma once

namespace UFG
{
	class UIHK_PDAPhoneContactsWidget
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_LOADING_TEXTURES,
			STATE_SHOULD_ACTIVATE,
			STATE_ACTIVE,
			STATE_EMPTY,
			STATE_VIEWING_MSG,
			STATE_SHOULD_EXIT,
			NUM_STATES
		};

		struct UIHKTxtMsgInfo
		{
			qString message;
			qSymbol symbol;
		};

		eState mState;
		u32 mNumContacts;
		u32 mSelectedIndex;
		u32 mSelectedSubOptionIndex;
		qString mSelectedName;
		qString mSelectedSubOption;
		qArray<qString> mMissionList;
		qArray<UIHKTxtMsgInfo> mMessages;
		qPropertySet* mData;
		qPropertySet* mContactData;
		qString mTraceName;
		qSymbol mTraceSymbol;
		qString mPerkGiverName;
		qSymbol mPerkGiverSymbol;
		bool mShowingPerkIcon;
		bool mDisablePerk;
		bool mUpdateContactMethod;
		qSymbol mSelectedSymbol;
		qArray<qSymbol> mSymbolList;
		qArray<qString> mNameList;
		qArray<qString> mPortraitList;

		/* Virtual Functions */

		virtual ~UIHK_PDAPhoneContactsWidget() = 0;

		/* Functions */

		void AddContact(UIScreen* screen, const qSymbol& sym, const char* name, const char* portrait) {
			SDK_CALL_FUNC(void, 0x5D1AA0, void*, UIScreen*, const qSymbol&, const char*, const char*)(this, screen, sym, name, portrait);
		}

		void Exit(UIScreen* screen, bool playSound) { SDK_CALL_FUNC(void, 0x5D7D50, void*, UIScreen*, bool)(this, screen, playSound); }
		void FindAndAddContact(UIScreen* screen, const qSymbol& contactID) { SDK_CALL_FUNC(void, 0x5D8560, void*, UIScreen*, const qSymbol&)(this, screen, contactID); }
		void Flash_Activate(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5D9030, void*, UIScreen*)(this, screen); }
		const char* GetActivePerk() { return SDK_CALL_FUNC(const char*, 0x5E69C0, void*)(this); }
		u32 GetSectedIndex(UIScreen* screen) { return SDK_CALL_FUNC(u32, 0x5E8B40, void*, UIScreen*)(this, screen); }
		void GetSelectedName(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E90B0, void*, UIScreen*)(this, screen); }
		char HandleMessage(UIScreen* screen, u32 msgId) { return SDK_CALL_FUNC(char, 0x5EB380, void*, UIScreen*, u32)(this, screen, msgId); }

		void LaunchCallMission(const qSymbol& contact, const qString& name, const qString& portrait) {
			SDK_CALL_FUNC(void, 0x5F0610, void*, const qSymbol&, const qString&, const qString&)(this, contact, name, portrait);
		}

		void LaunchSubOption(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5F0740, void*, UIScreen*)(this, screen); }
		void LoadTexturePack() { SDK_CALL_FUNC(void, 0x5F1640, void*)(this); }
		int PopulateList(UIScreen* screen) { return SDK_CALL_FUNC(int, 0x5F97E0, void*, UIScreen*)(this, screen); }
		bool ProcessInput(UIScreen* screen, u32 msgId) { return SDK_CALL_FUNC(bool, 0x5FE760, void*, UIScreen*, u32)(this, screen, msgId); }
		void ScrollNext() { SDK_CALL_FUNC(void, 0x603F20, void*)(this); }
		void ScrollPrev() { SDK_CALL_FUNC(void, 0x604270, void*)(this); }
		void SetSubMenuIcon(UIScreen* screen, int slotIndex, const char* iconName) { SDK_CALL_FUNC(void, 0x609E20, void*, UIScreen*, int, const char*)(this, screen, slotIndex, iconName); }
	};
	SDK_ASSERT_SIZEOF(UIHK_PDAPhoneContactsWidget, 0x130);
}