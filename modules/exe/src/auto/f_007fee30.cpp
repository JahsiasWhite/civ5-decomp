// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast

// src: GUESS (confidence: low) [0x007fee30]
struct SceneNodeData_007fee30
{
    unsigned char m_pad0[0x68];
    unsigned int m_flags;
    unsigned char m_pad6c[0x13c];
    float m_localMat[16];
};

struct SceneChild_007fee30
{
    unsigned char m_pad0[0x110];
    float m_extraMat[16];
    unsigned char m_pad150[0x14];
    SceneNodeData_007fee30* m_pData;
};

struct SceneListItem_007fee30
{
    SceneListItem_007fee30* m_pNext;
    unsigned char m_pad4[0x12c];
    SceneChild_007fee30* m_pChild;
};

struct SceneList_007fee30
{
    unsigned char m_pad0[0x124];
    SceneListItem_007fee30* m_pHead;
    unsigned char m_pad128[4];
    SceneListItem_007fee30* m_pCur;
};

struct SceneNode_007fee30
{
    float m_worldMat[16];
    unsigned char m_pad40[4];
    SceneList_007fee30* m_pList;
};

// src: GUESS (confidence: low) [0x007fc870]
extern "C" void UpdateSceneChild_007fc870(SceneChild_007fee30* pChild, float* pMat);

#define COPY_MAT4(dstMat, srcMat) \
    { \
        float* pDst = (dstMat); \
        const float* pSrc = (srcMat); \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; pDst++; pSrc++; \
        *pDst = *pSrc; \
    }

#define IDENTITY_MAT4(dstMat) \
    { \
        float* pDst = (dstMat); \
        *pDst = 1.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 1.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 1.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 0.0f; pDst++; \
        *pDst = 1.0f; \
    }

#define MUL_MAT4(dstMat, matA, matB) \
    { \
        const float* pB; \
        { \
            float tmp[16]; \
            const float* pA = (matA); \
            pB = (matB); \
            tmp[0]  = pA[0] * pB[0] + pA[1] * pB[4] + pA[2] * pB[8]  + pA[3] * pB[12]; \
            tmp[1]  = pA[0] * pB[1] + pA[1] * pB[5] + pA[2] * pB[9]  + pA[3] * pB[13]; \
            tmp[2]  = pA[0] * pB[2] + pA[1] * pB[6] + pA[2] * pB[10] + pA[3] * pB[14]; \
            tmp[3]  = pA[0] * pB[3] + pA[1] * pB[7] + pA[2] * pB[11] + pA[3] * pB[15]; \
            tmp[4]  = pA[4] * pB[0] + pA[5] * pB[4] + pA[6] * pB[8]  + pA[7] * pB[12]; \
            tmp[5]  = pA[4] * pB[1] + pA[5] * pB[5] + pA[6] * pB[9]  + pA[7] * pB[13]; \
            tmp[6]  = pA[4] * pB[2] + pA[5] * pB[6] + pA[6] * pB[10] + pA[7] * pB[14]; \
            tmp[7]  = pA[4] * pB[3] + pA[5] * pB[7] + pA[6] * pB[11] + pA[7] * pB[15]; \
            tmp[8]  = pA[8] * pB[0] + pA[9] * pB[4] + pA[10] * pB[8]  + pA[11] * pB[12]; \
            tmp[9]  = pA[8] * pB[1] + pA[9] * pB[5] + pA[10] * pB[9]  + pA[11] * pB[13]; \
            tmp[10] = pA[8] * pB[2] + pA[9] * pB[6] + pA[10] * pB[10] + pA[11] * pB[14]; \
            tmp[11] = pA[8] * pB[3] + pA[9] * pB[7] + pA[10] * pB[11] + pA[11] * pB[15]; \
            tmp[12] = pA[12] * pB[0] + pA[13] * pB[4] + pA[14] * pB[8]  + pA[15] * pB[12]; \
            tmp[13] = pA[12] * pB[1] + pA[13] * pB[5] + pA[14] * pB[9]  + pA[15] * pB[13]; \
            tmp[14] = pA[12] * pB[2] + pA[13] * pB[6] + pA[14] * pB[10] + pA[15] * pB[14]; \
            tmp[15] = pA[12] * pB[3] + pA[13] * pB[7] + pA[14] * pB[11] + pA[15] * pB[15]; \
            COPY_MAT4(dstMat, tmp); \
        } \
    }

// src: GUESS (confidence: low) [0x007fee30]
void UpdateSceneNodeTransforms_007fee30(SceneNode_007fee30* pNode, const float* pParentMat)
{
    float localMat[16];
    SceneChild_007fee30* pChild = 0;

    if (pParentMat)
    {
        COPY_MAT4(pNode->m_worldMat, pParentMat);
    }
    else
    {
        IDENTITY_MAT4(pNode->m_worldMat);
    }

    pNode->m_pList->m_pCur = pNode->m_pList->m_pHead;
    while ((pChild = (pNode->m_pList->m_pCur ? pNode->m_pList->m_pCur->m_pChild : 0)) != 0)
    {
        pNode->m_pList->m_pCur = pNode->m_pList->m_pCur->m_pNext;
        MUL_MAT4(localMat, pChild->m_pData->m_localMat, pNode->m_worldMat);
        if (pChild->m_pData->m_flags & 0x200)
        {
            MUL_MAT4(localMat, pChild->m_extraMat, localMat);
        }
        UpdateSceneChild_007fc870(pChild, localMat);
    }
}
