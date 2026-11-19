// Stores the flag, but only while the info value at 0x24 is above 1;
// otherwise clears it.

#include "FieldHolder_007e9250.h"

void FieldHolder_007e9250::SetFlag84(bool value)
{
    if (GetInfo24() <= 1)
        value = false;
    m_flag84 = value;
}
