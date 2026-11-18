// Forwards to the linked object, or returns 0 when there is none.

#include "FieldHolder_007e9250.h"

int FieldHolder_007e9250::QueryLinked23()
{
    if (GetLinked())
        return GetLinked()->Query23();
    return 0;
}
