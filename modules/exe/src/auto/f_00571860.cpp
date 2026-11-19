// c5d-cflags: -/arch:SSE2
// Copies [first, last) of 0x1c-byte records to dest; returns the end.

// src: GUESS (confidence: low)
struct Record_0049b3e0
{
    int m_data[7];
};

// src: GUESS (confidence: low) [0x0049b3e0]
Record_0049b3e0* CopyRecords_0049b3e0(const Record_0049b3e0* first, const Record_0049b3e0* last, Record_0049b3e0* dest)
{
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return dest;
}
