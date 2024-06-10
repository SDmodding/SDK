#pragma once
#define RENDERWORLD_ALTCOLOR_GHOST 0xFA64CB1

namespace UFG
{
	namespace RenderWorld
	{
		UFG_INLINE void EnableAltColorEffect(bool p_bEnable) 
		{ 
			reinterpret_cast<void(__fastcall*)(bool)>(UFG_RVA(0x6FF90))(p_bEnable);
		}

		UFG_INLINE void SetGlobalEffectUID(uint32_t p_UID)
		{ 
			reinterpret_cast<void(__fastcall*)(unsigned int)>(UFG_RVA(0x708D0))(p_UID);
		}

		UFG_INLINE void RequestScreenShot(void* p_fnCallback, float p_fScale)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, int)>(UFG_RVA(0x5AED0))(p_fnCallback, p_fScale, 0);
		}
	}
}