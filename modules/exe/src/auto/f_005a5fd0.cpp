// Fills [first, last) of string-pair records with a copy of `value`.

#include <string>

// src: GUESS (confidence: low)
struct StringPair_005a5fd0
{
    // src: GUESS (confidence: low)
    std::string m_first;
    // src: GUESS (confidence: low)
    std::string m_second;
};

// src: GUESS (confidence: low) [0x005a5fd0]
void FillStringPairs_005a5fd0(StringPair_005a5fd0* first, StringPair_005a5fd0* last, const StringPair_005a5fd0& value)
{
    for (; first != last; ++first)
        *first = value;
}
