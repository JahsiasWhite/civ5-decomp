// Fills [first, last) of (id, name) records with a copy of `value`.

#include <string>

// src: GUESS (confidence: low)
struct NamedId_00559e80
{
    // src: GUESS (confidence: low)
    int m_id;
    // src: GUESS (confidence: low)
    std::string m_name;
};

// src: GUESS (confidence: low) [0x00559e80]
void FillNamedIds_00559e80(NamedId_00559e80* first, NamedId_00559e80* last, const NamedId_00559e80& value)
{
    for (; first != last; ++first)
        *first = value;
}
