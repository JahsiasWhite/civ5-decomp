// Forwards to the linked object, or returns false when there is none.

#include "FieldHolder_007e9250.h"

bool FieldHolder_007e9250::QueryLinked13()
{
    if (GetLinked())
        return GetLinked()->Query13();
    return false;
}
