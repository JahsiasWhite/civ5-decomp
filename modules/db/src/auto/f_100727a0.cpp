// c5d-cflags: -/EHsc
#include <algorithm>
#include <list>
#include <string>

// src: LIB [0x100727a0]
std::list<std::string>::iterator FindStr_100727a0(
    std::list<std::string>::iterator first,
    std::list<std::string>::iterator last,
    const std::string& val) {
    return std::find(first, last, val);
}
