// c5d-cflags: +/Oy-
#include <string.h>

// src: GUESS (confidence: low) [0x0040a9e0]
struct Unk_0040a9e0
{
    char m_buf[0x40];  // +0x00
    int m_f40;         // +0x40

    // src: GUESS (confidence: high) [0x0040a9e0]
    Unk_0040a9e0* Copy_0040a9e0(const Unk_0040a9e0* other);
};

// src: GUESS (confidence: high) [0x0040a9e0]
Unk_0040a9e0* Unk_0040a9e0::Copy_0040a9e0(const Unk_0040a9e0* other)
{
    strncpy(m_buf, other->m_buf, 0x40);
    m_f40 = other->m_f40;
    return this;
}
