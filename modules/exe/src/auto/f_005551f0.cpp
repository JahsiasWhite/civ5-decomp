// Fills raw storage with `count` copies of an int; returns the end.

#include <memory>

// src: GUESS (confidence: low)
struct Value_005551f0
{
    int m_value;
};

// src: GUESS (confidence: low) [0x005551f0]
Value_005551f0* __stdcall UninitializedFill_005551f0(Value_005551f0* dest, unsigned int count, const Value_005551f0* value)
{
    std::uninitialized_fill_n(dest, count, *value);
    return dest + count;
}
