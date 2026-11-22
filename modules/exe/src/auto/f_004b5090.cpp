// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x004b5090]
struct Guid16_4b5090 {
    unsigned int a, b, c, d;
};

struct Iface4b5090 {
    virtual int __stdcall m0(Guid16_4b5090 g) = 0;
};

extern Guid16_4b5090 g_guid_4b5090;

int __stdcall f_004b5090(Iface4b5090* p) {
    return p->m0(g_guid_4b5090);
}
