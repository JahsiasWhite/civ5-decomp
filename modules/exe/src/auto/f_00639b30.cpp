// c5d-cflags: -/arch:SSE2
// Fills raw storage with `count` copies of a (3 floats, int) record.

#include <new>

// src: GUESS (confidence: low)
struct Record_005fd570
{
    Record_005fd570(const Record_005fd570& other)
        : x(other.x)
        , y(other.y)
        , z(other.z)
        , m_flags(other.m_flags)
    {
    }

    float x;
    float y;
    float z;
    int m_flags;
};

// src: GUESS (confidence: low) [0x005fd570]
void UninitializedFill_005fd570(Record_005fd570* dest, unsigned int count, const Record_005fd570& value)
{
    for (; 0 < count; --count, ++dest)
        new (dest) Record_005fd570(value);
}
