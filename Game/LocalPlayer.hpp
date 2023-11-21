#pragma once

namespace UFG
{
	namespace LocalPlayer
	{
		__inline CSimCharacter** GetPointer()
		{
			return reinterpret_cast<CSimCharacter**>(UFG_RVA(0x235C488));
		}

		__inline CSimCharacter* Get()
		{
			return *GetPointer();
		}

		__forceinline qSymbol GetNameUID()
		{
			return 0x90ECB5FF;
		}

		__forceinline qSymbol GetPropertySetUID()
		{
			return 0xBD387BEE; // object-physical-character-player
		}
	}
}