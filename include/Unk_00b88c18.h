#pragma once
// c5d-vtable: 0x00b88c18

// Layout seen from its constructor (0x0082b440). The vtable pointer is set
// through a declared array, as in 0x0082b490, until the virtuals are known.

// src: GUESS (confidence: medium) [0x00b88c18]
extern void* const g_vtable_00b88c18[];

// src: GUESS (confidence: medium) [0x00b88c18]
class Unk_00b88c18
{
public:
    // src: GUESS (confidence: medium) [0x0082b440]
    Unk_00b88c18();

    const void* m_vftable;
    bool m_enabled;     // 0x04
    int m_count;        // 0x08
    int m_unk0c;
    int m_unk10;
};
