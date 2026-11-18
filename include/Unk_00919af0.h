#pragma once

// Placeholder: an object with a float pair at 0xf4/0xf8. Rename once the
// owning type is known.

// src: GUESS (confidence: low) [0x00919af0]
class Unk_00919af0
{
public:
    // src: GUESS (confidence: low) [0x00919af0]
    bool GetPair(float* first, float* second);

    char m_unk000[0xf4];
    float m_first;      // 0xf4
    float m_second;     // 0xf8
};
