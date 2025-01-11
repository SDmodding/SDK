#pragma once

namespace UFG
{
	class qSymbol
	{
	public:
		u32 mUID;

		qSymbol() : mUID(-1) {}
		qSymbol(u32 uid) : mUID(uid) {}
		qSymbol(const qSymbol& source) : mUID(source.mUID) {}
		qSymbol(const char* pszSymbolString) { SDK_CALL_FUNC(void, 0x18DC30, void*, const char*)(this, pszSymbolString); }
	};

	class qSymbolUC
	{
	public:
		u32 mUID;

		qSymbolUC() : mUID(-1) {}
		qSymbolUC(u32 uid) : mUID(uid) {}
		qSymbolUC(const qSymbolUC& source) : mUID(source.mUID) {}
	};

	class qNamed
	{
	public:
		qSymbol i_name;
	};
}