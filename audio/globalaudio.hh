#pragma once

namespace UFG
{
	class AmbienceAudio : public AudioEntity
	{
	public:
		AudioEventController m_ambienceController;

		/* Static Functions */

		SDK_SINLINE AmbienceAudio* Instance() { return SDK_VAR_GET(AmbienceAudio*, 0x2175EC8); }

		/* Functions */

		bool PlayAmbience(u32 eventId) { return SDK_CALL_FUNC(bool, 0x5A4DB0, void*, u32)(this, eventId); }
	};

	class HudAudio : public AudioEntity
	{
	public:
		/* Static Functions */

		SDK_SINLINE HudAudio* Instance() { return SDK_VAR_GET(HudAudio*, 0x2175ED0); }

		SDK_SINLINE void PlayHudSound(u32 eventId, AudioEventInitParams* params = 0) { SDK_CALL_FUNC(void, 0x3C7FD0, u32, AudioEventInitParams*)(eventId, params); }
	};

	class Music : public AudioEntity
	{
	public:
		/* Static Members */


		SDK_VINLINE qGlobalVar<bool, 0x2036A38> sm_curPlayingMp3;
		SDK_VINLINE qGlobalVar<qList<qString>, 0x2036CE8> sm_mp3Playlist;

		SDK_VINLINE qGlobalVar<bool, 0x2175E6C> sm_playingUserMP3s;
		SDK_VINLINE qGlobalVar<bool, 0x2175E6D> sm_shuffleMP3s;

		/* Static Functions */

		SDK_SINLINE Music* Instance() { return SDK_VAR_GET(Music*, 0x2175E50); }

		SDK_SINLINE int GetNextMP3Idx() { return SDK_CALL_FUNC(int, 0x146180)(); }
		SDK_SINLINE bool MusicEvent(u32 id) { return SDK_CALL_FUNC(bool, 0x148FD0, u32)(id); }
		SDK_SINLINE void SetMusicState(u32 stateName, u32 stateMode) { SDK_CALL_FUNC(void, 0x14BFE0, u32, u32)(stateName, stateMode); }
	};
}