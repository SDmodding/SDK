#pragma once

namespace UFG
{
	namespace LocalPlayer
	{
		CSimCharacter** GetPointer()
		{
			return reinterpret_cast<CSimCharacter**>(UFG_RVA(0x235C488));
		}

		CSimCharacter* Get()
		{
			return *GetPointer();
		}

		__forceinline qSymbol GetNameUID()
		{
			return 0x90ECB5FF;
		}
	}
}