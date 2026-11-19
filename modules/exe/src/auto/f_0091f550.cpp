#include "Unk_009bc170.h"

int ReachedThreshold_009bc170(const Unk_009bc170* item)
{
    if ((item->m_flags & 2) && item->m_value >= item->m_threshold)
        return 1;
    return 0;
}
