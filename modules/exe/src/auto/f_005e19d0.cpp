// Writes `count` copies of a character starting at dest; returns the end.

#include <algorithm>

// src: GUESS (confidence: low) [0x0059e3f0]
char* __stdcall FillChars_0059e3f0(char* dest, unsigned int count, const char* value)
{
    std::fill_n(dest, count, *value);
    return dest + count;
}
