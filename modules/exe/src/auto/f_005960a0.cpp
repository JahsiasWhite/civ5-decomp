// src: GUESS (confidence: low)
struct UnkLeaf_005960a0
{
    char m_pad00[0x14];
    int m_val14;
    int m_val18;
};

// src: GUESS (confidence: low)
struct UnkNode_005960a0
{
    char m_pad00[0x4c];
    int m_count;
    UnkLeaf_005960a0** m_items;
};

// src: GUESS (confidence: low)
struct UnkOwner_005960a0
{
    char m_pad00[0x13e8];
    UnkNode_005960a0** m_nodes;
    char m_pad13ec[0x34];
    int m_nodeCount;
};

// src: GUESS (confidence: low)
struct UnkSink_005960a0
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
struct UnkManager_005960a0
{
    char m_pad00[0x28c];
    UnkSink_005960a0* m_sink;

    void Accumulate_005960a0(UnkOwner_005960a0* owner);
};

// src: GUESS (confidence: medium) [0x005960a0]
void UnkManager_005960a0::Accumulate_005960a0(UnkOwner_005960a0* owner)
{
    unsigned int total = 0;
    UnkNode_005960a0** cur = owner->m_nodes;
    UnkNode_005960a0** end = cur + owner->m_nodeCount;
    for (; cur != end; ++cur)
    {
        UnkNode_005960a0* node = *cur;
        if (node && node->m_count > 0)
        {
            for (unsigned int i = 0; i < (unsigned int)node->m_count; ++i)
            {
                UnkLeaf_005960a0* leaf = node->m_items[i];
                total += (leaf && leaf->m_val18) ? leaf->m_val14 : 0;
            }
        }
    }
    if (total > 0)
        m_sink->V8(m_sink->V7() + total);
}
