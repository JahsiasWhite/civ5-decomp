// If any later node in the chain is dirty, marks this node and every node
// before that one dirty too.

// src: GUESS (confidence: low)
class ChainNode_007bebd0
{
public:
    // src: GUESS (confidence: low) [0x007bebd0]
    void PropagateDirty();

    int m_00;
    // src: GUESS (confidence: low)
    ChainNode_007bebd0* m_next;
    char m_pad8[0x7c - 8];
    // src: GUESS (confidence: low)
    int m_dirty;
};

void ChainNode_007bebd0::PropagateDirty()
{
    ChainNode_007bebd0* dirty = m_next;
    while (dirty && !dirty->m_dirty)
        dirty = dirty->m_next;
    if (!dirty)
        return;
    ChainNode_007bebd0* node = this;
    do
    {
        node->m_dirty = 1;
        node = node->m_next;
    } while (node != dirty);
}
