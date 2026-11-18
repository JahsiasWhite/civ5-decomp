// c5d-review: vtable pointer written through a declared array instead of a real
// virtual class (same as the constructor 0x004c2cc0); replace once the virtuals are known.
#include "Class_004c2cc0.h"

void Class_004c2cc0::Destroy()
{
    vtable = kVtable_00a72c88;
    if (!m_onDestroy.IsEmpty())
        m_onDestroy();
}
