// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_0056ec20 {
    TreeNode_0056ec20* m_left;
    TreeNode_0056ec20* m_parent;
    TreeNode_0056ec20* m_right;
    char pad[0x5];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x0056ec20]
TreeNode_0056ec20* FindMaxNode_0056ec20(TreeNode_0056ec20* node) {
    while (!node->m_right->m_isNil) {
        node = node->m_right;
    }
    return node;
}
