// Sets a flag in the data block, when there is one.

#include "FieldHolder_007e9250.h"

void FieldHolder_007e9250::SetFlag1E(bool value)
{
    if (GetData())
        GetData()->m_flag1e = value;
}
