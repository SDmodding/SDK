//=============================================================================
// 
// Description:		Everything related to Audiokinetic/WWise (Sound Engine)
// 
//=============================================================================
#pragma once

// Typedefs
typedef _RTL_CRITICAL_SECTION CAkLock;

// Includes
#include "Types.hh"
#include "Classes.hh"

// Common (Important)
#include "Common/Indexable.hh"

// Common
#include "Common/AudioLibIndex.hh"
#include "Common/Callback.hh"
#include "Common/BankReader.hh"
#include "Common/BankMgr.hh"

namespace AK
{
	namespace SoundEngine
	{
		// Rewritten from scratch. Reference: (.text:0000000140A41FD0)
		uint32_t GetIDFromString(const char* p_Str)
		{
			uint32_t m_ID = 0x811C9DC5;
			for (; *p_Str; ++p_Str)
			{
				char m_Char = tolower(*p_Str);
				m_ID = static_cast<uint32_t>(m_Char ^ (0x1000193 * m_ID));
			}

			return m_ID;
		}

		UFG_INLINE AKRESULT LoadBank(AkBankID p_BankID, AkBankCallbackFunc p_Callback, void* p_Cookie, uint32_t p_MemPoolID)
		{
			return reinterpret_cast<AKRESULT(__fastcall*)(AkBankID, AkBankCallbackFunc, void*, int)>(UFG_RVA(0xA424A0))(p_BankID, p_Callback, p_Cookie, p_MemPoolID);
		}

		UFG_INLINE AkExternalSourceArray* PostEvent(AkBankID p_EventID, AkGameObjectID p_GameObjID, uint32_t p_Flags, AkCallbackFunc p_Callback, void* p_Cookie, uint32_t p_NumExternals, AkExternalSourceInfo* p_ExternalSources, uint32_t p_PlayingID = AK_INVALID_PLAYING_ID)
		{
			return reinterpret_cast<AkExternalSourceArray*(__fastcall*)(AkBankID, AkGameObjectID, uint32_t, AkCallbackFunc, void*, uint32_t, AkExternalSourceInfo*, uint32_t)>(UFG_RVA(0xA426F0))(p_EventID, p_GameObjID, p_Flags, p_Callback, p_Cookie, p_NumExternals, p_ExternalSources, p_PlayingID);
		}
	}
}