// Copy-constructs count copies of a named value into raw storage.

#include <new>
#include <string.h>

// src: GUESS (confidence: low)
struct NamedValue_008ed910
{
    NamedValue_008ed910(const NamedValue_008ed910& other)
    {
        m_value = other.m_value;
        strcpy(m_name, other.m_name);
    }

    // src: GUESS (confidence: low)
    char m_name[0x40];
    // src: GUESS (confidence: low)
    int m_value;
};

// src: GUESS (confidence: low) [0x008ed910]
void FillNamedValues_008ed910(NamedValue_008ed910* dest, unsigned int count, const NamedValue_008ed910& value)
{
    for (; count > 0; --count, ++dest)
    {
        new (dest) NamedValue_008ed910(value);
    }
}
