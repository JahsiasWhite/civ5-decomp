// Copies [first, last) of 0x40-byte records to dest; returns the end.

// src: GUESS (confidence: low)
struct Record_0074d770
{
    int m_data[0x10];
};

// src: GUESS (confidence: low) [0x0074d770]
Record_0074d770* CopyRecords_0074d770(const Record_0074d770* first, const Record_0074d770* last, Record_0074d770* dest)
{
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return dest;
}
