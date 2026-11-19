// c5d-cflags: -/O2 -/Ob1 +/Od   (this part of the exe was built unoptimised)
#include "Unk_008a30b0.h"

// The block's data, at the offset its header records. (In this unoptimised
// code the stack slots follow the local names, so keep p/result.)
// src: GUESS (confidence: low) [0x008a30b0]
void* GetBlockData_008a30b0(UnkBlockHeader_008a30b0* block)
{
    UnkBlockHeader_008a30b0* p = block;
    void* result = (char*)block + p->m_dataOffset;
    return result;
}
