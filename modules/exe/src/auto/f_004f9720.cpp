// c5d-cflags: -/arch:SSE2
// Fills raw storage with `count` copies of a 16-byte record.

#include <new>

// src: GUESS (confidence: low)
struct Record_004f9720
{
    int m_data[4];
};

// src: GUESS (confidence: low) [0x004f9720]
void UninitializedFill_004f9720(Record_004f9720* dest, unsigned int count, const Record_004f9720& value)
{
    for (; 0 < count; --count, ++dest)
        new (dest) Record_004f9720(value);
}
