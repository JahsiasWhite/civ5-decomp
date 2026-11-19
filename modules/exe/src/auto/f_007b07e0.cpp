// c5d-cflags: -/EHsc   (no unwind frame around the copies)
// Copy-constructs [first, last) of strings into raw storage at dest; returns
// the end of the copy.

#include <string>
#include <new>

// src: GUESS (confidence: low) [0x0053bb50]
std::string* UninitializedCopyStrings_0053bb50(const std::string* first, const std::string* last, std::string* dest)
{
    for (; first != last; ++first, ++dest)
        new (dest) std::string(*first);
    return dest;
}
