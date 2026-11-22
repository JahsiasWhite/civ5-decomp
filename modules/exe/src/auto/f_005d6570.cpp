// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x005d6570]
struct Guid16_5d6570 {
    unsigned int a, b, c, d;
};

struct Iface5d6570 {
    virtual int __stdcall m0(Guid16_5d6570 g) = 0;
};

extern Guid16_5d6570 g_guid_5d6570;

int __stdcall f_005d6570(Iface5d6570* p) {
    return p->m0(g_guid_5d6570);
}
