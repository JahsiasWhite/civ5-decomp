// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_00635eb0 {
    TreeNode_00635eb0* m_left;
    TreeNode_00635eb0* m_parent;
    TreeNode_00635eb0* m_right;
    char pad[0x55];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x00635eb0]
TreeNode_00635eb0* FindMaxNode_00635eb0(TreeNode_00635eb0* node) {
    while (!node->m_right->m_isNil) {
        node = node->m_right;
    }
    return node;
}
