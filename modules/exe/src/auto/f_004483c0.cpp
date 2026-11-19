// Forwards the value to the linked object, if there is one.

#include "FieldHolder_007e9250.h"

void FieldHolder_007e9250::ApplyLinked9(int value)
{
    if (GetLinked())
        GetLinked()->Apply9(value);
}
