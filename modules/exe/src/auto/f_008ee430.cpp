// Copies [first, last) of 8-byte pairs backwards so that it ends at destEnd;
// returns the start of the copy. This is std::copy_backward for this type.

#include <algorithm>

// src: GUESS (confidence: low)
struct Pair_008ee430
{
    int first;
    int second;
};

// src: GUESS (confidence: low) [0x008ee430]
Pair_008ee430* CopyPairsBackward(Pair_008ee430* first, Pair_008ee430* last, Pair_008ee430* destEnd)
{
    return std::copy_backward(first, last, destEnd);
}
