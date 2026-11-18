// Copies [first, last) of 0x44-byte records backwards so that it ends at
// destEnd; returns the start of the copy.

// src: GUESS (confidence: low)
struct Record_008ee460
{
    int m_data[17];
};

// src: GUESS (confidence: low) [0x008ee460]
Record_008ee460* CopyRecordsBackward_008ee460(const Record_008ee460* first, const Record_008ee460* last, Record_008ee460* destEnd)
{
    while (first != last)
        *--destEnd = *--last;
    return destEnd;
}
