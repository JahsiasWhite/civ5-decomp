// Copies [first, last) of ints to dest; returns the end. This is std::copy
// for ints.

#include <algorithm>

// src: GUESS (confidence: low) [0x006d1b30]
int* CopyInts_006d1b30(int* first, int* last, int* dest)
{
    return std::copy(first, last, dest);
}
