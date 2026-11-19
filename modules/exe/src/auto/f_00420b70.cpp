#include <string.h>

extern "C" {
// src: LIB
__declspec(dllimport) int __cdecl strcpy_s(char* dst, unsigned int sizeInBytes, const char* src);
}

// src: GUESS (confidence: medium) [0x0065c1e0]
struct PacketWriter_0065c1e0 {
    char* m_pCur;
    unsigned int m_cap;
    unsigned int m_rem;

    // src: GUESS (confidence: medium) [0x0065c1e0]
    bool WriteString(const char* s);
};

// src: GUESS (confidence: medium) [0x0065c1e0]
bool PacketWriter_0065c1e0::WriteString(const char* s) {
    if (!s) {
        if (m_rem < 1) {
            return false;
        }
        *m_pCur = 0;
        --m_rem;
        ++m_pCur;
        return true;
    }
    unsigned int len = (unsigned int)strlen(s) + 1;
    if (len > m_rem) {
        return false;
    }
    strcpy_s(m_pCur, m_rem, s);
    m_rem -= len;
    m_pCur += len;
    return true;
}
