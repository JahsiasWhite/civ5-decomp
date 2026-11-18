// Forwards to the linked object, or returns false when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::QueryLinked14()
{
    if (GetLinked())
        return GetLinked()->Query14();
    return false;
}
