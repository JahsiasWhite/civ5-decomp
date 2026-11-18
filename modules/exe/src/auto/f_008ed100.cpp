// Copies a named record: the 64-byte name and the two values after it.

#include <string.h>

// src: GUESS (confidence: low)
struct NamedRecord_008ed100
{
    // src: GUESS (confidence: low) [0x008ed100]
    NamedRecord_008ed100& operator=(const NamedRecord_008ed100& other);

    // src: GUESS (confidence: low)
    char m_name[0x40];
    // src: GUESS (confidence: low)
    int m_a;
    // src: GUESS (confidence: low)
    int m_b;
};

NamedRecord_008ed100& NamedRecord_008ed100::operator=(const NamedRecord_008ed100& other)
{
    m_a = other.m_a;
    strcpy(m_name, other.m_name);
    m_b = other.m_b;
    return *this;
}
