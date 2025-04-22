#pragma once

namespace UFG
{
	class qSymbol
	{
	public:
		u32 mUID;

		SDK_INLINE qSymbol() : mUID(-1) {}
		SDK_INLINE qSymbol(u32 uid) : mUID(uid) {}
		SDK_INLINE qSymbol(const qSymbol& source) : mUID(source.mUID) {}

		void set_from_cstr(const char* pszSymbolString) { SDK_CALL_FUNC(void, 0x18DC30, void*, const char*)(this, pszSymbolString); }

		SDK_INLINE operator u32() const { return mUID; }
		SDK_INLINE void operator=(u32 uid) { mUID = uid; }
	};

	class qSymbolUC
	{
	public:
		u32 mUID;

		SDK_INLINE qSymbolUC() : mUID(-1) {}
		SDK_INLINE qSymbolUC(u32 uid) : mUID(uid) {}
		SDK_INLINE qSymbolUC(const qSymbolUC& source) : mUID(source.mUID) {}

		void set_from_cstr(const char* pszSymbolString) { SDK_CALL_FUNC(void, 0x18DC80, void*, const char*)(this, pszSymbolString); }

		SDK_INLINE operator u32() const { return mUID; }
		SDK_INLINE void operator=(u32 uid) { mUID = uid; }
	};

	class qNamed
	{
	public:
		qSymbol i_name;
	};
}