#pragma once

// Placeholder: a record whose value at 0x0c applies while the field at 0x08 is
// set, else the one at 0x14. Rename once the owning type is known.

// src: GUESS (confidence: low) [0x009bbd20]
struct UnkChoiceRecord
{
    int m_unk00[2];
    int m_useFirst;     // 0x08
    int m_first;        // 0x0c
    int m_unk10;
    int m_second;       // 0x14
};

// src: GUESS (confidence: low) [0x009bbd20]
struct UnkChoiceOwner
{
    int m_unk00[4];
    UnkChoiceRecord* m_record;  // 0x10
};

// src: GUESS (confidence: low) [0x009bbd20]
int GetChoiceValue_009bbd20(UnkChoiceOwner* owner);
