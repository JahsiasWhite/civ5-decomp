// c5d-cflags: -/O2 -/Ob1 +/Od

// src: GUESS (confidence: medium) [0x007f9a00]
struct Inner90 {
    char m_pad0[0x28];
    int m_iVal28;
    int m_iVal2c;
};

// src: GUESS (confidence: medium) [0x007f9a00]
struct Outer90 {
    char m_pad0[0x90];
    Inner90* m_pInner;
};

// src: GUESS (confidence: medium) [0x007f9a00]
void __cdecl GetInnerPair(Outer90* pOuter, int* pOut1, int* pOut2) {
    *pOut1 = pOuter->m_pInner->m_iVal2c;
    *pOut2 = pOuter->m_pInner->m_iVal28;
}
