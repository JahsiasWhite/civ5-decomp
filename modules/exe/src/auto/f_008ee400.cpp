// Copies [first, last) of 0x48-byte records backwards so that it ends at
// destEnd; returns the start of the copy.

// src: GUESS (confidence: low)
struct Record_008ee400
{
    int m_data[0x12];
};

// src: GUESS (confidence: low) [0x008ee400]
Record_008ee400* CopyRecordsBackward_008ee400(const Record_008ee400* first, const Record_008ee400* last, Record_008ee400* destEnd)
{
    while (first != last)
        *--destEnd = *--last;
    return destEnd;
}
