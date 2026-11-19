// Copy-constructs [first, last) of 12-byte records into raw storage at
// dest; returns the end of the copy.

#include <memory>

// src: GUESS (confidence: low)
struct Record_00918e60
{
    int m_data[3];
};

// src: GUESS (confidence: low) [0x00918e60]
Record_00918e60* __stdcall UninitializedCopy_00918e60(const Record_00918e60* first, const Record_00918e60* last, Record_00918e60* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
