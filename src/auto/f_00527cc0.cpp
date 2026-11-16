// Assigns a C string to a std::string member at offset 0xe8.

#include <string>

// src: GUESS (confidence: low)
class StringHolder_00527cc0
{
public:
    // src: GUESS (confidence: low) [0x00527cc0]
    void SetStringe8(const char* text);

    char pad[0xe8];
    // src: GUESS (confidence: low)
    std::string m_stringe8;
};

void StringHolder_00527cc0::SetStringe8(const char* text)
{
    m_stringe8 = text;
}
