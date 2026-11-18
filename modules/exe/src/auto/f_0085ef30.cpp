// Fills raw storage with `count` copies of an int; returns the end.

#include <memory>

// src: GUESS (confidence: low)
struct Value_0085ef30
{
    int m_value;
};

// src: GUESS (confidence: low) [0x0085ef30]
Value_0085ef30* __stdcall UninitializedFill_0085ef30(Value_0085ef30* dest, unsigned int count, const Value_0085ef30* value)
{
    std::uninitialized_fill_n(dest, count, *value);
    return dest + count;
}
