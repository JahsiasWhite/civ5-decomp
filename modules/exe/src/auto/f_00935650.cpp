#include "Unk_00935650.h"

// Entry index counting back from the last one, or null when out of range.
// src: GUESS (confidence: low) [0x00935650]
UnkEntry28_00935650* GetEntryFromEnd_00935650(unsigned int index)
{
    if (index < 7)
        return &g_table_00ca2890[7 - 1 - index];
    return 0;
}
