// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_006f04a0 {
    TreeNode_006f04a0* m_left;
    TreeNode_006f04a0* m_parent;
    TreeNode_006f04a0* m_right;
    char pad[0x45];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x006f04a0]
TreeNode_006f04a0* FindMaxNode_006f04a0(TreeNode_006f04a0* node) {
    while (!node->m_right->m_isNil) {
        node = node->m_right;
    }
    return node;
}
