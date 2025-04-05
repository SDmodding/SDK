#pragma once

namespace UFG
{
	enum PoliceVoiceType
	{
		ePoliceVoiceType_Police,
		ePoliceVoiceType_Heat
	};

	class SpeechObject
	{
	public:
		u32 m_eventId;
		u32 m_contextId;
		PoliceVoiceType m_voice;
		const char* m_context;
		u32 m_msMinDelay;
		u32 m_msMaxDelay;
	};

	class SpeechScenario : public qNodeRB<SpeechScenario>
	{
	public:
		char m_szName[128];
		qArray<SpeechObject> m_ObjectArray;
	};

	class PoliceScannerAudio : public AudioEntity
	{
	public:
		int m_previousPoliceVoices[2];
		int m_previousHeatVoices[2];
		bool m_enabled;
		AudioEntity* m_pOwnerEntity;
		qTreeRB<SpeechScenario> m_Scenarios;
		AudioDialogEventController m_Controller;

		/* Static Functions */

		SDK_SINLINE PoliceScannerAudio* Instance() { return SDK_VAR_GET(PoliceScannerAudio*, 0x242F0F0); }

		/* Impl Functions */

		SDK_INLINE void AttachToAudioEntity(AudioEntity* pEntity) { m_pOwnerEntity = pEntity; }
		SDK_INLINE void DetachFromAudioEntity(AudioEntity* pEntity) { m_pOwnerEntity = 0; }
		SDK_INLINE bool IsOwnedBy(AudioEntity* pEntity) { return m_pOwnerEntity == pEntity; }

		/* Functions */

		void Enable(bool isEnabled) { SDK_CALL_FUNC(void, 0x59B5F0, void*, bool)(this, isEnabled); }
		const char* GenerateRandomHeatVoice() { return SDK_CALL_FUNC(const char*, 0x59CBF0, void*)(this); }
		const char* GenerateRandomVoice() { return SDK_CALL_FUNC(const char*, 0x59CC60, void*)(this); }
		void LoadScenarios() { SDK_CALL_FUNC(void, 0x5A1B50, void*)(this); }
		void OnHeatLevelIncrease(u32 newHeatLevel) { SDK_CALL_FUNC(void, 0x5A4380, void*, u32)(this, newHeatLevel); }
		void PlayClick() { SDK_CALL_FUNC(void, 0x5A5010, void*)(this); }
		bool PlayScenario(const char* pszScenarioName) { return SDK_CALL_FUNC(bool, 0x5A7030, void*, const char*)(this, pszScenarioName); }
	};
}