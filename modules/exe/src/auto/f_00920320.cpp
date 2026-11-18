#include "Unk_00920300.h"

int Unk_00920300::GetSecondValue(int index)
{
    if (index >= 0 && index <= m_secondLast)
        return m_second[index].m_value;
    return 0;
}
