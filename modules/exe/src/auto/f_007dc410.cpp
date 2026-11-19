// Assigns a C string to a std::string member at offset 0x104.

#include <string>

// src: GUESS (confidence: low)
class StringHolder_00714580
{
public:
    // src: GUESS (confidence: low) [0x00714580]
    void SetString104(const char* text);

    char pad[0x104];
    // src: GUESS (confidence: low)
    std::string m_string104;
};

void StringHolder_00714580::SetString104(const char* text)
{
    m_string104 = text;
}
