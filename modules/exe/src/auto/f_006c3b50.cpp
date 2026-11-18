// Writes `count` copies of an int starting at dest; returns the end.

#include <algorithm>

// src: GUESS (confidence: low) [0x006c3b50]
int* __stdcall FillInts_006c3b50(int* dest, unsigned int count, const int* value)
{
    std::fill_n(dest, count, *value);
    return dest + count;
}
