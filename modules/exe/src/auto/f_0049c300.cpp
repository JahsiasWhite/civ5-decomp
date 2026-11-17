// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_0049c300 {
    TreeNode_0049c300* m_left;
    char pad[0x11];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x0049c300]
TreeNode_0049c300* FindMinNode_0049c300(TreeNode_0049c300* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
