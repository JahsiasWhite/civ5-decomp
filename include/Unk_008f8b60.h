#pragma once

// Placeholder: an owner of 64-byte records at 0x0c, written by index.
// Rename once the owning type is known.

// src: GUESS (confidence: low) [0x008f8b60]
struct UnkRecord40_008f8b60
{
    int m_data[16];
};

// src: GUESS (confidence: low) [0x008f8b60]
class UnkRecordTable_008f8b60
{
public:
    // src: GUESS (confidence: low) [0x008f8b60]
    void SetRecord(int index, const UnkRecord40_008f8b60* record);

    int m_unk00[3];
    UnkRecord40_008f8b60* m_records;    // 0x0c
};
