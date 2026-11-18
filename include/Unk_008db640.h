#pragma once

// Placeholder: an object that forwards a value to the int it points at (0x3c)
// while its flag at 0x34 and the global at 0x05f54f34 are set. Rename once the
// type is known.

// src: GUESS (confidence: low) [0x05f54f34]
extern int g_unk_05f54f34;

// src: GUESS (confidence: low) [0x008db640]
class Unk_008db640
{
public:
    // src: GUESS (confidence: low) [0x008db640]
    void SetTarget(int value);

    char m_unk00[0x34];
    bool m_active;      // 0x34
    char m_unk35[7];
    int* m_target;      // 0x3c
};
