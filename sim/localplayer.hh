#pragma once

namespace UFG
{
	SDK_SINLINE SimObjectCharacter* GetLocalPlayer() { return SDK_VAR_GET(SimObjectCharacter*, 0x235C488); }
	SDK_SINLINE qSymbol GetPlayerPropertySetNameUID() { return 0xBD387BEE; } // object-physical-character-player

	SDK_SINLINE bool IsAnyLocalPlayer(SimObjectCharacter* object) { return (object && object == GetLocalPlayer()); }
	SDK_SINLINE bool IsLocalPlayer(SimObject* object) { return (object && object->m_Name.mUID == 0x90ECB5FF); } // (m_Name == "PlayerOne_Havok")
}