// Forwards to the linked object, or returns 0 when there is none.

#include "FieldHolder_007e9250.h"

int FieldHolder_007e9250::QueryLinked28()
{
    if (GetLinked())
        return GetLinked()->Query28();
    return 0;
}
