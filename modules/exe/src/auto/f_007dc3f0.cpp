// Assigns a C string to a std::string member at offset 0x58.

#include <string>

// src: GUESS (confidence: low)
class StringHolder_0064d840
{
public:
    // src: GUESS (confidence: low) [0x0064d840]
    void SetString58(const char* text);

    char pad[0x58];
    // src: GUESS (confidence: low)
    std::string m_string58;
};

void StringHolder_0064d840::SetString58(const char* text)
{
    m_string58 = text;
}
