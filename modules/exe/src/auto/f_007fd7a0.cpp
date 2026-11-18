// Returns value 8 of the info block, or -1 when there is none.

#include "FieldHolder_007e9250.h"

int FieldHolder_007e9250::GetInfo08()
{
    int result = -1;
    if (GetInfo())
        result = GetInfo()->m_value08;
    return result;
}
