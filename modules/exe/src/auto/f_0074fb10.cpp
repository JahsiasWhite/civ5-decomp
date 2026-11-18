// src: GUESS (confidence: medium) [0x0074fb10]
// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Entry12_0074fb10 {
    unsigned int m_a;
    unsigned int m_b;
    unsigned int m_key;
};

// src: GUESS (confidence: medium) [0x0074fb10]
static inline void SwapIfLess_0074fb10(Entry12_0074fb10* pDst, Entry12_0074fb10* pSrc) {
    if (pSrc->m_key < pDst->m_key && pSrc != pDst) {
        Entry12_0074fb10 kTmp = *pSrc;
        *pSrc = *pDst;
        *pDst = kTmp;
    }
}

void SortThree_0074fb10(Entry12_0074fb10* pA, Entry12_0074fb10* pB, Entry12_0074fb10* pC) {
    if (pB->m_key < pA->m_key && pB != pA) {
        Entry12_0074fb10 kTmp = *pB;
        *pB = *pA;
        *pA = kTmp;
    }
    SwapIfLess_0074fb10(pB, pC);
    if (pB->m_key < pA->m_key && pB != pA) {
        Entry12_0074fb10 kTmp = *pB;
        *pB = *pA;
        *pA = kTmp;
    }
}
