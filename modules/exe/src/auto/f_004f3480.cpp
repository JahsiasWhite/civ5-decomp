// src: GUESS (confidence: low)
struct UnkLeaf_004f3480
{
    char m_pad00[0x14];
    int m_val14;
    int m_val18;
};

// src: GUESS (confidence: low)
struct UnkNode_004f3480
{
    char m_pad00[0x4c];
    int m_count;
    UnkLeaf_004f3480** m_items;
};

// src: GUESS (confidence: low)
struct UnkOwner_004f3480
{
    char m_pad00[0x13cc];
    UnkNode_004f3480** m_nodes;
    char m_pad13d0[0x34];
    int m_nodeCount;
};

// src: GUESS (confidence: low)
struct UnkSink_004f3480
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
struct UnkManager_004f3480
{
    char m_pad00[0x28c];
    UnkSink_004f3480* m_sink;

    void Accumulate_004f3480(UnkOwner_004f3480* owner);
};

// src: GUESS (confidence: medium) [0x004f3480]
void UnkManager_004f3480::Accumulate_004f3480(UnkOwner_004f3480* owner)
{
    unsigned int total = 0;
    UnkNode_004f3480** cur = owner->m_nodes;
    UnkNode_004f3480** end = cur + owner->m_nodeCount;
    for (; cur != end; ++cur)
    {
        UnkNode_004f3480* node = *cur;
        if (node && node->m_count > 0)
        {
            for (unsigned int i = 0; i < (unsigned int)node->m_count; ++i)
            {
                UnkLeaf_004f3480* leaf = node->m_items[i];
                total += (leaf && leaf->m_val18) ? leaf->m_val14 : 0;
            }
        }
    }
    if (total > 0)
        m_sink->V8(m_sink->V7() + total);
}
