// src: GUESS (confidence: low)
struct Node_00567250 {
    int left;
    int m_04;
    int right;
    int parent;
    char pad[0xa0];
};

// src: GUESS (confidence: low)
struct Container_00567250 {
    int m_00;
    int m_04;
    Node_00567250* m_nodes;
};

// src: GUESS (confidence: low)
struct Iter_00567250 {
    Container_00567250* m_cont;
    int m_idx;

    int Prev();
};

// src: GUESS (confidence: medium) [0x00567250]
int Iter_00567250::Prev() {
    Node_00567250* node = &m_cont->m_nodes[m_idx];
    int left = node->left;
    if (left != 0xfffffff) {
        Node_00567250* nodes = m_cont->m_nodes;
        int r = nodes[left].right;
        while (r != 0xfffffff) {
            left = r;
            r = nodes[r].right;
        }
        return left;
    }
    int p = node->parent;
    if (p != 0xfffffff) {
        return p;
    }
    return 0xfffffff;
}
