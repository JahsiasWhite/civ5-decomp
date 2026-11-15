// Returns 0x60 when the object's virtual "kind" query, adjusted by whether the
// field at +0xAC is empty, equals -0xB8; otherwise returns 0.

#include "KindQueryObject.h"

int KindQueryObject::GetKindFlags()
{
    int kind = GetKind();
    return (kind + 0xB8 + (m_ac == 0) != 0) ? 0 : 0x60;
}
