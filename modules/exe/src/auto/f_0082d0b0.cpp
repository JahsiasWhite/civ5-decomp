#include "Unk_0082d030.h"

bool UnkNodeCursor_0082d030::GetLink10(UnkNodeCursor_0082d030* out)
{
    if (m_node && m_node->m_link10) {
        out->m_node = m_node->m_link10;
        return true;
    }
    return false;
}
