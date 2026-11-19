// src: GUESS (confidence: medium) [0x008151a0]
#include "FStringA.h"
#include <cstring>

int FStringA::Find(char ch, int iStart) const {
    const Header* pHeader = (const Header*)m_pszData - 1;
    if (iStart < pHeader->m_iLength && iStart >= 0) {
        const char* pFound = std::strchr(m_pszData + iStart, ch);
        if (pFound != 0) {
            return (int)(pFound - m_pszData);
        }
    }
    return -1;
}
