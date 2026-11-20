// c5d-cflags: +/Oy-
#include <wchar.h>

// src: GUESS (confidence: low) [0x004138e0]
struct Unk_004138e0
{
    char m_pad00[0x4c];      // +0x00
    unsigned char m_flag4c;  // +0x4c
    unsigned char m_pad4d;   // +0x4d
    wchar_t m_buf4e[0x104];  // +0x4e

    // src: GUESS (confidence: high) [0x004138e0]
    void SetPath_004138e0(const wchar_t* path);
};

// src: GUESS (confidence: high) [0x004138e0]
void Unk_004138e0::SetPath_004138e0(const wchar_t* path)
{
    wcsncpy_s(m_buf4e, 0x104, path, 0x104);
    m_flag4c = 1;
}
