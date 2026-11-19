// c5d-cflags: -/O2 -/Ob1 +/Od -/arch:SSE2 -/fp:fast   (unoptimised x87 code, like the NVAPI wrappers after it)
#include "Unk_008a8180.h"

// src: GUESS (confidence: low) [0x008a8180]
void SetHolderValue_008a8180(UnkDevice_008a8180* device, float value)
{
    UnkFloatHolder_008a8180* holder = device->m_holder;
    holder->m_value = value;
}
