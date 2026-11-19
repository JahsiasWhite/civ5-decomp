// Forwards to the linked object, or returns 0 when there is none.

#include "FieldHolder_007e9250.h"

int FieldHolder_007e9250::QueryLinked21()
{
    if (GetLinked())
        return GetLinked()->Query21();
    return 0;
}
