#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low)
struct UnkObj_004727d0
{
    char m_pad[0x118];
    CRITICAL_SECTION m_cs;
    char m_flag;

    void SetFlag_004727d0(char flag);
};

// src: GUESS (confidence: medium) [0x004727d0]
void UnkObj_004727d0::SetFlag_004727d0(char flag)
{
    EnterCriticalSection(&m_cs);
    m_flag = flag;
    LeaveCriticalSection(&m_cs);
}
