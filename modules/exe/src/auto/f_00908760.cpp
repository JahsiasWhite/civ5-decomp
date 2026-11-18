// Copy-constructs [first, last) of 72-byte records into raw storage at
// dest; returns the end of the copy.

#include <memory>

// src: GUESS (confidence: low)
struct Record_00908760
{
    int m_data[18];
};

// src: GUESS (confidence: low) [0x00908760]
Record_00908760* __stdcall UninitializedCopy_00908760(const Record_00908760* first, const Record_00908760* last, Record_00908760* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
