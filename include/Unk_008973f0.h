#pragma once

// Placeholder: a 0x120-byte block copied whole into the buffer that the
// owner points to at 0x128. Rename once the owning type is known.

// src: GUESS (confidence: low) [0x008973f0]
struct UnkBlock120_008973f0
{
    int m_data[0x48];
};

// src: GUESS (confidence: low) [0x008973f0]
struct UnkBlockOwner_008973f0
{
    char m_unk000[0x128];
    UnkBlock120_008973f0* m_block;  // 0x128
};
