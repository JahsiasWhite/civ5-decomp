// c5d-cflags: -/Ob1 +/Ob0
#include <stdio.h>
#include <string>

// src: GUESS (confidence: low) [0x007bdea0]
struct NetVersionNack {
    char pad[0x30];
    int m_eVersionType;
    int m_iIntValue;
    std::string m_szStringValue;
    void format(char* buf, size_t size);
};

void NetVersionNack::format(char* buf, size_t size) {
    sprintf_s(buf, size, "NetVersionNack : m_eVersionType=%d, m_iIntValue=%d, m_szStringValue=\"%s\"",
              m_eVersionType, m_iIntValue, m_szStringValue.c_str());
}
