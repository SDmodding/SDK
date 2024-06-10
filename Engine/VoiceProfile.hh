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

		UFG_INLINE bool BankRequiredForExertions()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x596FF0))(this);
		}
	};

	namespace VoiceProfileManager
	{
		UFG_INLINE CVoiceProfile* AddOrGetVoiceProfile(const char* p_szVoiceName, qWiseSymbol p_qVoiceTag)
		{
			return reinterpret_cast<CVoiceProfile*(__fastcall*)(const char* , qWiseSymbol*)>(UFG_RVA(0x596590))(p_szVoiceName, &p_qVoiceTag);
		}

		UFG_INLINE CVoiceProfile* AssignVoice(CSimObject* p_SimObject)
		{
			return reinterpret_cast<CVoiceProfile*(__fastcall*)(CSimObject*)>(UFG_RVA(0x596970))(p_SimObject);
		}

		UFG_INLINE CVoiceProfile* AssignVoice(qPropertySet* p_PropertySet)
		{
			return reinterpret_cast<CVoiceProfile*(__fastcall*)(qPropertySet*)>(UFG_RVA(0x596CE0))(p_PropertySet);
		}
	}
}