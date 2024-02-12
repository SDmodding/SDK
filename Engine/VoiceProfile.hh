#pragma once

namespace UFG
{
	class CVoiceProfile
	{
	public:
		void* vfptr;
		qNodeRB m_Node;
		qWiseSymbol m_wwiseVoiceUid;
		qWiseSymbol m_wwiseTagsUid;
		qString m_subtitleSet;
		uint32_t m_weight;
		BitFlags128 m_bitFlags;
		__int8 m_isTrueCrowd : 1;
		__int8 m_loadSubtitlesOnBoot : 1;

		bool BankRequiredForExertions()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x596FF0))(this);
		}
	};

	namespace VoiceProfileManager
	{
		CVoiceProfile* AddOrGetVoiceProfile(const char* m_VoiceName, qWiseSymbol m_VoiceTag)
		{
			return reinterpret_cast<CVoiceProfile*(__fastcall*)(const char* , qWiseSymbol*)>(UFG_RVA(0x596590))(m_VoiceName, &m_VoiceTag);
		}

		CVoiceProfile* AssignVoice(CSimObject* m_SimObject)
		{
			return reinterpret_cast<CVoiceProfile*(__fastcall*)(CSimObject*)>(UFG_RVA(0x596970))(m_SimObject);
		}

		CVoiceProfile* AssignVoice(qPropertySet* m_PropertySet)
		{
			return reinterpret_cast<CVoiceProfile*(__fastcall*)(qPropertySet*)>(UFG_RVA(0x596CE0))(m_PropertySet);
		}
	}
}