// src: GUESS (confidence: low)
struct UnkLeaf_00567440
{
    char m_pad00[0x14];
    int m_val14;
    int m_val18;
};

// src: GUESS (confidence: low)
struct UnkNode_00567440
{
    char m_pad00[0x4c];
    int m_count;
    UnkLeaf_00567440** m_items;
};

// src: GUESS (confidence: low)
struct UnkOwner_00567440
{
    char m_pad00[0x13d4];
    UnkNode_00567440** m_nodes;
    char m_pad13d8[0x34];
    int m_nodeCount;
};

// src: GUESS (confidence: low)
struct UnkSink_00567440
{
    virtual void V0() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual unsigned int V7() { return 0; }
    virtual void V8(unsigned int) {}
};

// src: GUESS (confidence: low)
struct UnkManager_00567440
{
    char m_pad00[0x28c];
    UnkSink_00567440* m_sink;

    void Accumulate_00567440(UnkOwner_00567440* owner);
};

// src: GUESS (confidence: medium) [0x00567440]
void UnkManager_00567440::Accumulate_00567440(UnkOwner_00567440* owner)
{
    unsigned int total = 0;
    UnkNode_00567440** cur = owner->m_nodes;
    UnkNode_00567440** end = cur + owner->m_nodeCount;
    for (; cur != end; ++cur)
    {
        UnkNode_00567440* node = *cur;
        if (node && node->m_count > 0)
        {
            for (unsigned int i = 0; i < (unsigned int)node->m_count; ++i)
            {
                UnkLeaf_00567440* leaf = node->m_items[i];
                total += (leaf && leaf->m_val18) ? leaf->m_val14 : 0;
            }
        }
    }
    if (total > 0)
        m_sink->V8(m_sink->V7() + total);
}
