// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: high) [0x006661b0]
struct Guid16_6661b0 {
    unsigned int a, b, c, d;
};

struct Iface6661b0 {
    virtual int __stdcall m0(Guid16_6661b0 g) = 0;
};

extern Guid16_6661b0 g_guid_6661b0;

int __stdcall f_006661b0(Iface6661b0* p) {
    return p->m0(g_guid_6661b0);
}
