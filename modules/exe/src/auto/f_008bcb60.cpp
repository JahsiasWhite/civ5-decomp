#include "Unk_0313de88.h"

// Copies the record at index into *out.
// src: GUESS (confidence: medium) [0x008bcb60]
void __stdcall CopyRecord_008bcb60(int index, UnkRecord80_0313de88* out)
{
    *out = g_records_0313de88[index];
}
