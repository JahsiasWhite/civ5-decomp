// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x006c6ba0]
struct Elem_006c6ba0 {
    int a, b, c, d;
};

// src: LIB (confidence: high) [0x006c6ba0]
void __stdcall reverse_006c6ba0(Elem_006c6ba0* first, Elem_006c6ba0* last) {
    for (; first != last && first != --last; ++first) {
        Elem_006c6ba0 tmp = *first;
        *first = *last;
        *last = tmp;
    }
}
