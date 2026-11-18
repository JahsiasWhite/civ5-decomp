#include "Unk_007553a0.h"

// This object when it has the given type id, else null.
void* UnkTyped_007553a0::CastTo(const int& typeId)
{
    return GetTypeId() == typeId ? this : 0;
}
