// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low)
#include <cstring>

struct F0060a500 {
    unsigned char data[0x2008];
    float f2008;
    float f200c;
    float f2010;
    float f2014;
    float f2018;
    float f201c;

    F0060a500& __thiscall operator=(const F0060a500& o);
};

F0060a500& __thiscall F0060a500::operator=(const F0060a500& o) {
    std::memcpy(data, o.data, 0x2008);
    f2008 = o.f2008;
    f200c = o.f200c;
    f2010 = o.f2010;
    f2014 = o.f2014;
    f2018 = o.f2018;
    f201c = o.f201c;
    return *this;
}
