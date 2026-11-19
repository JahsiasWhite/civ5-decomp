// Forwards the check to the linked object; true when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::LinkedCheck10(int a)
{
    bool result = true;
    if (GetLinked())
        result = GetLinked()->Check10(a);
    return result;
}
