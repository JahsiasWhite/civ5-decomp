// src: GUESS (confidence: low)
#include <new>
#include <windows.h>

struct F0064e190Hdr {
    int size;
    int type;
    int f8;
    int fc;
};

struct F0064e190Payload {
    unsigned char pad0[0x98];
    float x;
    float y;
    float z;
};

struct F0064e190Buf {
    volatile LONG offset;
    unsigned char pad4[0x7c];
    unsigned char data[0x400000];
};

struct F0064e190 {
    F0064e190Buf bufs[2];
    int idx;

    F0064e190Payload* __thiscall f_0064e190();
};

F0064e190Payload* __thiscall F0064e190::f_0064e190() {
    F0064e190Buf& buf = bufs[idx & 1];
    LONG off = InterlockedExchangeAdd(&buf.offset, 0x100);
    F0064e190Hdr* hdr = new (buf.data + off) F0064e190Hdr;
    if (hdr) {
        hdr->size = 0x100;
        hdr->type = 0x32;
        hdr->f8 = 0;
        hdr->fc = 0;
    }
    F0064e190Payload* p = (F0064e190Payload*)(hdr + 1);
    if (p) {
        p->x = 0.0f;
        p->y = 0.0f;
        p->z = 0.0f;
        return p;
    }
    return 0;
}
