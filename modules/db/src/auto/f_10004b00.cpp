#include <new>

// src: GUESS (confidence: low)
struct Elem_10004b00 {
    // src: GUESS (confidence: low)
    Elem_10004b00(const Elem_10004b00& o) : value(o.value) {}
    // src: GUESS (confidence: low)
    int value;
};

// src: GUESS 0x10004b00 (confidence: medium)
Elem_10004b00* __stdcall UninitFillNDwords_10004b00(Elem_10004b00* dest, unsigned int count, const Elem_10004b00& val) {
    unsigned int n = count;
    Elem_10004b00* p = dest;
    for (; n > 0; --n, ++p) {
        new ((void*)p) Elem_10004b00(val);
    }
    return dest + count;
}
