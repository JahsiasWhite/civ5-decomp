#pragma once

// Placeholder: an object with six fields at 0x1c..0x30 that are cleared
// together. Rename once the owning type is known.

// src: GUESS (confidence: low) [0x008e7ff0]
class Unk_008e7ff0
{
public:
    // src: GUESS (confidence: low) [0x008e7ff0]
    void* Detach();

    char m_unk00[0x1c];
    void* m_object;     // 0x1c
    int m_unk20[5];
};
