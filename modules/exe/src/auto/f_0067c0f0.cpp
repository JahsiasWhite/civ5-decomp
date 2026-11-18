// src: GUESS (confidence: medium) [0x0067c0f0]
// src: GUESS (confidence: low)
struct Node60_0067c0f0 {
    int m_prev;
    int m_next;
    char m_pad08[0x34];
};

// src: GUESS (confidence: low)
struct PoolHeader_0067c0f0 {
    int m_i00;
    int m_i04;
    Node60_0067c0f0* m_pNodes;
};

// src: GUESS (confidence: low)
class PoolHost_0067c0f0 {
public:
    PoolHeader_0067c0f0* m_pHeader;

    // src: GUESS (confidence: medium) [0x0067c0f0]
    void LinkNode_0067c0f0(int iNode, int iTarget);
};

void PoolHost_0067c0f0::LinkNode_0067c0f0(int iNode, int iTarget) {
    Node60_0067c0f0* pNodes = m_pHeader->m_pNodes;
    Node60_0067c0f0& kNode = pNodes[iNode];
    if (iTarget == 0x0fffffff) {
        kNode.m_next = 0x0fffffff;
        kNode.m_prev = 0x0fffffff;
        return;
    }
    Node60_0067c0f0& kTarget = pNodes[iTarget];
    int iNext = kTarget.m_next;
    kNode.m_prev = iTarget;
    kNode.m_next = iNext;
    if (iNext != 0x0fffffff) {
        m_pHeader->m_pNodes[iNext].m_prev = iNode;
    }
    kTarget.m_next = iNode;
}
