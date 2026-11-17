// Leaves the wrapped critical section.

#include "FCriticalSection.h"

void FCriticalSection::Leave()
{
    LeaveCriticalSection(&m_cs);
}
