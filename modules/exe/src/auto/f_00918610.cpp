// Copies [first, last) of 12-byte records backwards so that it ends at
// destEnd; returns the start of the copy. This is std::copy_backward for
// this type.

#include <algorithm>

// src: GUESS (confidence: low)
struct Record_00918610
{
    int m_data[3];
};

// src: GUESS (confidence: low) [0x00918610]
Record_00918610* CopyRecordsBackward_00918610(Record_00918610* first, Record_00918610* last, Record_00918610* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
