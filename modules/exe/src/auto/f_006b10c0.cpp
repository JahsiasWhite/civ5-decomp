// Assigns a C string to a std::string member at offset 0x3c.

#include <string>

// src: GUESS (confidence: low)
class StringHolder_006b10c0
{
public:
    // src: GUESS (confidence: low) [0x006b10c0]
    void SetString3c(const char* text);

    char pad[0x3c];
    // src: GUESS (confidence: low)
    std::string m_string3c;
};

void StringHolder_006b10c0::SetString3c(const char* text)
{
    m_string3c = text;
}
