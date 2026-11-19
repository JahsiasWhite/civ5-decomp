#include "Unk_0082d030.h"

bool UnkNodeCursor_0082d030::GetLink2c(UnkNodeCursor_0082d030* out)
{
    if (m_node && m_node->m_link2c) {
        out->m_node = m_node->m_link2c;
        return true;
    }
    return false;
}
