// Fills raw storage with `count` copies of an 8-byte pair; returns the end.

#include <memory>

// src: GUESS (confidence: low)
struct Pair_008eed70
{
    int m_a;
    int m_b;
};

// src: GUESS (confidence: low) [0x008eed70]
Pair_008eed70* __stdcall UninitializedFill_008eed70(Pair_008eed70* dest, unsigned int count, const Pair_008eed70* value)
{
    std::uninitialized_fill_n(dest, count, *value);
    return dest + count;
}
