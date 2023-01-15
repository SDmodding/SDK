#include "imgui.h"
#include "imgui_impl_win32.h"
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <tchar.h>

// Win32 Data
static HWND                 g_hWnd = NULL;
static INT64                g_Time = 0;
static INT64                g_TicksPerSecond = 0;
static ImGuiMouseCursor     g_LastMouseCursor = ImGuiMouseCursor_COUNT;
static bool                 g_HasGamepad = false;
static bool                 g_WantUpdateHasGamepad = true;

// Functions
bool ImGui_ImplWin32_Init(void* hwnd)
{
    if (!QueryPerformanceFrequency((LARGE_INTEGER*)&g_TicksPerSecond)) return false;
    if (!QueryPerformanceCounter((LARGE_INTEGER*)&g_Time)) return false;

    // Setup back-end capabilities flags
    g_hWnd = (HWND)hwnd;
    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
    io.BackendPlatformName = NULL;
    io.ImeWindowHandle = hwnd;

    // Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array that we will update during the application lifetime.
    io.KeyMap[ImGuiKey_Tab] = VK_TAB;
    io.KeyMap[ImGuiKey_LeftArrow] = VK_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = VK_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = VK_UP;
    io.KeyMap[ImGuiKey_DownArrow] = VK_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = VK_PRIOR;
    io.KeyMap[ImGuiKey_PageDown] = VK_NEXT;
    io.KeyMap[ImGuiKey_Home] = VK_HOME;
    io.KeyMap[ImGuiKey_End] = VK_END;
    io.KeyMap[ImGuiKey_Insert] = VK_INSERT;
    io.KeyMap[ImGuiKey_Delete] = VK_DELETE;
    io.KeyMap[ImGuiKey_Backspace] = VK_BACK;
    io.KeyMap[ImGuiKey_Space] = VK_SPACE;
    io.KeyMap[ImGuiKey_Enter] = VK_RETURN;
    io.KeyMap[ImGuiKey_Escape] = VK_ESCAPE;
    io.KeyMap[ImGuiKey_KeyPadEnter] = VK_RETURN;
    io.KeyMap[ImGuiKey_A] = 'A';
    io.KeyMap[ImGuiKey_C] = 'C';
    io.KeyMap[ImGuiKey_V] = 'V';
    io.KeyMap[ImGuiKey_X] = 'X';
    io.KeyMap[ImGuiKey_Y] = 'Y';
    io.KeyMap[ImGuiKey_Z] = 'Z';

    return true;
}

void ImGui_ImplWin32_Shutdown()
{
    g_hWnd = (HWND)0;
}

static bool ImGui_ImplWin32_UpdateMouseCursor(ImGuiIO& io)
{
    if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange) return false;

    ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
    if (imgui_cursor == ImGuiMouseCursor_None || io.MouseDrawCursor) SetCursor(0);
    else
    {
        LPTSTR win32_cursor = IDC_ARROW;
        switch (imgui_cursor)
        {
        case ImGuiMouseCursor_Arrow: win32_cursor = IDC_ARROW; break;
        case ImGuiMouseCursor_TextInput: win32_cursor = IDC_IBEAM; break;
        case ImGuiMouseCursor_ResizeAll: win32_cursor = IDC_SIZEALL; break;
        case ImGuiMouseCursor_ResizeEW: win32_cursor = IDC_SIZEWE; break;
        case ImGuiMouseCursor_ResizeNS: win32_cursor = IDC_SIZENS; break;
        case ImGuiMouseCursor_ResizeNESW: win32_cursor = IDC_SIZENESW; break;
        case ImGuiMouseCursor_ResizeNWSE: win32_cursor = IDC_SIZENWSE; break;
        case ImGuiMouseCursor_Hand: win32_cursor = IDC_HAND; break;
        case ImGuiMouseCursor_NotAllowed: win32_cursor = IDC_NO; break;
        }
        SetCursor(LoadCursorA(0, win32_cursor));
    }
    return true;
}

static void ImGui_ImplWin32_UpdateMousePos(ImGuiIO& io)
{
    if (io.WantSetMousePos)
    {
        POINT pPos = { (int)io.MousePos.x, (int)io.MousePos.y };
        ClientToScreen(g_hWnd, &pPos);
        SetCursorPos(pPos.x, pPos.y);
    }

    io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);

    HWND hActiveWindow = GetForegroundWindow();
    if (hActiveWindow)
    {
        if (hActiveWindow == g_hWnd || IsChild(hActiveWindow, g_hWnd))
        {
            POINT pPos;
            if (GetCursorPos(&pPos) && ScreenToClient(g_hWnd, &pPos)) 
                io.MousePos = ImVec2(static_cast<float>(pPos.x), static_cast<float>(pPos.y));
        }
    }
}

void ImGui_ImplWin32_NewFrame()
{
    ImGuiIO& io = ImGui::GetIO();
    IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer back-end. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

    // Setup display size (every frame to accommodate for window resizing)
    RECT rect;
    GetClientRect(g_hWnd, &rect);
    io.DisplaySize = ImVec2(static_cast<float>(rect.right - rect.left), static_cast<float>(rect.bottom - rect.top));

    // Setup time step
    INT64 current_time;
    QueryPerformanceCounter((LARGE_INTEGER*)&current_time);
    io.DeltaTime = static_cast<float>(current_time - g_Time) / g_TicksPerSecond;
    g_Time = current_time;

    io.KeySuper = false;

    // Update OS mouse position
    ImGui_ImplWin32_UpdateMousePos(io);

    // Update OS mouse cursor with the cursor requested by imgui
    ImGuiMouseCursor mouse_cursor = io.MouseDrawCursor ? ImGuiMouseCursor_None : ImGui::GetMouseCursor();
    if (g_LastMouseCursor != mouse_cursor)
    {
        g_LastMouseCursor = mouse_cursor;
        ImGui_ImplWin32_UpdateMouseCursor(io);
    }
}

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (!ImGui::GetCurrentContext()) return false;

    ImGuiIO& io = ImGui::GetIO();
    static POINTS pLeftDown;

    switch (msg)
    {
        case WM_LBUTTONDOWN:
        {
            io.MouseDown[0] = true;
            SetCapture(g_hWnd);
            pLeftDown = MAKEPOINTS(lParam);
            return true;
        }
        case WM_LBUTTONUP:
        {
            ReleaseCapture();
            io.MouseDown[0] = false;
            return true;
        }
        case WM_RBUTTONDOWN: io.MouseDown[1] = true; return true;
        case WM_RBUTTONUP: io.MouseDown[1] = false; return true;
        case WM_MBUTTONDOWN: io.MouseDown[2] = true; return true;
        case WM_MBUTTONUP: io.MouseDown[2] = false; return true;
        case WM_MOUSEWHEEL: io.MouseWheel += GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? +1.0f : -1.0f; return true;
        case WM_MOUSEMOVE:
        {
            io.MousePos.x = (signed short)(lParam);
            io.MousePos.y = (signed short)(lParam >> 16);
            return true;
        }
        case WM_KEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
        {
            bool m_bDown = (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN);
            if (256 > wParam)
            {
                io.KeysDown[wParam] = m_bDown;
                switch (wParam)
                {
                    case VK_SHIFT: io.KeyShift = m_bDown; break;
                    case VK_CONTROL: io.KeyCtrl = m_bDown; break;
                    case VK_MENU: io.KeyAlt = m_bDown; break;
                }
            }
            return true;
        }
        case WM_CHAR:
        {           
            if (wParam > 0 && 65536 > wParam) io.AddInputCharacter(static_cast<unsigned int>(wParam));
            return true;
        }
    }
    return false;
}