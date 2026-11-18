// Copies [first, last) of 0x40-byte records backwards so that it ends at
// destEnd; returns the start of the copy.

// src: GUESS (confidence: low)
struct Record_00751e50
{
    int m_data[16];
};

// src: GUESS (confidence: low) [0x00751e50]
Record_00751e50* CopyRecordsBackward_00751e50(const Record_00751e50* first, const Record_00751e50* last, Record_00751e50* destEnd)
{
    while (first != last)
        *--destEnd = *--last;
    return destEnd;
}
