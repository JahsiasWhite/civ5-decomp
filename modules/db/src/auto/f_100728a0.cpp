// c5d-cflags: -/EHsc +/GS-
#include <new>
#include <string>

// src: GUESS 0x100728a0 (confidence: medium)
std::string* UninitSwapMoveStrings_100728a0(std::string* first, std::string* last, std::string* dest) {
    std::string empty;
    while (first != last) {
        new ((void*)dest) std::string(empty);
        dest->swap(*first);
        ++first;
        ++dest;
    }
    return dest;
}
