#pragma once

namespace UFG
{
	class qWiseSymbol
	{
	public:
		u32 mUID; 
		
		qWiseSymbol() : mUID(-1) {}
		qWiseSymbol(u32 uid) : mUID(uid) {}
	};
}