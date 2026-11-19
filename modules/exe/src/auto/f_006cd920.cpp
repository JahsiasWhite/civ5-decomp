// c5d-cflags: -/EHsc   (no unwind frame between the two string destructors)
// Destroys [first, last) of records that hold two strings.

#include <string>

// src: GUESS (confidence: low)
struct StringPair_004cbc50
{
    // src: GUESS (confidence: low)
    std::string m_first;
    // src: GUESS (confidence: low)
    std::string m_second;
};

// src: GUESS (confidence: low) [0x004cbc50]
void __stdcall DestroyStringPairs_004cbc50(StringPair_004cbc50* first, StringPair_004cbc50* last)
{
    for (; first != last; ++first)
        first->~StringPair_004cbc50();
}
