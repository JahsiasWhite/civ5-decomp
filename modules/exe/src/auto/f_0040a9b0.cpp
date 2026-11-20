// c5d-cflags: +/Oy-
#include <string.h>

// src: GUESS (confidence: low) [0x0040a9b0]
struct Unk_0040a9b0
{
    char m_buf[0x40];  // +0x00
    int m_f40;         // +0x40

    // src: GUESS (confidence: high) [0x0040a9b0]
    Unk_0040a9b0* Init_0040a9b0(const char* s, int val);
};

// src: GUESS (confidence: high) [0x0040a9b0]
Unk_0040a9b0* Unk_0040a9b0::Init_0040a9b0(const char* s, int val)
{
    strncpy_s(m_buf, 0x40, s, 0x40);
    m_f40 = val;
    return this;
}
