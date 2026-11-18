// Forwards to the linked object, or returns true when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::QueryLinked22()
{
    if (GetLinked())
        return GetLinked()->Query22();
    return true;
}
