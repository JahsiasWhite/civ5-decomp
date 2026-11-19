// Points a cursor at a node chain and walks it to the last node; returns itself.

// src: GUESS (confidence: low)
struct ChainNode_006494d0
{
    char m_pad0[8];
    // src: GUESS (confidence: low)
    int m_next;
    char m_padC[0xb0 - 0xc];
};

// src: GUESS (confidence: low)
struct ChainPool_006494d0
{
    char m_pad0[8];
    // src: GUESS (confidence: low)
    ChainNode_006494d0* m_nodes;
};

// src: GUESS (confidence: low)
struct ChainCursor_006494d0
{
    // src: GUESS (confidence: low) [0x006494d0]
    ChainCursor_006494d0& SeekLast(int index, ChainPool_006494d0* pool);

    // src: GUESS (confidence: low)
    ChainPool_006494d0* m_pool;
    // src: GUESS (confidence: low)
    int m_index;
};

ChainCursor_006494d0& ChainCursor_006494d0::SeekLast(int index, ChainPool_006494d0* pool)
{
    m_pool = pool;
    m_index = index;
    while (index != 0x0fffffff)
    {
        m_index = index;
        index = pool->m_nodes[index].m_next;
    }
    return *this;
}
