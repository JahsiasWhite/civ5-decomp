#include "Unk_0091c050.h"

// The item at index, or null when it's out of range.
void* Unk_0091c050::GetAt(unsigned int index)
{
    if (index < m_items.size())
        return m_items[index];
    return 0;
}
