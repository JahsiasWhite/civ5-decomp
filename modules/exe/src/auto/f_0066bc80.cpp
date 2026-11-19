// Copy-constructs [first, last) of 8-byte pairs into raw storage at dest;
// returns the end of the copy.

#include <memory>

// src: GUESS (confidence: low)
struct Pair_0091ae80
{
    int m_a;
    int m_b;
};

// src: GUESS (confidence: low) [0x0091ae80]
Pair_0091ae80* __stdcall UninitializedCopy_0091ae80(const Pair_0091ae80* first, const Pair_0091ae80* last, Pair_0091ae80* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
