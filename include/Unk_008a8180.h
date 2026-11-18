#pragma once

// Placeholders for 0x008a8180 and 0x008a85b0, which sit just before the NVAPI
// wrappers and were built unoptimised like them. Rename once the types are known.

// src: GUESS (confidence: low) [0x008a8180]
struct UnkFloatHolder_008a8180
{
    int m_unk00[2];
    float m_value;      // 0x08
};

// src: GUESS (confidence: low) [0x008a8180]
struct UnkDevice_008a8180
{
    char m_unk000[0x200];
    int m_unk200;                           // 0x200
    int m_unk204;                           // 0x204
    char m_unk208[0x110];
    UnkFloatHolder_008a8180* m_holder;      // 0x318
};
