// c5d-cflags: -/O2 +/O1   (this library was built for size)
#include "Unk_06198000.h"

// src: GUESS (confidence: low) [0x009263f4]
unsigned long __stdcall ServiceThunk_009263f4(unsigned long a1, unsigned long a2, unsigned long a3) {
    if (!g_serviceActive_0606c9d4)
        return UNK_SERVICE_NOT_ACTIVE;
    return g_serviceTable_06198000->m_fn34(a1, a2, a3);
}
