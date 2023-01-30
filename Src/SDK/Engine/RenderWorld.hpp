#pragma once
#define RENDERWORLD_ALTCOLOR_GHOST 0xFA64CB1

namespace UFG
{
	namespace RenderWorld
	{
		void EnableAltColorEffect(bool enable) { reinterpret_cast<void(__fastcall*)(bool)>(UFG_RVA(0x6FF90))(enable); }
		void SetGlobalEffectUID(unsigned int uid) { reinterpret_cast<void(__fastcall*)(unsigned int)>(UFG_RVA(0x708D0))(uid); }
	}
}