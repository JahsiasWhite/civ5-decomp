// c5d-cflags: -/EHsc
#include <string>

// src: GUESS (confidence: low) [0x00665e30]
class Class_00665e30
{
public:
    unsigned char m_pad[0x254];
    std::string m_str;

    std::string GetStr();
};

std::string Class_00665e30::GetStr()
{
    return m_str;
}
