// src: GUESS (confidence: low)
struct TreeNode_00482460;

// src: GUESS (confidence: low)
struct Tree_00482460 {
    int m_00;
    TreeNode_00482460* m_head;
};

// src: GUESS (confidence: low)
struct TreeNode_00482460 {
    TreeNode_00482460* m_left;
    TreeNode_00482460* m_parent;
    TreeNode_00482460* m_right;
    char m_pad[0x9];
    char m_isNil;

    void Rrotate(Tree_00482460* tree);
};

// src: GUESS (confidence: medium) [0x00482460]
void TreeNode_00482460::Rrotate(Tree_00482460* tree) {
    TreeNode_00482460* p = m_left;
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
