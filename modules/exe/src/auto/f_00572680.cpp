// Reverses [first, last) of 4-byte values in place (the bidirectional-
// iterator form: it stops when the two ends meet).

#include <algorithm>

// src: GUESS (confidence: low) [0x005fef70]
void __stdcall ReverseInts_005fef70(int* first, int* last)
{
    for (; first != last && first != --last; ++first)
        std::iter_swap(first, last);
}
