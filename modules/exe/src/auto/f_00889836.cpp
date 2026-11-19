// c5d-cflags: -/O2 +/O1   (this library was built for size)
#include "Unk_06198000.h"

// src: GUESS (confidence: low) [0x00926390]
unsigned long __stdcall ServiceThunk_00926390(unsigned long a1) {
    if (!g_serviceActive_0606c9d4)
        return UNK_SERVICE_NOT_ACTIVE;
    return g_serviceTable_06198000->m_fn14(a1);
}
