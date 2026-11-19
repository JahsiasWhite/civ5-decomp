#include "Unk_008ec800.h"

// Only types 2-4 carry the value.
bool Unk_008ec800::HasValue()
{
    switch (m_type) {
    case 2:
        return m_value != 0;
    case 3:
        return m_value != 0;
    case 4:
        return m_value != 0;
    default:
        return false;
    }
}
