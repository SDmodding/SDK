#pragma once

namespace UFG
{
	class VoiceProfile : public qNodeRB<VoiceProfile>
	{
	public:
		qWiseSymbol m_wwiseVoiceUid;
		qWiseSymbol m_wwiseTagsUid;
		qString m_subtitleSet;
		u32 m_weight;
		BitFlags128 m_bitFlags;
		bool m_isTrueCrowd : 1;
		bool m_loadSubtitlesOnBoot : 1;

		virtual ~VoiceProfile() = 0;

		bool BankRequiredForExertions() { return SDK_CALL_FUNC(bool, 0x596FF0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(VoiceProfile, 0x78);

	class VoiceProfileManager
	{
	public:
		/* Static Functions */

		SDK_SINLINE VoiceProfile* AddOrGetVoiceProfile(const char* voiceStr, const qWiseSymbol* tag_voice) {
			return SDK_CALL_FUNC(VoiceProfile*, 0x596590, const char*, const qWiseSymbol*)(voiceStr, tag_voice);
		}

		SDK_SINLINE VoiceProfile* AssignVoice(SimObject* simObject) { return SDK_CALL_FUNC(VoiceProfile*, 0x596970, SimObject*)(simObject); }
		SDK_SINLINE VoiceProfile* AssignVoice(qPropertySet* pSet) { return SDK_CALL_FUNC(VoiceProfile*, 0x596CE0, qPropertySet*)(pSet); }
		SDK_SINLINE BitFlags128 BuildBitFlags(SimObject* simObject) { return SDK_CALL_FUNC(BitFlags128, 0x597290, SimObject*)(simObject); }
		SDK_SINLINE BitFlags128 BuildBitFlags(qPropertySet* pSet) { return SDK_CALL_FUNC(BitFlags128, 0x5973B0, qPropertySet*)(pSet); }
		SDK_SINLINE void LoadVoiceProfiles() { SDK_CALL_FUNC(void, 0x5A29A0)(); }
		SDK_SINLINE void SetTagVoice(VoiceProfile* profile) { SDK_CALL_FUNC(void, 0x5AB370, VoiceProfile*)(profile); }
	};
}