// Assigns a C string to a std::string member at offset 0x20.

#include <string>

// src: GUESS (confidence: low)
class StringHolder_00525ac0
{
public:
    // src: GUESS (confidence: low) [0x00525ac0]
    void SetString20(const char* text);

    char pad[0x20];
    // src: GUESS (confidence: low)
    std::string m_string20;
};

void StringHolder_00525ac0::SetString20(const char* text)
{
    m_string20 = text;
}
