// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_00660c10 {
    TreeNode_00660c10* m_left;
    TreeNode_00660c10* m_parent;
    TreeNode_00660c10* m_right;
    char pad[0xd];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x00660c10]
TreeNode_00660c10* FindMaxNode_00660c10(TreeNode_00660c10* node) {
    while (!node->m_right->m_isNil) {
        node = node->m_right;
    }
    return node;
}
