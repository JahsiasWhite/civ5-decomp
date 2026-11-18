#pragma once

// Placeholder: the object at 0x44 of 0x0089a880's argument, which copies its
// field at 0x124 to 0x12c. Rename once the owning type is known.

// src: GUESS (confidence: low) [0x0089a880]
struct UnkState_0089a880
{
    char m_unk000[0x124];
    int m_source;       // 0x124
    int m_unk128;
    int m_target;       // 0x12c
};

// src: GUESS (confidence: low) [0x0089a880]
struct UnkStateOwner_0089a880
{
    char m_unk00[0x44];
    UnkState_0089a880* m_state;     // 0x44
};
