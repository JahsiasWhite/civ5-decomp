// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_0046e460 {
    TreeNode_0046e460* m_left;
    TreeNode_0046e460* m_parent;
    TreeNode_0046e460* m_right;
    char pad[0x9];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x0046e460]
TreeNode_0046e460* FindMaxNode_0046e460(TreeNode_0046e460* node) {
    while (!node->m_right->m_isNil) {
        node = node->m_right;
    }
    return node;
}
