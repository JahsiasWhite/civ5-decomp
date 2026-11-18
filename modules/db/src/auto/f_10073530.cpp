// c5d-cflags: -/EHsc
#include <string>

// src: GUESS 0x10073530 (confidence: medium)
std::string* SwapBackward_10073530(std::string* first, std::string* last, std::string* dest) {
    std::string* p = dest;
    while (first != last) {
        --last;
        --p;
        p->swap(*last);
    }
    return p;
}
