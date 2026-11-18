#include "Unk_04170b80.h"

// The record at index, or null when it's out of range.
// src: GUESS (confidence: medium) [0x008bc840]
UnkRecord398_04170b80* __stdcall GetRecord_008bc840(unsigned int index)
{
    if (index < g_recordCount_0413e300)
        return &g_records_04170b80[index];
    return 0;
}
