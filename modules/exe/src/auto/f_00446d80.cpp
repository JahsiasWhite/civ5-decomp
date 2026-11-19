// Returns value 0x28 of the data block, or 0 when there is none.

#include "FieldHolder_007e9250.h"

int FieldHolder_007e9250::GetData28()
{
    int result = 0;
    if (GetData())
        result = GetData()->m_value28;
    return result;
}
