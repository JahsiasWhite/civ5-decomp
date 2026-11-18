#pragma once

// Placeholder: an object with a type code at 0x00 and 16-bit values at 0x6e/0x70.
// Rename once the owning type is known.

// src: GUESS (confidence: low) [0x008ec800]
class Unk_008ec800
{
public:
    // src: GUESS (confidence: low) [0x008ec800]
    bool HasValue();
    // src: GUESS (confidence: low) [0x008ec820]
    bool HasSecondValue();

    int m_type;                 // 0x00
    char m_unk04[0x6a];
    unsigned short m_value;     // 0x6e
    unsigned short m_secondValue;   // 0x70
};
