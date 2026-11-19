// src: GUESS (confidence: low) [0x008cfdc0]
struct CmdBuf_008cfdc0 {
    int m_00[9];
    int m_24;
    int m_28[2];
    int m_30;
    int m_34[3];
    int m_40;
    int m_44[2];
    unsigned short m_4c;
};

// src: GUESS (confidence: low) [0x008cfdc0]
int __stdcall AllocScratch_008cfdc0(CmdBuf_008cfdc0* pBuf, unsigned int size) {
    pBuf->m_30 = pBuf->m_24 + pBuf->m_40;
    pBuf->m_40 += (unsigned short)size;
    pBuf->m_4c = (unsigned short)size;
    return pBuf->m_30;
}
