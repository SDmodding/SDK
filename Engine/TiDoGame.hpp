#pragma once

namespace UFG
{
	namespace TiDoGame
	{
		bool UnloadWwiseBank(qWiseSymbol m_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(qWiseSymbol*)>(UFG_RVA(0x14D100))(&m_BankID);
		}

		bool LoadWwiseBank(qWiseSymbol m_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(qWiseSymbol*)>(UFG_RVA(0x148D00))(&m_BankID);
		}

		bool GetVoiceId(CSimObject* m_SimObject, CVoiceProfile** m_VoiceProfile)
		{
			// Call: GetVoiceIdFromPropSet and then GetVoiceIdFromTrueCrowdInfo if result was -1
			return reinterpret_cast<bool(__fastcall*)(CSimObject*, CVoiceProfile**)>(UFG_RVA(0x59D8D0))(m_SimObject, m_VoiceProfile);
		}

		void GetVoiceIdFromPropSet(qWiseSymbol* m_Result, CSimObject* m_SimObject, CVoiceProfile** m_VoiceProfile)
		{
			reinterpret_cast<void(__fastcall*)(qWiseSymbol*, CSimObject*, CVoiceProfile**)>(UFG_RVA(0x59D970))(m_Result, m_SimObject, m_VoiceProfile);
		}

		void GetVoiceIdFromTrueCrowdInfo(qWiseSymbol* m_Result, CSimObject* m_SimObject, CVoiceProfile** m_VoiceProfile)
		{
			reinterpret_cast<void(__fastcall*)(qWiseSymbol*, CSimObject*, CVoiceProfile**)>(UFG_RVA(0x59DA60))(m_Result, m_SimObject, m_VoiceProfile);
		}
	}
}