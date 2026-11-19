// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
struct TreeNode_005f7c70 {
    TreeNode_005f7c70* m_left;
    char pad[0x15];
    char m_isNil;
};

// src: GUESS (confidence: high) [0x005f7c70]
TreeNode_005f7c70* FindMinNode_005f7c70(TreeNode_005f7c70* node) {
    while (!node->m_left->m_isNil) {
        node = node->m_left;
    }
    return node;
}
