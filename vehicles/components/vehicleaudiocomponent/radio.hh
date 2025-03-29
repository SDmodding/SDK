#pragma once

namespace UFG
{
	enum eRadioStationAssetType
	{
		eRadioStationAssetType_Track,
		eRadioStationAssetType_Dj,
		eRadioStationAssetType_Ad,
		eRadioStationAssetType_Ident,
		eRadioStationAssetType_Max
	};

	class RadioStationAsset : public qNode<RadioStationAsset>
	{
	public:
		char m_index;
		eRadioStationAssetType m_type;
		u32 m_assetId;
		bool m_isSeekable : 1;
	};

	class TrackAsset : public RadioStationAsset
	{
	public:
		u32 m_trackUID;
		char* m_trackName;
		char* m_artistName;
	};

	class DJAsset : public RadioStationAsset
	{
	public:
		u32 m_afterTracksEvent;
		u32 m_beforeTracksEvent;
		TrackAsset* m_trackAssets[3];
	};

	class RadioStationProgram : public qNode<RadioStationProgram>
	{
	public:
		s8 m_startIndex;
		s8 m_endIndex;
		s8 m_startTime;
		s8 m_endTime;
	};

	class RadioStation : public qNode<RadioStation>
	{
	public:
		f32 m_timeSinceStarted;
		f32 m_timeSinceStopped;
		f32 m_currentTrackTimer;
		u32 m_id;
		u32 m_numAssets;
		u32 m_assetCount[4];
		u32 m_firstAssetIndex[4];
		u32 m_numRecentlyPlayed;
		u32 m_numConsecutiveTracks;
		f32 m_percentTrack;
		f32 m_percentAd;
		f32 m_percentDj;
		char m_name[64];
		qString m_textureName;
		qString m_texturePack;
		qString m_currentlyPlayingAssetName;
		qWiseSymbol m_bankId;
		RadioStationAsset* m_currentlyPlaying;
		qList<RadioStationProgram> m_programs;
		qList<RadioStationAsset> m_assets;
		qList<qPointerNode<RadioStationAsset>> m_playList;
		qList<qPointerNode<RadioStationAsset>> m_prevPlayed;
		bool m_bIsRaceStation;
		bool m_bIsCopScannerStation;

		/* Virtual Functions */

		virtual ~RadioStation() = 0;

		/* Functions */

		void AddCurrentlyPlayingToRecentlyPlayed() { SDK_CALL_FUNC(void, 0x66F410, void*)(this); }
		void AddDjAssetToPlaylist(DJAsset* djAsset) { SDK_CALL_FUNC(void, 0x66F7F0, void*, DJAsset*)(this, djAsset); }
		void AddToPlaylist(const char* id, bool isSeekable) { SDK_CALL_FUNC(void, 0x66FF70, void*, const char*, bool)(this, id, isSeekable); }
		void AddToPlaylist(u32 id, bool isSeekable) { SDK_CALL_FUNC(void, 0x66FEB0, void*, u32, bool)(this, id, isSeekable); }
		eRadioStationAssetType DetermineAssetType() { return SDK_CALL_FUNC(eRadioStationAssetType, 0x6767C0, void*)(this); }
		u32 GetNextTrack() { return SDK_CALL_FUNC(u32, 0x67AA80, void*)(this); }
		bool IsInCurrentProgram(u32 index) { return SDK_CALL_FUNC(bool, 0x67F250, void*, u32)(this, index); }
		void RandomizePlaylist() { SDK_CALL_FUNC(void, 0x688460, void*)(this); }
		void SetCurrentlyPlaying(RadioStationAsset* currentlyPlaying) { SDK_CALL_FUNC(void, 0x68A500, void*, RadioStationAsset*)(this, currentlyPlaying); }
		void SetupAdAsset(char index) { SDK_CALL_FUNC(void, 0x68B7B0, void*, char)(this, index); }
		void SetupIdentAsset() { SDK_CALL_FUNC(void, 0x68B870, void*)(this); }
		void SetupTrackAsset(u32 index, const char* artistName, const char* trackName) { SDK_CALL_FUNC(void, 0x68BBB0, void*, u32, const char*, const char*)(this, index, artistName, trackName); }
	};

	class Radio : public AudioEntity
	{
	public:
		enum eRadioType
		{
			eRadioType_Radio,
			eRadioType_Scanner,
			eRadioType_RadioWithScanner
		};

		VehicleAudioComponent* m_pVehAudComponent;
		RadioStation* m_curStation;
		AudioEventController m_ecRadio;
		bool m_bRadioEnabled : 1;
		bool m_isPlaying : 1;
		bool m_isTurnedOff : 1;
		bool m_bStartTrack : 1;
		bool m_bSkipTrack : 1;
		bool m_bNextStation : 1;
		bool m_bPrevStation : 1;
		bool m_bSeek : 1;
		bool m_bTrackWasStopped : 1;
		f32 m_buttonHoldLength;
		f32 m_timeSinceRadioStarted;
		f32 m_timeSinceRadioStopped;
		f32 m_timeSinceStationChanged;
		bool m_ignoreRelease;
		eRadioType m_radioType;
		u32 m_adjacentNextStationCount;
		u32 m_adjacentPrevStationCount;

