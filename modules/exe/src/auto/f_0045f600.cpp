// Replaces every occurrence of one character with another; returns how
// many were replaced. The string's length is stored 8 bytes before its data.

// src: GUESS (confidence: low)
class CharString_00814fb0
{
public:
    // src: GUESS (confidence: low) [0x00814fb0]
    int Replace(char from, char to);

    // src: GUESS (confidence: low)
    char* m_data;
};

int CharString_00814fb0::Replace(char from, char to)
{
    int count = 0;
    if (from != to)
    {
        char* p = m_data;
        char* end = p + ((int*)p)[-2];
        for (; p < end; ++p)
        {
            if (*p == from)
            {
                *p = to;
                ++count;
            }
        }
    }
    return count;
}
