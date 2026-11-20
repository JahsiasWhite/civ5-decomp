// c5d-cflags: +/Oy-
#include <string>

// src: LIB [0x0040d910]
void __stdcall DestroyStrings_0040d910(std::string* first, std::string* last)
{
    for (; first != last; ++first)
        first->~basic_string();
}
