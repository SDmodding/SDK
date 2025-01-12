#pragma once

namespace UFG
{
	SDK_SINLINE void EnableAltColorEffect(bool enable) { SDK_CALL_FUNC(void, 0x6FF90, bool)(enable); }
	SDK_SINLINE void SetAltColorEffectActiveGlobally(bool bEnable) { SDK_CALL_FUNC(void, 0x70890, bool)(bEnable); }
	SDK_SINLINE void SetGlobalEffectUID(u32 uid) { SDK_CALL_FUNC(void, 0x708D0, u32)(uid); }
}