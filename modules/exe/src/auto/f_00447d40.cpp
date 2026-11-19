// Returns flag 0x1e of the data block, or false when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::GetFlag1E()
{
    bool result = false;
    if (GetData())
        result = GetData()->m_flag1e;
    return result;
}
