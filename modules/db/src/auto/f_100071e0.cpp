// c5d-cflags: -/EHsc +/Ob0
#include <string>

// src: GUESS 0x100071e0 (confidence: high)
unsigned int HashStringFNV1a_100071e0(const std::string& s) {
    const char* first = s.c_str();
    const char* last = first + s.size();
    const char* p = first;
    unsigned int h = 0x811c9dc5u;
    for (; p != last; ++p) {
        h = (h * 0x01000193u) ^ *p;
    }
    return h;
}
