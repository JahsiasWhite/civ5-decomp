#include "Unk_00b88b8c.h"

Unk_00b88b8c::~Unk_00b88b8c()
{
    CloseHandle(m_handle);
    DeleteCriticalSection(&m_lock);
}
