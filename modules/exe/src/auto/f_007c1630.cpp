// c5d-cflags: -/Ob1 +/Ob0
#include <cstdio>
#include <string>

// src: GUESS (confidence: low)
class NetDiploChatFormatter {
public:
    unsigned char pad[0x30];
    int m_player;
    int m_unk;
    std::string m_text;

    void Format(char* buf, size_t size);
};

void NetDiploChatFormatter::Format(char* buf, size_t size) {
    sprintf_s(buf, size, "NetDiploChat : Player %d diplo said \"%s\"", m_player, m_text.c_str(), m_unk);
}
