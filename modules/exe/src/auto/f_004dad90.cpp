// src: GUESS (confidence: low)
struct Node176_0043e7d0 {
    int m_val;
    int m_04;
    int m_08;
    int m_next;
    int m_pad[40];
};

// src: GUESS (confidence: low)
struct Host_0043e7d0;

// src: GUESS (confidence: low)
struct NodeIter_0043e7d0 {
    NodeIter_0043e7d0(Host_0043e7d0* host, int val) : m_host(host), m_val(val) {}
    NodeIter_0043e7d0(const NodeIter_0043e7d0& o) : m_host(o.m_host), m_val(o.m_val) {}
    Host_0043e7d0* m_host;
    int m_val;
};

// src: GUESS (confidence: low) [0x0043e7d0]
struct Host_0043e7d0 {
    int m_00;
    int m_04;
    Node176_0043e7d0* m_nodes;

    // src: GUESS (confidence: low) [0x0043e7d0]
    NodeIter_0043e7d0 NextValid(int index);
};

// src: GUESS (confidence: low) [0x0043e7d0]
NodeIter_0043e7d0 Host_0043e7d0::NextValid(int index) {
    Node176_0043e7d0* nodes = m_nodes;
    Node176_0043e7d0* p = &nodes[index];
    int v = p->m_val;
    if (v == 0xfffffff) {
        do {
            int nxt = p->m_next;
            if (nxt == 0xfffffff) {
                return NodeIter_0043e7d0(this, 0xfffffff);
            }
            p = &nodes[nxt];
            v = p->m_val;
        } while (v == 0xfffffff);
    }
    return NodeIter_0043e7d0(this, v);
}
