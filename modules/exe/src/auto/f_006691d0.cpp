// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_006691d0 {
    TreeNode_006691d0* m_left;
    char pad[0x5d];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x006691d0]
TreeNode_006691d0* FindMinNode_006691d0(TreeNode_006691d0* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
