// c5d-cflags: -/Ob1 +/Ob0
#include <stdio.h>
#include <string>

// src: EXE
struct NetVersionNack_007bdea0
{
    char m_pad[0x30];
    int m_eVersionType;
    int m_iIntValue;
    std::string m_szStringValue;

    void Format_007bdea0(char* buf, size_t bufSize);
};

// src: EXE [0x007bdea0]
void NetVersionNack_007bdea0::Format_007bdea0(char* buf, size_t bufSize)
{
    sprintf_s(buf, bufSize, "NetVersionNack : m_eVersionType=%d, m_iIntValue=%d, m_szStringValue=\"%s\"",
        m_eVersionType, m_iIntValue, m_szStringValue.c_str());
}
