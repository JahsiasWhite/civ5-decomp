// c5d-cflags: -/O2 -/Ob1 +/Od   (this part of the exe was built unoptimised)
#include "Unk_0089a880.h"

// src: GUESS (confidence: low) [0x0089a880]
void SyncState_0089a880(UnkStateOwner_0089a880* owner)
{
    owner->m_state->m_target = owner->m_state->m_source;
}
