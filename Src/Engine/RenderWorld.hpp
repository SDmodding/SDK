#pragma once
#define RENDERWORLD_ALTCOLOR_GHOST 0xFA64CB1

namespace UFG
{
	namespace RenderWorld
	{
		void EnableAltColorEffect(bool enable) 
		{ 
			reinterpret_cast<void(__fastcall*)(bool)>(UFG_RVA(0x6FF90))(enable); 
		}

		void SetGlobalEffectUID(unsigned int uid) 
		{ 
			reinterpret_cast<void(__fastcall*)(unsigned int)>(UFG_RVA(0x708D0))(uid); 
		}

		void RequestScreenShot(void* m_Callback, float m_Scale)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, int)>(UFG_RVA(0x5AED0))(m_Callback, m_Scale, 0);
		}
	}
}