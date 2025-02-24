#pragma once

namespace SDK
{
	class Hook
	{
	private:
		void* mOriginal = 0;
	public:
		/* Original Callers */

		template <typename T = void, typename... Args>
		SDK_INLINE T Original(Args... args) { return (mOriginal ? reinterpret_cast<T(SDK_CALL*)(Args...)>(mOriginal)(args...) : static_cast<T>(0)); }

		template <typename T = void, typename... Args>
		SDK_INLINE T operator()(Args... args) { return Original<T, Args...>(args...); }

		/* Initializers */

		void I_CallRax(uptr address, void* func)
		{
			if (*reinterpret_cast<u16*>(address) == 0xB848) { // mov rax
				mOriginal = *reinterpret_cast<void**>(address + 0x2);
			}

			u8 opCodes[] = { 
				0x48, 0xB8, 0, 0, 0, 0, 0, 0, 0, 0, // mov rax, ?
				0xFF, 0xD0 							// call rax
			};

			DWORD dwOldProtect;
			if (!VirtualProtect(reinterpret_cast<void*>(address), sizeof(opCodes), PAGE_EXECUTE_READWRITE, &dwOldProtect)) {
				return;
			}

			*reinterpret_cast<void**>(&opCodes[2]) = func;
			memcpy(reinterpret_cast<void*>(address), opCodes, sizeof(opCodes));

			VirtualProtect(reinterpret_cast<void*>(address), sizeof(opCodes), dwOldProtect, &dwOldProtect);
		}

		void I_FuncPtr(uptr address, void* func)
		{
			DWORD dwOldProtect;
			if (!VirtualProtect(reinterpret_cast<void*>(address), sizeof(void*), PAGE_READWRITE, &dwOldProtect)) {
				return;
			}

			mOriginal = *reinterpret_cast<void**>(address);
			*reinterpret_cast<void**>(address) = func;
			VirtualProtect(reinterpret_cast<void*>(address), sizeof(void*), dwOldProtect, &dwOldProtect);
		}

		/* Initializer Wrappers */

		SDK_INLINE void I_InitGameSystems(void* func) { I_CallRax(SDK_RVA(0x422691), func); }

		enum ESceneObjectProperties
		{
			SceneObjectProperties_Activate,
			SceneObjectProperties_Deactivate = 0x8,
			SceneObjectProperties_SimObjectFactory = 0x10
		};

		SDK_INLINE void I_SceneObjectProperties(ESceneObjectProperties sceneObject, void* func) { I_FuncPtr(SDK_RVA(0x23A9D10 + sceneObject), func); }

		enum EGameState
		{
			GameState_OnPreUpdate,
			GameState_OnPostUpdate = 0x8,
			GameState_OnEnter = 0x10,
			GameState_OnUpdate = 0x18,
			GameState_OnExit = 0x20
		};

		SDK_INLINE void I_GameStateChangeLocation(EGameState gameState, void* func) { I_FuncPtr(SDK_RVA(0x1784B80 + gameState), func); }
		SDK_INLINE void I_GameStateInGame(EGameState gameState, void* func) { I_FuncPtr(SDK_RVA(0x1784A90 + gameState), func); }
		SDK_INLINE void I_GameStateLoadChallenge(EGameState gameState, void* func) { I_FuncPtr(SDK_RVA(0x1784C90 + gameState), func); }
		SDK_INLINE void I_GameStateLoadGame(EGameState gameState, void* func) { I_FuncPtr(SDK_RVA(0x17846A0 + gameState), func); }
		SDK_INLINE void I_GameStateLoadNIS(EGameState gameState, void* func) { I_FuncPtr(SDK_RVA(0x1784D50 + gameState), func); }
		SDK_INLINE void I_GameStateRestoreCheckpoint(EGameState gameState, void* func) { I_FuncPtr(SDK_RVA(0x1784700 + gameState), func); }
	};
}