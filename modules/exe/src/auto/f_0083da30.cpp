// src: GUESS (confidence: medium) [0x008d79c0]
// src: GUESS (confidence: low)
struct TreeNode_008d79c0 {
    int m_i00;
    TreeNode_008d79c0* m_pParent;
};

// src: GUESS (confidence: medium) [0x008d79c0]
int CompareAncestor_008d79c0(const TreeNode_008d79c0* pTarget, const TreeNode_008d79c0* pNode) {
    if (pNode != 0 && pTarget != 0) {
        if (pNode == pTarget) {
            return 2;
        }
        for (const TreeNode_008d79c0* pCur = pNode->m_pParent; pCur != 0; pCur = pCur->m_pParent) {
            if (pCur == pTarget) {
                return 1;
            }
        }
    }
    return 0;
}
