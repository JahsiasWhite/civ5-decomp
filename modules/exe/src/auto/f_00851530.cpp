#include "Unk_008eb8d0.h"

// The first item, or null when there are none.
void** Unk_008eb8d0::GetItems()
{
    if (m_items.size() > 0)
        return &m_items[0];
    return 0;
}
