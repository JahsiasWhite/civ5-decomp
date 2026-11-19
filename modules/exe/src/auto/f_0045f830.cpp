// Finds a substring at or after `start`; returns its offset or -1. The
// string's length is stored 8 bytes before its data.

#include <string.h>

// src: GUESS (confidence: low)
class CharString_008151e0
{
public:
    // src: GUESS (confidence: low) [0x008151e0]
    int Find(const char* text, int start) const;

    // src: GUESS (confidence: low)
    char* m_data;
};

int CharString_008151e0::Find(const char* text, int start) const
{
    if (start < ((int*)m_data)[-2] && start >= 0)
    {
        const char* found = strstr(m_data + start, text);
        if (found)
            return found - m_data;
    }
    return -1;
}
