// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
struct Item16 {
    int a, b, c, d;
};

// src: GUESS (confidence: low)
struct Iter16 {
    const Item16* ptr;
    Iter16& operator++() { ++ptr; return *this; }
    bool operator!=(const Iter16& o) const { return ptr != o.ptr; }
};

// src: GUESS (confidence: medium)
Item16* __cdecl f_006442a0(Iter16 begin, Iter16 end, Item16* dst) {
    for (; begin != end; ++begin, ++dst) {
        if (dst) {
            *dst = *begin.ptr;
        }
    }
    return dst;
}
