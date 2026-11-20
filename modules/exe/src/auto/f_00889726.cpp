// c5d-cflags: -/O2 +/O1
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low)
struct UnkServiceTable;

// src: GUESS (confidence: low) [0x05efd368]
extern HMODULE g_hModule_05efd368;
// src: EXE [0x06028ac0]
extern UnkServiceTable* g_serviceTable_06198000;

// src: GUESS (confidence: medium) [0x00889726]
int UnloadServiceLibrary_00889726()
{
    if (g_hModule_05efd368)
    {
        FreeLibrary(g_hModule_05efd368);
        g_hModule_05efd368 = 0;
    }
    g_serviceTable_06198000 = 0;
    return 1;
}
