// Copy-constructs [first, last) of 4-byte values into raw storage at dest;
// returns the end of the copy.

#include <memory>

// src: GUESS (confidence: low)
struct Value_0043ba10
{
    int m_value;
};

// src: GUESS (confidence: low) [0x0043ba10]
Value_0043ba10* __stdcall UninitializedCopy_0043ba10(const Value_0043ba10* first, const Value_0043ba10* last, Value_0043ba10* dest)
{
    return std::uninitialized_copy(first, last, dest);
}
