// Copies [first, last) of ints backwards so that it ends at destEnd; returns
// the start of the copy. This is std::copy_backward for ints.

#include <algorithm>

// src: GUESS (confidence: low) [0x008f3dc0]
int* CopyIntsBackward_008f3dc0(int* first, int* last, int* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
