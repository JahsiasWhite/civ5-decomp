#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low) [0x00492d20]
struct Unk_00492d20
{
    char m_pad00[0xa4];  // +0x00
    HWND m_hWnd;         // +0xa4

    // src: GUESS (confidence: high) [0x00492d20]
    void ClipToWindow_00492d20();
};

// src: GUESS (confidence: high) [0x00492d20]
void Unk_00492d20::ClipToWindow_00492d20()
{
    WINDOWINFO wi;
    GetWindowInfo(m_hWnd, &wi);
    ClipCursor(&wi.rcClient);
}
