// c5d-cflags: -/Ob1 +/Ob0
#include <stdio.h>
#include <string>

// src: GUESS (confidence: low) [0x007c1630]
struct NetDiploChat {
    char pad[0x30];
    int m_ePlayer;
    int m_eToPlayer;
    std::string m_szText;
    void format(char* buf, size_t size);
};

void NetDiploChat::format(char* buf, size_t size) {
    int to = m_eToPlayer;
    sprintf_s(buf, size, "NetDiploChat : Player %d diplo said \"%s\" to %d",
              m_ePlayer, m_szText.c_str(), to);
}
