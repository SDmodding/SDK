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