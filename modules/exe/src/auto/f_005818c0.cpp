// c5d-cflags: -/arch:SSE2
// Copies [first, last) of 12-byte records backwards so that it ends at
// destEnd; returns the start of the copy.

#include <algorithm>

// src: GUESS (confidence: low)
struct Record_005818c0
{
    int m_data[3];
};

// src: GUESS (confidence: low) [0x005818c0]
Record_005818c0* CopyRecordsBackward_005818c0(Record_005818c0* first, Record_005818c0* last, Record_005818c0* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
