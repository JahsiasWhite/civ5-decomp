// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// Copy-constructs [first, last) of 4-byte values into raw storage at dest;
// returns the end of the copy.

#include <memory>

// src: GUESS (confidence: low)
struct Value_00721690
{
    int m_value;
};

// src: GUESS (confidence: low) [0x00721690]
Value_00721690* __stdcall UninitializedCopy_00721690(const Value_00721690* first, const Value_00721690* last, Value_00721690* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
