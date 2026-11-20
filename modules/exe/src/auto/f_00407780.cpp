#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low) [0x05f01cd0]
extern DWORD g_numProcs_00407780;

// src: GUESS (confidence: high) [0x00407780]
DWORD GetNumProcsMinus1_00407780()
{
    DWORD n = g_numProcs_00407780;
    if (n == 0)
    {
        SYSTEM_INFO si;
        GetSystemInfo(&si);
        n = si.dwNumberOfProcessors;
        g_numProcs_00407780 = n;
    }
    return n - 1;
}
