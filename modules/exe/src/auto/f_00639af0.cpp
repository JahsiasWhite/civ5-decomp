// c5d-cflags: -/arch:SSE2
// Copies [first, last) of 16-byte records backwards so that it ends at
// destEnd; returns the start of the copy.

#include <algorithm>

// src: GUESS (confidence: low)
struct Record_004681d0
{
    int m_data[4];
};

// src: GUESS (confidence: low) [0x004681d0]
Record_004681d0* CopyRecordsBackward_004681d0(Record_004681d0* first, Record_004681d0* last, Record_004681d0* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
