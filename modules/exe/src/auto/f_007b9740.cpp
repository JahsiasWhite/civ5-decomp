#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low)
struct UnkObj_007b9740
{
    char m_pad[0x16c];
    CRITICAL_SECTION m_cs;
    int m_val;

    void SetVal_007b9740(int val);
};

// src: GUESS (confidence: medium) [0x007b9740]
void UnkObj_007b9740::SetVal_007b9740(int val)
{
    EnterCriticalSection(&m_cs);
    m_val = val;
    LeaveCriticalSection(&m_cs);
}
