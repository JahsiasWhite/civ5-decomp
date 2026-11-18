// c5d-cflags: -/arch:SSE2
// Copy-constructs [first, last) of 12-byte records into raw storage at
// dest.

#include <memory>

// src: GUESS (confidence: low)
struct Record_005945f0
{
    int m_data[3];
};

// src: GUESS (confidence: low) [0x005945f0]
void UninitializedCopy_005945f0(const Record_005945f0* first, const Record_005945f0* last, Record_005945f0* dest)
{
    std::uninitialized_copy(first, last, dest);
}
