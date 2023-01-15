#include <windows.h>
#include <algorithm>
#include <string>

#include "SDK/_Includes.hpp"
#include "Utils/VMTHook.hpp"

#include "Hooks/_Includes.hpp"

DWORD __stdcall MainThread(void* m_pReserved)
{
    Hook::Init();

    while (!GetAsyncKeyState(VK_DELETE)) Sleep(10);

    Hook::Uninit();

    Sleep(1000);

    Hook::PresentCleanup();

    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(m_pReserved), 0x0);
    return 0;
}

int __stdcall DllMain(HMODULE m_hModule, DWORD m_dReason, void* m_pReserved)
{
    if (m_dReason == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, MainThread, m_hModule, 0, 0);

    return 1;
}