// Releases the wrapped critical section.

#include "FCriticalSection.h"

void FCriticalSection::Delete()
{
    DeleteCriticalSection(&m_cs);
}
