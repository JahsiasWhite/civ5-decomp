// c5d-review: the four vtable pointers are written through declared arrays instead
// of a real class hierarchy (same as 0x0083ee60); replace once the bases are known.
#include "Unk_00b898d8.h"

void Unk_00b898d8::ResetVtables()
{
    m_vtable0c = kVtable_00b898c4;
    m_vtable8 = kVtable_00b898ac;
    m_vtable4 = kVtable_00b898a0;
    m_vtable0 = kVtable_00b89890;
}
