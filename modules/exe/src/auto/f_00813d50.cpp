// Enters the wrapped critical section.

#include "FCriticalSection.h"

void FCriticalSection::Enter()
{
    EnterCriticalSection(&m_cs);
}
