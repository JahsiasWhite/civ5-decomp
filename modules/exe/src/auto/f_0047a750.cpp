#include "Unk_0082d030.h"

bool UnkNodeCursor_0082d030::GetNext(UnkNodeCursor_0082d030* out)
{
    if (m_node && m_node->m_next) {
        out->m_node = m_node->m_next;
        return true;
    }
    return false;
}
