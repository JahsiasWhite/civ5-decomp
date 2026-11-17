// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_0068ca60 {
    TreeNode_0068ca60* m_left;
    TreeNode_0068ca60* m_parent;
    TreeNode_0068ca60* m_right;
    char pad[0x5];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x0068ca60]
TreeNode_0068ca60* FindMaxNode_0068ca60(TreeNode_0068ca60* node) {
    while (!node->m_right->m_isNil) {
        node = node->m_right;
    }
    return node;
}
