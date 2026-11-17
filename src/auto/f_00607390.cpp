// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_00607390 {
    TreeNode_00607390* m_left;
    char pad[0x0d];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x00607390]
TreeNode_00607390* FindMinNode_00607390(TreeNode_00607390* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
