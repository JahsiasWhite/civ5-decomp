// src: GUESS (confidence: medium) [0x005d7760]
// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Vec4_005d7760 {
    float x;
    float y;
    float z;
    float w;
};

// src: GUESS (confidence: medium) [0x005d7760]
void FillVec4Array_005d7760(Vec4_005d7760* pDst, unsigned int uiCount, const Vec4_005d7760* pVal) {
    while (uiCount > 0) {
        if (pDst != 0) {
            pDst->x = pVal->x;
            pDst->y = pVal->y;
            pDst->z = pVal->z;
            pDst->w = pVal->w;
        }
        --uiCount;
        ++pDst;
    }
}
