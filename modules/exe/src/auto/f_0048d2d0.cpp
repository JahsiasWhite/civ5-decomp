// src: GUESS (confidence: medium) [0x0083f850]
#include "Unk_00b89dcc.h"

// src: GUESS (confidence: low) [0x00b89dcc]
extern const void* const kVtable_00b89dcc[];
// src: GUESS (confidence: low) [0x00b89df4]
extern const void* const kVtable_00b89df4[];
// src: GUESS (confidence: low) [0x00b89e00]
extern const void* const kVtable_00b89e00[];

Unk_00b89dcc::Unk_00b89dcc() {
    *(const void**)this = kVtable_00b89dcc;
    m_vf4 = kVtable_00b89df4;
    m_vf8 = kVtable_00b89e00;
    m_i0c = 0;
    m_f10 = 0.0f;
    m_i14 = 0;
}
