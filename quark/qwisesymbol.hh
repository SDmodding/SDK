#pragma once

namespace UFG
{
	class qWiseSymbol
	{
	public:
		u32 mUID; 
		
		SDK_INLINE qWiseSymbol() : mUID(-1) {}
		SDK_INLINE qWiseSymbol(u32 uid) : mUID(uid) {}
		SDK_INLINE qWiseSymbol(const qWiseSymbol& source) : mUID(source.mUID) {}
		SDK_INLINE qWiseSymbol(const char* pszSymbolString) { SDK_CALL_FUNC(void, 0x180950, void*, const char*)(this, pszSymbolString); }

		SDK_INLINE void operator=(u32 uid) { mUID = uid; }
		SDK_INLINE bool operator==(const qWiseSymbol& sym) const { return mUID == sym.mUID; }
		SDK_INLINE bool operator!=(const qWiseSymbol& sym) const { return !operator==(sym); }
	};
}