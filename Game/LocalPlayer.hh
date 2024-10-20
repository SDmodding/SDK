#pragma once

namespace UFG
{
	namespace LocalPlayer
	{
		UFG_INLINE SimCharacter** GetPointer()
		{
			return reinterpret_cast<SimCharacter**>(UFG_RVA(0x235C488));
		}

		UFG_INLINE SimCharacter* Get()
		{
			return *GetPointer();
		}

		UFG_INLINE qSymbol GetNameUID()
		{
			return 0x90ECB5FF;
		}

		UFG_INLINE qSymbol GetPropertySetUID()
		{
			return 0xBD387BEE; // object-physical-character-player
		}
	}
}