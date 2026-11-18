// Forwards the check to the linked object; true when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::LinkedCheck11(int a, int b)
{
    bool result = true;
    if (GetLinked())
        result = GetLinked()->Check11(a, b);
    return result;
}
