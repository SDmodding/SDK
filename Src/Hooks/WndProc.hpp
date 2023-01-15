#pragma once

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace WndProc
{
    typedef LRESULT(__stdcall* m_tHook)(HWND, UINT, WPARAM, LPARAM); 
    m_tHook m_oHook;

    LRESULT __stdcall Hook(const HWND m_hWindow, UINT m_uMsg, WPARAM m_wParam, LPARAM m_lParam)
    {
        ImGui_ImplWin32_WndProcHandler(m_hWindow, m_uMsg, m_wParam, m_lParam);

        if (m_wParam == VK_INSERT)
        {
            static bool m_bPressed = false;
            if (m_uMsg == WM_KEYUP)
                m_bPressed = false;
            else if (m_uMsg == WM_KEYDOWN && !m_bPressed)
            {
                Callback::m_bOnRenderDebug = !Callback::m_bOnRenderDebug;
                m_bPressed = true;
            }
        }
      
        UFG::Input::EnableGameInput(!Callback::m_bOnRenderDebug);

        return CallWindowProcA(m_oHook, m_hWindow, m_uMsg, m_wParam, m_lParam);
    }
}