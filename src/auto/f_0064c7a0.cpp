// c5d-cflags: +/Oy-
// Fills the range [first, last) of std::string with copies of value (std::fill).

#include <string>

void FillStringRange(std::string* first, std::string* last, const std::string& value)
{
    for (; first != last; ++first)
        *first = value;
}
