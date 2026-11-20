#include <string.h>

// src: GUESS (confidence: low)
struct UnkFixedStr256_0077cbe0
{
    char m_buf[0x100];
    int m_len;

    UnkFixedStr256_0077cbe0* Set_0077cbe0(const char* str, int len);
};

// src: GUESS (confidence: medium) [0x0077cbe0]
UnkFixedStr256_0077cbe0* UnkFixedStr256_0077cbe0::Set_0077cbe0(const char* str, int len)
{
    m_len = len;
    strcpy_s(m_buf, 0x100, str);
    return this;
}
