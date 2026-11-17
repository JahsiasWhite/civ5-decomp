// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_005a05b0 {
    TreeNode_005a05b0* m_left;
    char pad[0x19];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x005a05b0]
TreeNode_005a05b0* FindMinNode_005a05b0(TreeNode_005a05b0* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
