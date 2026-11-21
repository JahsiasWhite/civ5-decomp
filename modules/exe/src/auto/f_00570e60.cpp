// src: GUESS (confidence: low)
struct UnkLeaf_00570e60
{
    char m_pad00[0x14];
    int m_val14;
    int m_val18;
};

// src: GUESS (confidence: low)
struct UnkNode_00570e60
{
    char m_pad00[0x4c];
    int m_count;
    UnkLeaf_00570e60** m_items;
};

// src: GUESS (confidence: low)
struct UnkOwner_00570e60
{
    char m_pad00[0x1424];
    UnkNode_00570e60** m_nodes;
    char m_pad1428[0x34];
    int m_nodeCount;
};

// src: GUESS (confidence: low)
struct UnkSink_00570e60
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
struct UnkManager_00570e60
{
    char m_pad00[0x28c];
    UnkSink_00570e60* m_sink;

    void Accumulate_00570e60(UnkOwner_00570e60* owner);
};

// src: GUESS (confidence: medium) [0x00570e60]
void UnkManager_00570e60::Accumulate_00570e60(UnkOwner_00570e60* owner)
{
    unsigned int total = 0;
    UnkNode_00570e60** cur = owner->m_nodes;
    UnkNode_00570e60** end = cur + owner->m_nodeCount;
    for (; cur != end; ++cur)
    {
        UnkNode_00570e60* node = *cur;
        if (node && node->m_count > 0)
        {
            for (unsigned int i = 0; i < (unsigned int)node->m_count; ++i)
            {
                UnkLeaf_00570e60* leaf = node->m_items[i];
                total += (leaf && leaf->m_val18) ? leaf->m_val14 : 0;
            }
        }
    }
    if (total > 0)
        m_sink->V8(m_sink->V7() + total);
}
