#include <string>
#include <memory>

// src: LIB [0x007b1c80]
void __stdcall DestroyStringRange_007b1c80(std::string* first, std::string* last)
{
    for (; first != last; ++first)
        first->~basic_string();
}
