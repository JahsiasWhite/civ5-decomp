#pragma once
// c5d-vtable: 0x00b898ac

// Placeholder: a class with four base subobjects, each with its own vtable
// pointer. 0x00838b10 resets all four. Set through declared arrays (as in
// 0x0083ee60) until the class hierarchy is known.

// src: GUESS (confidence: medium) [0x00b89890]
extern const void* const kVtable_00b89890[];
// src: GUESS (confidence: medium) [0x00b898a0]
extern const void* const kVtable_00b898a0[];
// src: GUESS (confidence: medium) [0x00b898ac]
extern const void* const kVtable_00b898ac[];
// src: GUESS (confidence: medium) [0x00b898c4]
extern const void* const kVtable_00b898c4[];

// src: GUESS (confidence: low) [0x00838b10]
class Unk_00b898d8
{
public:
    // src: GUESS (confidence: medium) [0x00838b10]
    void ResetVtables();

    const void* const* m_vtable0;
    const void* const* m_vtable4;
    const void* const* m_vtable8;
    const void* const* m_vtable0c;
};
