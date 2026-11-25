// src: GUESS (confidence: low)
#include <algorithm>

struct F005dc050Out {
    unsigned char pad0[0x1a];
    unsigned short f1a;
    unsigned short f1c;
    unsigned short f1e;
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    unsigned char pad26[0x26];
    unsigned short f4c[16];
    unsigned char pad6c[0x10];
    unsigned char f7c;
};

struct F005dc050Self {
    unsigned char pad0[0x3c];
    unsigned short f3c;
    unsigned char pad3e[2];
    unsigned short f40;
    unsigned char pad42[2];
    unsigned short f44;
    unsigned char pad46[2];
    unsigned short f48;
    unsigned char pad4a[2];
    unsigned short f4c;
    unsigned char pad4e[6];
    unsigned short f54;

    void __thiscall f_005dc050(F005dc050Out* out);
};

void __thiscall F005dc050Self::f_005dc050(F005dc050Out* out) {
    std::fill_n(out->f4c, 16, (unsigned short)2);
    out->f1a = this->f3c;
    out->f1c = this->f40;
    out->f1e = this->f44;
    out->f20 = this->f48;
    out->f22 = this->f4c;
    out->f24 = this->f54;
    out->f7c = 8;
}
