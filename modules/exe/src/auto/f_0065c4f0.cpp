typedef unsigned int uint32_t;
typedef int int32_t;

// src: GUESS (confidence: low) [0x0065c4f0]
struct Node65C4F0 {
    uint32_t m_next;
    uint32_t m_unk04;
    uint32_t m_flags;
    uint32_t m_unk0C;
};

// src: GUESS (confidence: low) [0x0065c4f0]
struct F65C4F0 {
    uint32_t    m_head;
    int32_t     m_count;
    Node65C4F0* m_nodes;

    // src: GUESS (confidence: low) [0x0065c4f0]
    void freeNode(uint32_t idx);
};

void F65C4F0::freeNode(uint32_t idx) {
    Node65C4F0* node = &m_nodes[idx];
    node->m_flags |= 0x100;
    uint32_t head = m_head;
    if (idx < head) {
        node->m_next = head;
        m_count--;
        m_head = idx;
    } else {
        Node65C4F0* headNode = &m_nodes[head];
        node->m_next = headNode->m_next;
        headNode->m_next = idx;
        m_count--;
    }
}
