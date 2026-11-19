// Copies [first, last) of ints into raw storage at dest; returns the end.
// This is std::uninitialized_copy for ints, which uses memmove_s.

#include <memory>

// src: GUESS (confidence: low) [0x008e8dc0]
int* __stdcall UninitializedCopyInts_008e8dc0(int* first, int* last, int* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
