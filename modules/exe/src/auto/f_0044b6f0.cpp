// src: GUESS (confidence: low)
struct TreeNode_0044b6f0;

// src: GUESS (confidence: low)
struct Tree_0044b6f0 {
    int m_00;
    TreeNode_0044b6f0* m_head;
};

// src: GUESS (confidence: low)
struct TreeNode_0044b6f0 {
    TreeNode_0044b6f0* m_left;
    TreeNode_0044b6f0* m_parent;
    TreeNode_0044b6f0* m_right;
    char m_pad[0x1d];
    char m_isNil;

    void Rrotate(Tree_0044b6f0* tree);
};

// src: GUESS (confidence: medium) [0x0044b6f0]
void TreeNode_0044b6f0::Rrotate(Tree_0044b6f0* tree) {
    TreeNode_0044b6f0* p = m_left;
    m_left = p->m_right;
    if (!p->m_right->m_isNil) {
        p->m_right->m_parent = this;
    }
    p->m_parent = m_parent;
    if (this == tree->m_head->m_parent) {
        tree->m_head->m_parent = p;
    } else if (this == m_parent->m_right) {
        m_parent->m_right = p;
    } else {
        m_parent->m_left = p;
    }
    p->m_right = this;
    m_parent = p;
}
