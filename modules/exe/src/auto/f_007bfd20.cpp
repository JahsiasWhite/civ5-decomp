// c5d-cflags: -/EHsc
#include <string>

// src: GUESS (confidence: low) [0x007bfd20]
struct PairStr_007bfd20
{
    std::string m_a;  // +0x00
    std::string m_b;  // +0x1c

    // src: GUESS (confidence: high) [0x007bfd20]
    PairStr_007bfd20(const PairStr_007bfd20& other);
};

// src: GUESS (confidence: high) [0x007bfd20]
PairStr_007bfd20::PairStr_007bfd20(const PairStr_007bfd20& other)
    : m_a(other.m_a)
    , m_b(other.m_b)
{
}
