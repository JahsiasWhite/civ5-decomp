#include "Unk_0082d030.h"

// Counts the chain from m_first, stopping after the first node whose link at
// 0x10 is empty.
int UnkNodeCursor_0082d030::CountChildren()
{
    int count = 0;
    if (m_node) {
        for (UnkNode_0082d030* child = m_node->m_first; child; child = child->m_next) {
            ++count;
            if (!child->m_link10)
                break;
        }
    }
    return count;
}
