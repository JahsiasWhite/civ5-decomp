// Copies a range of (id, name) records backwards, as std::copy_backward does.

#include <string>

// src: GUESS (confidence: low)
struct NamedId_00683370
{
    // src: GUESS (confidence: low)
    int m_id;
    // src: GUESS (confidence: low)
    std::string m_name;
};

// src: GUESS (confidence: low) [0x00683370]
NamedId_00683370* CopyBackward_00683370(NamedId_00683370* first, NamedId_00683370* last, NamedId_00683370* dest)
{
    while (first != last)
    {
        *--dest = *--last;
    }
    return dest;
}
