// Copies [first, last) of ints to dest; returns the end. This is std::copy
// for ints.

#include <algorithm>

// src: GUESS (confidence: low) [0x004c1e30]
int* CopyInts_004c1e30(int* first, int* last, int* dest)
{
    return std::copy(first, last, dest);
}
