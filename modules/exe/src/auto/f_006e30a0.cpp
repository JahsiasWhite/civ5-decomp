// c5d-cflags: -/arch:SSE2
#include <new>

// src: GUESS (confidence: low)
struct UnkStruct24_006e30a0
{
    int data[6];
};

// src: LIB [0x006e30a0]
UnkStruct24_006e30a0* CopyRange24_006e30a0(const UnkStruct24_006e30a0* first, const UnkStruct24_006e30a0* last, UnkStruct24_006e30a0* dst)
{
    for (; first != last; ++first, ++dst)
        new ((void*)dst) UnkStruct24_006e30a0(*first);
    return dst;
}
