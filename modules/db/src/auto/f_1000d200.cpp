#include <new>

// src: GUESS (confidence: low)
struct Elem_1000d200 {
    // src: GUESS (confidence: low)
    Elem_1000d200(const Elem_1000d200& o) : value(o.value) {}
    // src: GUESS (confidence: low)
    int value;
};

// src: GUESS 0x1000d200 (confidence: medium)
Elem_1000d200* __stdcall UninitFillNDwords_1000d200(Elem_1000d200* dest, unsigned int count, const Elem_1000d200& val) {
    unsigned int n = count;
    Elem_1000d200* p = dest;
    for (; n > 0; --n, ++p) {
        new ((void*)p) Elem_1000d200(val);
    }
    return dest + count;
}
