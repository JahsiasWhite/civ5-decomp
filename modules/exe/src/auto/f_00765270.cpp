// Copies [first, last) of 0x5c-byte records backwards so that it ends at
// destEnd; returns the start of the copy.

// src: GUESS (confidence: low)
struct Record_00765270
{
    int m_data[23];
};

// src: GUESS (confidence: low) [0x00765270]
Record_00765270* CopyRecordsBackward_00765270(const Record_00765270* first, const Record_00765270* last, Record_00765270* destEnd)
{
    while (first != last)
        *--destEnd = *--last;
    return destEnd;
}
