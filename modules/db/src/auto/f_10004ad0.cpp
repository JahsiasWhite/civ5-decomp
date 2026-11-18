#include <new>

// src: GUESS (confidence: low)
struct Elem_10004ad0 {
    // src: GUESS (confidence: low)
    Elem_10004ad0(const Elem_10004ad0& o) : value(o.value) {}
    // src: GUESS (confidence: low)
    int value;
};

// src: GUESS 0x10004ad0 (confidence: medium)
Elem_10004ad0* __stdcall UninitFillNDwords_10004ad0(Elem_10004ad0* dest, unsigned int count, const Elem_10004ad0& val) {
    unsigned int n = count;
    Elem_10004ad0* p = dest;
    for (; n > 0; --n, ++p) {
        new ((void*)p) Elem_10004ad0(val);
    }
    return dest + count;
}
