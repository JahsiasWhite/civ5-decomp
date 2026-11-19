// c5d-cflags: -/arch:SSE2
// Copies [first, last) of 0x1c-byte records backwards so that it ends at
// destEnd; returns the start of the copy.

// src: GUESS (confidence: low)
struct Record_006f25b0
{
    int m_data[7];
};

// src: GUESS (confidence: low) [0x006f25b0]
Record_006f25b0* CopyRecordsBackward_006f25b0(const Record_006f25b0* first, const Record_006f25b0* last, Record_006f25b0* destEnd)
{
    while (first != last)
        *--destEnd = *--last;
    return destEnd;
}
