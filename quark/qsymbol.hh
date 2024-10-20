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
}