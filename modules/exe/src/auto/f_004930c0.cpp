#include <string.h>

// src: GUESS (confidence: low) [0x00512da0]
class UnkName48_00512da0
{
public:
    // Copies a name in, cut to fit; null clears it.
    // src: GUESS (confidence: low) [0x00512da0]
    void Set(const char* szName);

    // src: GUESS (confidence: low)
    char m_name[0x30];
};

void UnkName48_00512da0::Set(const char* szName)
{
    if (szName)
        strncpy_s(m_name, sizeof(m_name), szName, _TRUNCATE);
    else
        m_name[0] = '\0';
}
