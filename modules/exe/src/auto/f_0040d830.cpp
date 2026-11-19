// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// Writes `count` copies of an int starting at dest; returns the end.

#include <algorithm>

// src: GUESS (confidence: low) [0x00551550]
int* __stdcall FillInts_00551550(int* dest, unsigned int count, const int* value)
{
    std::fill_n(dest, count, *value);
    return dest + count;
}
