#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low) [0x007bbb00]
struct Unk_007bbb00
{
    char m_pad00[0x14];  // +0x00
    HDC m_hDC;           // +0x14
    HGDIOBJ m_hOldObj;   // +0x18? Wait: +0x1c!
    HGDIOBJ m_hObj1c;    // +0x1c

    // src: GUESS (confidence: high) [0x007bbb00]
    void RestoreDC_007bbb00();
};

// src: GUESS (confidence: high) [0x007bbb00]
void Unk_007bbb00::RestoreDC_007bbb00()
{
    if (m_hObj1c)
    {
        GdiFlush();
        SelectObject(m_hDC, m_hObj1c);
        m_hObj1c = 0;
    }
}
