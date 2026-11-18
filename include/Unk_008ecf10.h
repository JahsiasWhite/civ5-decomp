#pragma once

// Placeholder: a counted array of 60-byte records (pointer at 0x08, count at
// 0x0c). Rename once the owning type is known.

// src: GUESS (confidence: low) [0x008ecf10]
struct UnkRecord3C_008ecf10
{
    int m_data[15];
};

// src: GUESS (confidence: low) [0x008ecf10]
class UnkRecordArray_008ecf10
{
public:
    // src: GUESS (confidence: medium) [0x008ecf10]
    UnkRecord3C_008ecf10* GetRecord(unsigned int index);

    int m_unk00[2];
    UnkRecord3C_008ecf10* m_records;    // 0x08
    unsigned int m_count;               // 0x0c
};
