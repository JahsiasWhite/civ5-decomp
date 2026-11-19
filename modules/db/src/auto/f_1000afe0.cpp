// c5d-cflags: -/EHsc +/GS-
// src: GUESS (confidence: low)
struct ArenaPool_10008660
{
    char m_pad[0x10010];
    // src: EXE [0x10008660]
    void Reset();
    ~ArenaPool_10008660()
    {
        Reset();
    }
};

// src: GUESS (confidence: low)
struct NodeA_1000afe0
{
    int m_pad00[4];
    int m_owner;
    int m_pad14[6];
    NodeA_1000afe0* m_next2c;
};

// src: GUESS (confidence: low)
struct NodeB_1000afe0
{
    int m_pad00[4];
    int m_owner;
    int m_pad14;
    NodeB_1000afe0* m_next18;
};

// src: GUESS (confidence: low)
struct ArenaData_1000afe0
{
    int m_pad00[6];
    NodeA_1000afe0* m_headA;
    int m_pad1c;
    NodeB_1000afe0* m_headB;
    int m_pad24[3];
    ArenaPool_10008660 m_pool;

    void Clear()
    {
        for (NodeA_1000afe0* a = m_headA; a; a = a->m_next2c)
        {
            a->m_owner = 0;
        }
        m_headA = 0;
        for (NodeB_1000afe0* b = m_headB; b; b = b->m_next18)
        {
            b->m_owner = 0;
        }
        m_headB = 0;
        m_pool.Reset();
    }
};

// src: GUESS (confidence: low)
struct XmlDoc_1000afe0
{
    // src: GUESS (confidence: high) [0x1000afe0]
    ~XmlDoc_1000afe0();
    virtual void Dummy();

    ArenaData_1000afe0* m_data;
};

XmlDoc_1000afe0::~XmlDoc_1000afe0()
{
    m_data->Clear();
    delete m_data;
}
