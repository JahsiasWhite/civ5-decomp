// c5d-cflags: -/O2 -/Ob1 +/Od   (this part of the exe was built unoptimised)
#include "Unk_008a8180.h"

// src: GUESS (confidence: low) [0x008a85b0]
void SetPair_008a85b0(UnkDevice_008a8180* device, int second, int first)
{
    device->m_unk200 = first;
    device->m_unk204 = second;
}
