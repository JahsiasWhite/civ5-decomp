// c5d-cflags: +/Oy-   (this area of the exe keeps frame pointers)
// True when both names have the same hash and match case-insensitively.

#include <string.h>

// src: GUESS (confidence: low)
struct HashedName_007c40b0
{
    // src: GUESS (confidence: low) [0x007c40b0]
    bool Equals(const HashedName_007c40b0& other) const;

    // src: GUESS (confidence: low)
    char m_name[0x40];
    // src: GUESS (confidence: low)
    int m_hash;
};

bool HashedName_007c40b0::Equals(const HashedName_007c40b0& other) const
{
    return m_hash == other.m_hash && _strnicmp(m_name, other.m_name, 0x40) == 0;
}
