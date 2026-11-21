// src: GUESS (confidence: low)
struct UnkLeaf_0056cf30
{
    char m_pad00[0x14];
    int m_val14;
    int m_val18;
};

// src: GUESS (confidence: low)
struct UnkNode_0056cf30
{
    char m_pad00[0x4c];
    int m_count;
    UnkLeaf_0056cf30** m_items;
};

// src: GUESS (confidence: low)
struct UnkOwner_0056cf30
{
    char m_pad00[0x13d0];
    UnkNode_0056cf30** m_nodes;
    char m_pad13d4[0x34];
    int m_nodeCount;
};

// src: GUESS (confidence: low)
struct UnkSink_0056cf30
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
struct UnkManager_0056cf30
{
    char m_pad00[0x28c];
    UnkSink_0056cf30* m_sink;

    void Accumulate_0056cf30(UnkOwner_0056cf30* owner);
};

// src: GUESS (confidence: medium) [0x0056cf30]
void UnkManager_0056cf30::Accumulate_0056cf30(UnkOwner_0056cf30* owner)
{
    unsigned int total = 0;
    UnkNode_0056cf30** cur = owner->m_nodes;
    UnkNode_0056cf30** end = cur + owner->m_nodeCount;
    for (; cur != end; ++cur)
    {
        UnkNode_0056cf30* node = *cur;
        if (node && node->m_count > 0)
        {
            for (unsigned int i = 0; i < (unsigned int)node->m_count; ++i)
            {
                UnkLeaf_0056cf30* leaf = node->m_items[i];
                total += (leaf && leaf->m_val18) ? leaf->m_val14 : 0;
            }
        }
    }
    if (total > 0)
        m_sink->V8(m_sink->V7() + total);
}
