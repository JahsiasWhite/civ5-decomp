#include "Unk_00920300.h"

int Unk_00920300::GetFirstValue(int index)
{
    if (index >= 0 && index <= m_firstLast)
        return m_first[index].m_value;
    return 0;
}
