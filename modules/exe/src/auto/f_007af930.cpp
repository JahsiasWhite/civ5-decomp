// c5d-cflags: -/Ob1 +/Ob0
#include <string>

// src: LIB [0x007af930]
void FillStrings_007af930(std::string* first, std::string* last, const std::string& val)
{
    for (; first != last; ++first)
        *first = val;
}
