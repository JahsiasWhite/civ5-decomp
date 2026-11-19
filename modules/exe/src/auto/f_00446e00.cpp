// Returns value 0x24 of the info block, or 0 when there is none.

#include "FieldHolder_007e9250.h"

int FieldHolder_007e9250::GetInfo24()
{
    int result = 0;
    if (GetInfo())
        result = GetInfo()->m_value24;
    return result;
}
