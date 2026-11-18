#include "Unk_0092bd60.h"

// Entry index counting back from the last one, or null when out of range.
// src: GUESS (confidence: low) [0x0092bd60]
UnkEntry28_0092bd60* GetEntryFromEnd_0092bd60(unsigned int index)
{
    if (index < 66)
        return &g_table_00ca1a30[66 - 1 - index];
    return 0;
}
