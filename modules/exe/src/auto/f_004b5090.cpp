// c5d-cflags: -/arch:SSE2
// src: GUESS (confidence: low) [0x004b5090]
struct Guid16_004b5090 {
    int a, b, c, d;
};

// src: GUESS (confidence: low) [0x004b5090]
extern const Guid16_004b5090 g_guid_004b5090;

// src: GUESS (confidence: low) [0x004b5090]
struct Obj_004b5090 {
    struct Vtbl {
        int (__stdcall *fn0)(Obj_004b5090*, Guid16_004b5090);
    };
    Vtbl* vtbl;
};

// src: GUESS (confidence: low) [0x004b5090]
int __stdcall CallWithGuid_004b5090(Obj_004b5090* p) {
    return p->vtbl->fn0(p, g_guid_004b5090);
}
