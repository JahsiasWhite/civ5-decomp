// c5d-model: claude-opus-5-5
// Returns 0x60 when the object's virtual "kind" query, adjusted by whether the
// field at +0xAC is empty, equals -0xB8; otherwise returns 0.

#include "KindQueryObject.h"

int KindQueryObject::GetKindFlags()
{
    return (GetKind() + (m_ac == 0) + 0xB8 != 0) ? 0 : 0x60;
}
