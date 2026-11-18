// Forwards the check to the linked object; true when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::LinkedCheck8(int a)
{
    bool result = true;
    if (GetLinked())
        result = GetLinked()->Check8(a);
    return result;
}
