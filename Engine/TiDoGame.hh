#pragma once

namespace UFG
{
	namespace TiDoGame
	{
		UFG_INLINE bool UnloadWwiseBank(qWiseSymbol p_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(qWiseSymbol*)>(UFG_RVA(0x14D100))(&p_BankID);
		}

		UFG_INLINE bool LoadWwiseBank(qWiseSymbol p_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(qWiseSymbol*)>(UFG_RVA(0x148D00))(&p_BankID);
		}

		UFG_INLINE bool GetVoiceId(SimObject* p_SimObject, CVoiceProfile** p_VoiceProfile)
		{
			// Call: GetVoiceIdFromPropSet and then GetVoiceIdFromTrueCrowdInfo if result was -1
			return reinterpret_cast<bool(__fastcall*)(SimObject*, CVoiceProfile**)>(UFG_RVA(0x59D8D0))(p_SimObject, p_VoiceProfile);
		}

		UFG_INLINE void GetVoiceIdFromPropSet(qWiseSymbol* p_Result, SimObject* p_SimObject, CVoiceProfile** p_VoiceProfile)
		{
			reinterpret_cast<void(__fastcall*)(qWiseSymbol*, SimObject*, CVoiceProfile**)>(UFG_RVA(0x59D970))(p_Result, p_SimObject, p_VoiceProfile);
		}

		UFG_INLINE void GetVoiceIdFromTrueCrowdInfo(qWiseSymbol* p_Result, SimObject* p_SimObject, CVoiceProfile** p_VoiceProfile)
		{
			reinterpret_cast<void(__fastcall*)(qWiseSymbol*, SimObject*, CVoiceProfile**)>(UFG_RVA(0x59DA60))(p_Result, p_SimObject, p_VoiceProfile);
		}
	}
}