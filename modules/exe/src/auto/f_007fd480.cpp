// c5d-cflags: -/O2 -/Ob1 +/Od   (this part of the exe was built unoptimised)
#include "Unk_008973f0.h"

// src: GUESS (confidence: low) [0x008973f0]
void CopyBlock_008973f0(UnkBlockOwner_008973f0* owner, const UnkBlock120_008973f0* src)
{
    *owner->m_block = *src;
}
