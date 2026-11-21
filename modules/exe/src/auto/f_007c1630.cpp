// c5d-cflags: -/Ob1 +/Ob0
#include <cstdio>
#include <string>

// src: EXE [0x007c1630]
class NetDiploChat {
public:
    char pad0[0x30];
    int m_iFromPlayer;
    int m_iToPlayer;
    std::string m_szText;

    // src: GUESS (confidence: high) [0x007c1630]
    void __thiscall DebugString(char* szBuf, size_t uiSize);
};

void __thiscall NetDiploChat::DebugString(char* szBuf, size_t uiSize) {
    int iToPlayer = m_iToPlayer;
    const char* szText = m_szText.c_str();
    sprintf_s(
        szBuf,
        uiSize,
        "NetDiploChat : Player %d diplo said \"%s\" to %d",
        m_iFromPlayer,
        szText,
        iToPlayer
    );
}
