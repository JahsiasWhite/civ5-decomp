#pragma once

// Placeholder: an object with two tables of 12-byte entries (0x54 and 0x58),
// each with a highest valid index (0x04 and 0x0c). Rename once the type is known.

// src: GUESS (confidence: low) [0x00920300]
struct UnkEntry0C_00920300
{
    int m_unk00;
    int m_value;    // 0x04
    int m_unk08;
};

// src: GUESS (confidence: low) [0x00920300]
class Unk_00920300
{
public:
    // src: GUESS (confidence: low) [0x00920300]
    int GetFirstValue(int index);
    // src: GUESS (confidence: low) [0x00920320]
    int GetSecondValue(int index);

    int m_unk00;
    int m_firstLast;                    // 0x04
    int m_unk08;
    int m_secondLast;                   // 0x0c
    char m_unk10[0x44];
    UnkEntry0C_00920300* m_first;       // 0x54
    UnkEntry0C_00920300* m_second;      // 0x58
};
