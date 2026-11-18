#pragma once

// Placeholder: the object behind the global pointer at 0x05f54f38; only the
// double at 0x28 is known. Rename once the owning type is known.

// src: GUESS (confidence: low) [0x05f54f38]
struct Unk_05f54f38
{
    char m_unk00[0x28];
    double m_value;     // 0x28
};

// src: GUESS (confidence: low) [0x05f54f38]
extern Unk_05f54f38* g_unk_05f54f38;
