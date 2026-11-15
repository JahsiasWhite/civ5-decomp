// c5d-model: claude-opus-5-5
// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
#include "UnkStateHolder.h"

// Returns the +0x120 field of the holder's state block.
int UnkStateHolder_GetField120(UnkStateHolder* holder)
{
    return holder->state->field_120;
}
