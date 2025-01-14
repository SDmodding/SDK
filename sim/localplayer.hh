#pragma once

namespace UFG
{
	SDK_SINLINE SimObjectCharacter* GetLocalPlayer() { return SDK_VAR_GET(SimObjectCharacter*, 0x235C488); }
	SDK_SINLINE bool IsAnyLocalPlayer(SimObjectCharacter* object) { return (object && object == GetLocalPlayer()); }
}