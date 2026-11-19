// Looks up (a, b) in the global binary tree; null when it isn't there.
// Child links are stored with tag bits in the low two bits of the right link.

// src: GUESS (confidence: low)
struct TreeNode_0099aaa0
{
    // src: GUESS (confidence: low)
    int m_a;
    // src: GUESS (confidence: low)
    int m_b;
    char m_pad8[0x18 - 8];
    // src: GUESS (confidence: low)
    unsigned int m_rightTagged;
    // src: GUESS (confidence: low)
    TreeNode_0099aaa0* m_left;
};

// src: GUESS (confidence: low) [0x06070ab4]
extern TreeNode_0099aaa0* g_treeRoot_06070ab4;

// src: GUESS (confidence: low) [0x0099aaa0]
TreeNode_0099aaa0* FindNode_0099aaa0(int a, int b)
{
    TreeNode_0099aaa0* node = g_treeRoot_06070ab4;
    while (node)
    {
        int cmp = a - node->m_a;
        if (cmp == 0)
            cmp = b - node->m_b;
        if (cmp < 0)
            node = node->m_left;
        else if (cmp > 0)
            node = (TreeNode_0099aaa0*)(node->m_rightTagged & ~3u);
        else
            return node;
    }
    return 0;
}
