#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low) [0x00cc8e74]
struct EngineOwner_00cc8e74
{
    char m_pad00[0xa4];  // +0x00
    HWND m_hWnd;         // +0xa4
};

// src: GUESS (confidence: low) [0x00cc8e74]
extern EngineOwner_00cc8e74* g_pEngineOwner_00cc8e74;

// src: GUESS (confidence: high) [0x006656c0]
void __stdcall PostKeyDown_006656c0(WPARAM wParam)
{
    PostMessageA(g_pEngineOwner_00cc8e74->m_hWnd, WM_KEYDOWN, wParam, 0);
}
