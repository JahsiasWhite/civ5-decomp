// c5d-cflags: -/arch:SSE2 +/arch:SSE   (this function keeps doubles on the x87 stack)
#include "Unk_05f54f38.h"

// src: GUESS (confidence: low) [0x005fb630]
int IsValueZero_005fb630()
{
    return g_unk_05f54f38->m_value == 0.0;
}
