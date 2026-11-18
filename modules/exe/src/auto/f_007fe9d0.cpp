// Forwards the check to the linked object; true when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::LinkedCheck15(int a, int b)
{
    bool result = true;
    if (GetLinked())
        result = GetLinked()->Check15(a, b);
    return result;
}
