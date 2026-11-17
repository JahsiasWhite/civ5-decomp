// Returns field +0x4 of the linked object, or 0 when there is none.

#include "UnkLinkedHolder.h"

int UnkLinkedHolder::GetTargetField4()
{
    int value = 0;
    UnkLinkedTarget* target = m_pTarget;
    if (target)
        value = target->m_04;
    return value;
}
