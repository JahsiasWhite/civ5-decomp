// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_0086c350 {
    TreeNode_0086c350* m_left;
    char pad[0x1d];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x0086c350]
TreeNode_0086c350* FindMinNode_0086c350(TreeNode_0086c350* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
