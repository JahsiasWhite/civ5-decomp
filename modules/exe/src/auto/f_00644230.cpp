// c5d-cflags: -/arch:SSE2
// Copies [first, last) of 16-byte records to dest; returns the end.

// src: GUESS (confidence: low)
struct Record_00705870
{
    int m_data[4];
};

// src: GUESS (confidence: low) [0x00705870]
Record_00705870* CopyRecords_00705870(const Record_00705870* first, const Record_00705870* last, Record_00705870* dest)
{
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return dest;
}
