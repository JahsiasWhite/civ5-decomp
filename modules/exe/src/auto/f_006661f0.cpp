// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x006661f0]
struct Guid16_6661f0 {
    unsigned int a, b, c, d;
};

struct Iface6661f0 {
    virtual int __stdcall m0(Guid16_6661f0 g) = 0;
};

extern Guid16_6661f0 g_guid_6661f0;

int __stdcall f_006661f0(Iface6661f0* p) {
    return p->m0(g_guid_6661f0);
}
