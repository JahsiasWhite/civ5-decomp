// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_006b4530 {
    TreeNode_006b4530* m_left;
    char pad[0x4d];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x006b4530]
TreeNode_006b4530* FindMinNode_006b4530(TreeNode_006b4530* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
