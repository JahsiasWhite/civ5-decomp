// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// Copies [first, last) of ints backwards so that it ends at destEnd; returns
// the start of the copy. This is std::copy_backward for ints.

#include <algorithm>

// src: GUESS (confidence: low) [0x0073b770]
int* CopyIntsBackward_0073b770(int* first, int* last, int* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
