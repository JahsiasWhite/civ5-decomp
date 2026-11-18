// c5d-cflags: -/EHsc
#include <new>
#include <string>

// src: GUESS 0x10073900 (confidence: high)
std::string* __stdcall UninitFillNString_10073900(std::string* dest, unsigned int count, const std::string& val) {
    std::string* p = dest;
    for (unsigned int n = count; n > 0; --n, ++p) {
        new ((void*)p) std::string(val);
    }
    return dest + count;
}
