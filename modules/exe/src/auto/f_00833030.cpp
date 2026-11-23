// Function: 0x00833030

struct BatchVec4 { // src: GUESS (confidence: high)
    float x; // src: GUESS (confidence: high)
    float y; // src: GUESS (confidence: high)
    float z; // src: GUESS (confidence: high)
    float w; // src: GUESS (confidence: high)
};

struct DrawBatchEntry { // src: GUESS (confidence: high)
    void* m_pEffect; // src: GUESS (confidence: medium)
    void* m_pTechnique; // src: GUESS (confidence: medium)
    unsigned int m_pad08[2]; // src: GUESS (confidence: low)
    unsigned short m_wNumVB; // src: GUESS (confidence: high)
    unsigned short m_wNumTex; // src: GUESS (confidence: high)
    void* m_apVB[4]; // src: GUESS (confidence: high)
    unsigned char m_abFlag24[4]; // src: GUESS (confidence: medium)
    unsigned char m_abFlag28[4]; // src: GUESS (confidence: medium)
    void* m_apTex[4]; // src: GUESS (confidence: high)
    void* m_pIB; // src: GUESS (confidence: medium)
    unsigned int m_uiParam40; // src: GUESS (confidence: low)
    unsigned int m_uiParam44; // src: GUESS (confidence: low)
    bool m_bFlag48; // src: GUESS (confidence: medium)
    bool m_bFlag49; // src: GUESS (confidence: medium)
    unsigned char m_pad4a[2]; // src: GUESS (confidence: low)
    unsigned int* m_pPtr4c; // src: GUESS (confidence: low)
    unsigned int* m_pPtr50; // src: GUESS (confidence: low)
    unsigned int m_uiZero54; // src: GUESS (confidence: low)
    unsigned int m_uiBase58; // src: GUESS (confidence: low)
    unsigned int m_uiZero5c; // src: GUESS (confidence: low)
    BatchVec4 m_vColor; // src: GUESS (confidence: medium)
    float m_fSortKey; // src: GUESS (confidence: medium)
    unsigned int m_uiZero74; // src: GUESS (confidence: low)
    unsigned int m_uiParam78; // src: GUESS (confidence: low)
    unsigned int m_pad7c; // src: GUESS (confidence: low)
};

class DrawBatchQueue { // src: GUESS (confidence: medium)
public:
    unsigned int BeginBatch(
        void* pVB0, void* pVB1, void* pVB2, void* pVB3,
        void* pTex0, void* pTex1, void* pTex2, void* pTex3,
        void* pIB, unsigned int uiParam40, unsigned int uiParam44,
        void* pEffect, void* pTechnique, BatchVec4 vColor,
        float fSortKey, bool bFlag49, bool bFlag48, unsigned int uiParam78); // src: GUESS (confidence: medium) [0x00833030]

private:
    DrawBatchEntry* m_pEntries; // src: GUESS (confidence: high)
    unsigned int m_uiCurrent; // src: GUESS (confidence: high)
    unsigned int m_pad08; // src: GUESS (confidence: low)
    unsigned int m_uiBase58; // src: GUESS (confidence: low)
    unsigned char m_pad10[8]; // src: GUESS (confidence: low)
    bool m_bDirty; // src: GUESS (confidence: medium)
    unsigned char m_pad19[0x3b]; // src: GUESS (confidence: low)
    unsigned int m_uiOffset54; // src: GUESS (confidence: low)
    unsigned int* m_pBuf58; // src: GUESS (confidence: low)
    unsigned int* m_pBuf5c; // src: GUESS (confidence: low)
};

unsigned int DrawBatchQueue::BeginBatch(
    void* pVB0, void* pVB1, void* pVB2, void* pVB3,
    void* pTex0, void* pTex1, void* pTex2, void* pTex3,
    void* pIB, unsigned int uiParam40, unsigned int uiParam44,
    void* pEffect, void* pTechnique, BatchVec4 vColor,
    float fSortKey, bool bFlag49, bool bFlag48, unsigned int uiParam78)
{
    m_bDirty = true;
    m_pEntries[m_uiCurrent].m_pEffect = pEffect;
    m_pEntries[m_uiCurrent].m_pIB = pIB;
    m_pEntries[m_uiCurrent].m_pTechnique = pTechnique;
    m_pEntries[m_uiCurrent].m_apVB[0] = pVB0;
    m_pEntries[m_uiCurrent].m_apVB[1] = pVB1;
    m_pEntries[m_uiCurrent].m_apVB[2] = pVB2;
    m_pEntries[m_uiCurrent].m_apVB[3] = pVB3;

    unsigned int uiNumVB = 1;
    if (pVB1 != 0) ++uiNumVB;
    if (pVB2 != 0) ++uiNumVB;
    if (pVB3 != 0) ++uiNumVB;
    m_pEntries[m_uiCurrent].m_wNumVB = (unsigned short)uiNumVB;

    for (unsigned int i = 0; i < uiNumVB; ++i) {
        m_pEntries[m_uiCurrent].m_abFlag24[i] = 0;
        m_pEntries[m_uiCurrent].m_abFlag28[i] = 0;
    }

    unsigned short wNumTex = 0;
    m_pEntries[m_uiCurrent].m_apTex[0] = pTex0;
    m_pEntries[m_uiCurrent].m_apTex[1] = pTex1;
    m_pEntries[m_uiCurrent].m_apTex[2] = pTex2;
    m_pEntries[m_uiCurrent].m_apTex[3] = pTex3;

    if (pTex0 != 0) ++wNumTex;
    if (pTex1 != 0) ++wNumTex;
    if (pTex2 != 0) ++wNumTex;
    if (pTex3 != 0) ++wNumTex;
    m_pEntries[m_uiCurrent].m_wNumTex = wNumTex;

    m_pEntries[m_uiCurrent].m_uiParam40 = uiParam40;
    m_pEntries[m_uiCurrent].m_uiParam44 = uiParam44;
    m_pEntries[m_uiCurrent].m_uiBase58 = m_uiBase58;
    m_pEntries[m_uiCurrent].m_uiZero5c = 0;
    m_pEntries[m_uiCurrent].m_uiZero54 = 0;
    m_pEntries[m_uiCurrent].m_pPtr4c = &m_pBuf58[m_uiOffset54];
    m_pEntries[m_uiCurrent].m_pPtr50 = &m_pBuf5c[m_uiOffset54];
    m_pEntries[m_uiCurrent].m_vColor = vColor;
    m_pEntries[m_uiCurrent].m_fSortKey = fSortKey;
    m_pEntries[m_uiCurrent].m_bFlag48 = bFlag48;
    m_pEntries[m_uiCurrent].m_bFlag49 = bFlag49;
    m_pEntries[m_uiCurrent].m_uiParam78 = uiParam78;
    m_pEntries[m_uiCurrent].m_uiZero74 = 0;

    return m_uiCurrent;
}