		/* Static Functions */

		SDK_SINLINE void ClearRadioStationData() { SDK_CALL_FUNC(void, 0x6745F0)(); }
		SDK_SINLINE void LoadRadioStationData() { SDK_CALL_FUNC(void, 0x67F730)(); }

		/* Impl Functions */

		SDK_INLINE void SetRadioType(eRadioType type) { m_radioType = type; }
		SDK_INLINE void StartTrack(bool skipTrack) { m_bStartTrack = 1; m_bSkipTrack = skipTrack; }

		/* Functions */

		void AdvanceAllStations(f32 delta_sec) { SDK_CALL_FUNC(void, 0x6707D0, void*, f32)(this, delta_sec); }
		void ClearAllPlaylists() { SDK_CALL_FUNC(void, 0x6743D0, void*)(this); }
		void DecreaseRadioVolume() { SDK_CALL_FUNC(void, 0x676250, void*)(this); }
		void DoStartTrack() { SDK_CALL_FUNC(void, 0x676F00, void*)(this); }
		RadioStation* FindRadioStation(const qSymbol& name) { return SDK_CALL_FUNC(RadioStation*, 0x678C20, const qSymbol&)(name); }
		void GetNextStationId() { SDK_CALL_FUNC(void, 0x67A990, void*)(this); }
		void GetPrevStationId() { SDK_CALL_FUNC(void, 0x67AFE0, void*)(this); }
		void HandleInputs() { SDK_CALL_FUNC(void, 0x67C650, void*)(this); }
		void IncreaseRadioVolume() { SDK_CALL_FUNC(void, 0x67D430, void*)(this); }
		void NextStation(bool displayStationId) { SDK_CALL_FUNC(void, 0x681D70, void*, bool)(this, displayStationId); }
		void PlayClick() { SDK_CALL_FUNC(void, 0x686D20, void*)(this); }
		bool PlayerInVehicle() { return SDK_CALL_FUNC(bool, 0x687500, void*)(this); }
		void PrevStation(bool displayStationId) { SDK_CALL_FUNC(void, 0x687600, void*, bool)(this, displayStationId); }
		void SetCurStation(RadioStation* station) { SDK_CALL_FUNC(void, 0x68A490, void*, RadioStation*)(this, station); }
		void SetRadioVolume(f32 volume) { SDK_CALL_FUNC(void, 0x68B180, void*, f32)(this, volume); }
		void SetStation(u32 stationIdx) { SDK_CALL_FUNC(void, 0x68B5B0, void*, u32)(this, stationIdx); }
		void SetupParams(int station) { SDK_CALL_FUNC(void, 0x68B930, void*, int)(this, station); }
		bool StopTrack(int fadeOut) { return SDK_CALL_FUNC(bool, 0x68CA90, void*, int)(this, fadeOut); }
		void TurnOffRadio(bool playClick) { SDK_CALL_FUNC(void, 0x68DE80, void*, bool)(this, playClick); }
		void TurnOnRadio() { SDK_CALL_FUNC(void, 0x68E9D0, void*)(this); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x6932B0, void*, f32)(this, delta_sec); }
		void UpdateTrackTimers(f32 delta_sec) { SDK_CALL_FUNC(void, 0x69A530, void*, f32)(this, delta_sec); }
	};

	class RadioFullyControlled : public Radio
	{
	public:
		/* Functions */

		const char* GetCurrentlyPlayingSong() { return SDK_CALL_FUNC(const char*, 0x67A220, void*)(this); }
		void Init(const qSymbol& name) { SDK_CALL_FUNC(void, 0x67D470, void*, const qSymbol&)(this, name); }
		void NextStation(bool displayStationId) { SDK_CALL_FUNC(void, 0x681E80, void*, bool)(this, displayStationId); }
		void NextTrack() { SDK_CALL_FUNC(void, 0x681EC0, void*)(this); }
		void PrevStation(bool displayStationId) { SDK_CALL_FUNC(void, 0x687710, void*, bool)(this, displayStationId); }
		void SetupScannerAndRadio(RadioStation* prevStation, RadioStation* curStation) { SDK_CALL_FUNC(void, 0x68BAD0, void*, RadioStation*, RadioStation*)(this, prevStation, curStation); }
		void TurnOffRadio(bool playClick) { SDK_CALL_FUNC(void, 0x68DEF0, void*, bool)(this, playClick); }
		void TurnOnRadio() { SDK_CALL_FUNC(void, 0x68EA60, void*)(this); }
	};
}