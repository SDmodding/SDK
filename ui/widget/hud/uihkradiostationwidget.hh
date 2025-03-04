#pragma once

namespace UFG
{
	class UIHKRadioStationData
	{
	public:
		qString texturePack;
		qString texture;
	};

	class UIHKRadioStationWidget
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_SHOULD_ACTIVATE,
			STATE_ACTIVE,
			STATE_FADING_OUT
		};

		eState mState;
		bool mChanged;
		bool mVisible;
		bool mShouldRefreshTextures;
		bool mWaitingForTexture;
		u32 mCurrentStation;
		f32 mTimeSinceLastInput;
		f32 mWaitingForTextureTimer;
		qArray<UIHKRadioStationData> mStationData;
		qString mLoadedTexturePack;

		/* Impl Functions */

		SDK_INLINE void HandleNewSong() { mChanged = 1; }
		SDK_INLINE bool IsActive() { return mState && mState != STATE_FADING_OUT; }

		/* Functions */

		void ChangeStation(u32 stationID) { SDK_CALL_FUNC(void, 0x5D4C80, void*, u32)(this, stationID); }
		void Flash_Intro(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DE590, void*, UIScreen*)(this, screen); }
		void Flash_SetSongTitle(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E0D10, void*, UIScreen*)(this, screen); }
		void Flash_SetStationName(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E0E40, void*, UIScreen*)(this, screen); }
		void Flash_SetTexture(UIScreen* screen, const char* texture) { SDK_CALL_FUNC(void, 0x5E1310, void*, UIScreen*, const char*)(this, screen, texture); }
		void Flash_SetVisible(UIScreen* screen, bool visible) { SDK_CALL_FUNC(void, 0x5E1D20, void*, UIScreen*, bool)(this, screen, visible); }
		void LoadTextures(int oldStationIdx, int newStationIdx) { SDK_CALL_FUNC(void, 0x5F1870, void*, int, int)(this, oldStationIdx, newStationIdx); }
		void OnRadioTurnedOff() { SDK_CALL_FUNC(void, 0x5F2EF0, void*)(this); }
		void ReadStationList() { SDK_CALL_FUNC(void, 0x5FF110, void*)(this); }
	};
}