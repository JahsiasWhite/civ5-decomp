// Forwards the check to the linked object; true when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::LinkedCheck16(int a, int b, int c)
{
    bool result = true;
    if (GetLinked())
        result = GetLinked()->Check16(a, b, c);
    return result;
}
