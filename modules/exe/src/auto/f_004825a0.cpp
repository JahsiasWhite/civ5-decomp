// Copies [first, last) of ints backwards so that it ends at destEnd; returns
// the start of the copy. This is std::copy_backward for ints.

#include <algorithm>

// src: GUESS (confidence: low) [0x004c0e40]
int* CopyIntsBackward_004c0e40(int* first, int* last, int* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
