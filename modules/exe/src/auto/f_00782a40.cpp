// Copies [first, last) of 0x48-byte records to dest; returns the end.

// src: GUESS (confidence: low)
struct Record_006e3ab0
{
    int m_data[0x12];
};

// src: GUESS (confidence: low) [0x006e3ab0]
Record_006e3ab0* CopyRecords_006e3ab0(const Record_006e3ab0* first, const Record_006e3ab0* last, Record_006e3ab0* dest)
{
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return dest;
}
