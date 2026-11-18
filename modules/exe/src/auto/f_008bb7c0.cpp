#include "Unk_03010580.h"

// src: GUESS (confidence: low) [0x008bb7c0]
void NotifyComObject_008bb7c0()
{
    if (g_enabled_02f65e3e && g_comObject_03010580)
        g_comObject_03010580->Slot10(1, 0);
}
