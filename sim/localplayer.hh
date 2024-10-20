#pragma once

namespace UFG
{
	SDK_SINLINE SimObjectCharacter* GetLocalPlayer() { return *reinterpret_cast<SimObjectCharacter**>(SDK_RVA(0x235C488)); }
	SDK_SINLINE bool IsAnyLocalPlayer(SimObjectCharacter* object) { return (object && object == GetLocalPlayer()); }
}