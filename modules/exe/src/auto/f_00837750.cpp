#include "Unk_00b89800.h"

// True when there is no child or the child reports ready.
int Unk_00b89800::IsChildReady()
{
    if (!m_child || m_child->IsReady())
        return 1;
    return 0;
}
