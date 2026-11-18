#pragma once

// Placeholder: keeps a float and its previous value (0x674 = previous,
// 0x678 = current). Rename once the owning type is known.

// src: GUESS (confidence: low) [0x004572c0]
class UnkTrackedFloat_004572c0
{
public:
    // src: GUESS (confidence: low) [0x004572c0]
    void SetValue(float value);

    char m_unk000[0x674];
    float m_previous;   // 0x674
    float m_current;    // 0x678
};
