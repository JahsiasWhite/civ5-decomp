// src: GUESS (confidence: medium) [0x0071e550]
// src: GUESS (confidence: low)
struct Node60_0071e550 {
    unsigned int m_prev;
    unsigned int m_next;
    char m_pad08[0x34];
};

// src: GUESS (confidence: low)
struct PoolHeader_0071e550 {
    int m_i00;
    int m_i04;
    Node60_0071e550* m_pNodes;
};

// src: GUESS (confidence: low)
class PoolHost_0071e550 {
public:
    PoolHeader_0071e550* m_pHeader;

    // src: GUESS (confidence: medium) [0x0071e550]
    void LinkNode_0071e550(unsigned int uiNode, unsigned int uiTarget);
};

void PoolHost_0071e550::LinkNode_0071e550(unsigned int uiNode, unsigned int uiTarget) {
    Node60_0071e550* pNodes = m_pHeader->m_pNodes;
    Node60_0071e550& kNode = pNodes[uiNode];
    if (uiTarget == 0x0fffffff) {
        kNode.m_next = 0x0fffffff;
        kNode.m_prev = 0x0fffffff;
        return;
    }
    Node60_0071e550& kTarget = pNodes[uiTarget];
    unsigned int uiPrev = kTarget.m_prev & 0x7fffffff;
    kNode.m_next = uiTarget;
    kNode.m_prev = uiPrev;
    if (uiPrev != 0x0fffffff) {
        m_pHeader->m_pNodes[uiPrev].m_next = uiNode;
    }
    kTarget.m_prev = uiNode;
}
