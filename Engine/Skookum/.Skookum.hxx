#pragma once

typedef uint32_t ASymbol;
typedef void* SSInstance;

namespace UFG
{
	namespace SkookumMgr
	{
		__inline void InvokeWorldCoroutine(ASymbol p_CoroutineName, SSInstance* p_Arg)
		{
			reinterpret_cast<void(__fastcall*)(ASymbol*, SSInstance*)>(UFG_RVA(0x4E2180))(&p_CoroutineName, p_Arg);
		}
	}
}