#include "Unk_008e7ff0.h"

// Clears the block and returns what was held, or null when nothing was.
void* Unk_008e7ff0::Detach()
{
    void* object = 0;
    if (m_object) {
        object = m_object;
        m_object = 0;
        m_unk20[0] = 0;
        m_unk20[1] = 0;
        m_unk20[2] = 0;
        m_unk20[3] = 0;
        m_unk20[4] = 0;
    }
    return object;
}
