#pragma once

// Placeholder: owns a byte buffer (pointer at 0xa0, size at 0xa4). Rename once
// the owning type is known.

// src: GUESS (confidence: low) [0x00468210]
class Unk_00468210
{
public:
    // src: GUESS (confidence: medium) [0x00468210]
    void Fill(unsigned char value);

    char m_unk00[0xa0];
    unsigned char* m_buffer;    // 0xa0
    unsigned int m_size;        // 0xa4
};
