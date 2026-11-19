// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// Moves [first, last) of strings backwards (by swapping) so that it ends at
// destEnd; returns the start of the moved range.

#include <string>

// src: GUESS (confidence: low) [0x0063c7d0]
std::string* MoveStringsBackward_0063c7d0(std::string* first, std::string* last, std::string* destEnd)
{
    while (first != last)
        (--destEnd)->swap(*--last);
    return destEnd;
}
