// Copies a name into the object's 512-byte buffer (always terminated);
// a null name is ignored.

#include <string.h>

// src: GUESS (confidence: low)
class Named_006564e0
{
public:
    // src: GUESS (confidence: low) [0x006564e0]
    void SetName(const char* name);

    int m_00;
    // src: GUESS (confidence: low)
    char m_name[0x200];
};

void Named_006564e0::SetName(const char* name)
{
    if (name)
    {
        strncpy(m_name, name, sizeof(m_name));
        m_name[sizeof(m_name) - 1] = 0;
    }
}
