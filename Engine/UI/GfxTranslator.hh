#pragma once

namespace UFG
{
	class CUIGfxTranslator
	{
	public:
		char* Translate(uint32_t p_Hash) 
		{ 
			return reinterpret_cast<char*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0xA28340))(this, p_Hash);
		}

		UFG_INLINE char* Translate(const char* p_String)
		{ 
			return Translate(HashUpper32(p_String));
		}
	};
}