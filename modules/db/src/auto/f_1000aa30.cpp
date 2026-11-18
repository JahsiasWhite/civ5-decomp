// src: GUESS (confidence: low)
struct TreeNode_1000aa30 {
    // src: GUESS (confidence: low)
    char m_pad0[0x18];
    // src: GUESS (confidence: low)
    TreeNode_1000aa30* m_firstChild;
    // src: GUESS (confidence: low)
    char m_pad1[0x10];
    // src: GUESS (confidence: low)
    TreeNode_1000aa30* m_nextSibling;
};

// src: GUESS 0x1000aa30 (confidence: high)
int CountDescendants_1000aa30(const TreeNode_1000aa30* node, int depth) {
    int count = 0;
    if (depth == -1 || depth > 0) {
        for (const TreeNode_1000aa30* child = node->m_firstChild; child != 0; child = child->m_nextSibling) {
            count += 1 + CountDescendants_1000aa30(child, depth - 1);
        }
    }
    return count;
}
