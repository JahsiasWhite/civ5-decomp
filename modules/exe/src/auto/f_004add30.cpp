#include <string>

// src: GUESS (confidence: low)
struct Elem32_004add30
{
    int m_f00;          // +0x00
    std::string m_str;  // +0x04
};

// src: LIB [0x004add30]
void __stdcall DestroyRange_004add30(Elem32_004add30* first, Elem32_004add30* last)
{
    for (; first != last; ++first)
        first->m_str.~basic_string();
}
