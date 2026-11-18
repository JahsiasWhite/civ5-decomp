// src: GUESS (confidence: medium) [0x00610c10]
// src: GUESS (confidence: low)
struct Node64_00610c10 {
    unsigned int m_prev : 31;
    unsigned int m_bPrevFlag : 1;
    unsigned int m_next : 31;
    unsigned int m_bNextFlag : 1;
    char m_pad08[0x38];
};

// src: GUESS (confidence: low)
struct PoolHeader_00610c10 {
    int m_i00;
    int m_i04;
    Node64_00610c10* m_pNodes;
};

// src: GUESS (confidence: low)
class PoolHost_00610c10 {
public:
    PoolHeader_00610c10* m_pHeader;

    // src: GUESS (confidence: medium) [0x00610c10]
    void LinkNode(unsigned int uiNode, unsigned int uiTarget);
};

void PoolHost_00610c10::LinkNode(unsigned int uiNode, unsigned int uiTarget) {
    Node64_00610c10* pNodes = m_pHeader->m_pNodes;
    Node64_00610c10& kNode = pNodes[uiNode];
    if (uiTarget == 0x0fffffff) {
        kNode.m_prev = 0x0fffffff;
        kNode.m_next = 0x0fffffff;
        return;
    }
    Node64_00610c10& kTarget = pNodes[uiTarget];
    unsigned int uiPrev = kTarget.m_prev;
    kNode.m_next = uiTarget;
    kNode.m_prev = uiPrev;
    if (uiPrev != 0x0fffffff) {
        Node64_00610c10* pPrev = &m_pHeader->m_pNodes[uiPrev];
        pPrev->m_next = uiNode;
    }
    kTarget.m_prev = uiNode;
}
