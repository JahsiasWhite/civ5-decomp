// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class (same as 0x0082b490); replace once the virtual methods are known.
#include "Unk_00b88c18.h"

Unk_00b88c18::Unk_00b88c18()
{
    m_enabled = true;
    m_count = 1;
    m_vftable = g_vtable_00b88c18;
    m_unk0c = 0;
    m_unk10 = 0;
}
