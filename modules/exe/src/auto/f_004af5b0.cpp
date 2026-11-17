// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_004af5b0 {
    TreeNode_004af5b0* m_left;
    char pad[0x11];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x004af5b0]
TreeNode_004af5b0* FindMinNode_004af5b0(TreeNode_004af5b0* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
