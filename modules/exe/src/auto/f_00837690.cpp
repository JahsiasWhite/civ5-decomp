// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class (as in the base constructor 0x0082b440); replace once the virtuals are known.
#include "Unk_00b89800.h"

Unk_00b89800::Unk_00b89800()
{
    m_enabled = true;
    m_count = 1;
    m_unk0c = 0;
    m_unk10 = 0;
    m_vftable = g_vtable_00b89800;
    m_child = 0;
}
