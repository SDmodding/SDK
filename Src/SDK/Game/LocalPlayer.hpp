#pragma once

namespace UFG
{
	namespace LocalPlayer
	{
		CSimCharacter* Get()
		{
			return *reinterpret_cast<CSimCharacter**>(UFG_RVA(0x235C488));
		}

		__forceinline qSymbol GetNameUID()
		{
			return 0x90ECB5FF;
		}
	}
}