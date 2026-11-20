#include <string>

// src: GUESS (confidence: low) [0x00493040]
struct StringWrap_00493040 : public std::string
{
    // src: GUESS (confidence: high) [0x00493040]
    StringWrap_00493040& Set_00493040(const char* s);
};

// src: GUESS (confidence: high) [0x00493040]
StringWrap_00493040& StringWrap_00493040::Set_00493040(const char* s)
{
    if (s)
        assign(s);
    else
        clear();
    return *this;
}
