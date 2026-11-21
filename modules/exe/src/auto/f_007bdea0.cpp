// c5d-cflags: -/Ob1 +/Ob0
#include <cstdio>
#include <string>

// src: EXE [0x007bdea0]
class NetVersionNack {
public:
    char pad0[0x30];
    int m_eVersionType;
    int m_iIntValue;
    std::string m_szStringValue;

    // src: GUESS (confidence: high) [0x007bdea0]
    void __thiscall DebugString(char* szBuf, size_t uiSize);
};

void __thiscall NetVersionNack::DebugString(char* szBuf, size_t uiSize) {
    sprintf_s(
        szBuf,
        uiSize,
        "NetVersionNack : m_eVersionType=%d, m_iIntValue=%d, m_szStringValue=\"%s\"",
        m_eVersionType,
        m_iIntValue,
        m_szStringValue.c_str()
    );
}
