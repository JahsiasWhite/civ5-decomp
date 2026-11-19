// src: GUESS (confidence: medium) [0x007eaa20]
#include "Unk_00a91730.h"

int Unk_00a91730::ValidateIndex_007eaa20(int iIndex) const {
    if (iIndex >= 0 && (unsigned int)iIndex < (unsigned int)m_elems.size()) {
        return iIndex;
    }
    return -1;
}
