#include "Unk_0082d030.h"

bool UnkNodeCursor_0082d030::GetFirst(UnkNodeCursor_0082d030* out)
{
    if (m_node && m_node->m_first) {
        out->m_node = m_node->m_first;
        return true;
    }
    return false;
}
