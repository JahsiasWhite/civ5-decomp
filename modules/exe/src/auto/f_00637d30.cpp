// c5d-cflags: -/arch:SSE2
#include <new>

// src: GUESS (confidence: low) [0x00637d30]
struct Item16_00637d30 {
    float a, b, c;
    int d;
    Item16_00637d30(const Item16_00637d30& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};

// src: GUESS (confidence: low) [0x00637d30]
Item16_00637d30* __cdecl CopyRange_00637d30(const Item16_00637d30* first, const Item16_00637d30* last, Item16_00637d30* dest) {
    for (; first != last; ++first, ++dest) {
        if (dest) {
            new (dest) Item16_00637d30(*first);
        }
    }
    return dest;
}
