#pragma once

// Placeholder: the object at 0x44 of 0x0089a880's argument: a list head at 0x124
// and a cursor at 0x12c that 0x0089a880 resets and 0x0089a8a0 advances.
// Rename once the owning type is known.

// src: GUESS (confidence: low) [0x0089a8a0]
struct UnkLink_0089a880
{
    UnkLink_0089a880* m_next;
};

// src: GUESS (confidence: low) [0x0089a880]
struct UnkState_0089a880
{
    char m_unk000[0x124];
    UnkLink_0089a880* m_source;     // 0x124
    int m_unk128;
    UnkLink_0089a880* m_target;     // 0x12c
};

// src: GUESS (confidence: low) [0x0089a880]
struct UnkStateOwner_0089a880
{
    char m_unk00[0x44];
    UnkState_0089a880* m_state;     // 0x44
};
