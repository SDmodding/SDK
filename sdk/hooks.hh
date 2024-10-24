#pragma once

namespace SDK
{
	class Hook
	{
	public:
		void* mOriginal;

		template <typename T = void, typename... Args>
		SDK_INLINE T operator()(Args... args) 
		{
			return (mOriginal ? reinterpret_cast<T(SDK_CALL*)(Args...)>(mOriginal)(args...) : static_cast<T>(0));
		}

		/* Create Funcs */

		void CreateCallRAX(uptr address, void* func)
		{
			if (*reinterpret_cast<u16*>(address) == 0xB848) { // mov rax
				mOriginal = *reinterpret_cast<void**>(address + 0x2);
			}
			else {
				mOriginal = nullptr;
			}

			u8 opCodes[] = { 0x48, 0xB8, 0, 0, 0, 0, 0, 0, 0, 0, 0xFF, 0xD0 };
			*reinterpret_cast<void**>(&opCodes[2]) = func;

			DWORD dwOldProtect;
			if (!VirtualProtect(reinterpret_cast<void*>(address), sizeof(opCodes), PAGE_EXECUTE_READWRITE, &dwOldProtect)) {
				return;
			}

			memcpy(reinterpret_cast<void*>(address), opCodes, sizeof(opCodes));
			VirtualProtect(reinterpret_cast<void*>(address), sizeof(opCodes), dwOldProtect, &dwOldProtect);
		}

		void CreateVFunc(uptr address, void* func)
		{
			mOriginal = *reinterpret_cast<void**>(address);

			DWORD dwOldProtect;
			if (!VirtualProtect(reinterpret_cast<void*>(address), sizeof(void*), PAGE_READWRITE, &dwOldProtect)) {
				return;
			}

			*reinterpret_cast<void**>(address) = func;
			VirtualProtect(reinterpret_cast<void*>(address), sizeof(void*), dwOldProtect, &dwOldProtect);
		}

		/* Hooks */

		SDK_INLINE void Setup_InitGameSystems(void* func) { CreateCallRAX(SDK_RVA(0x422691), func); }
		SDK_INLINE void Setup_GameStateInGame_OnUpdate(void* func) { CreateVFunc(SDK_RVA(0x1784AA8), func); }
	};
}