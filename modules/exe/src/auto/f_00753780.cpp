// Copy-constructs [first, last) of 64-byte records into raw storage at
// dest; returns the end of the copy.

#include <memory>

// src: GUESS (confidence: low)
struct Record_00753780
{
    int m_data[16];
};

// src: GUESS (confidence: low) [0x00753780]
Record_00753780* __stdcall UninitializedCopy_00753780(const Record_00753780* first, const Record_00753780* last, Record_00753780* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
